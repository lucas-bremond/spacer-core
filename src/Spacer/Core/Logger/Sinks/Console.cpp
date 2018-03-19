////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Copyright (C) 2018 by Lucas Brémond
///
/// This file is part of the Spacer project.
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @file                       Spacer/Core/Logger/Sinks/Console.cpp
/// @author                     Lucas Brémond <lucas.bremond@gmail.com>
/// @date                       20 Dec 2017

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Spacer/Core/Logger/Sinks/Console.hpp>

#include <boost/log/attributes/named_scope.hpp>
#include <boost/log/attributes/mutable_constant.hpp>
#include <boost/log/attributes/current_thread_id.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/expressions/formatters/date_time.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/log/support/exception.hpp>
#include <boost/log/sinks/sync_frontend.hpp>
#include <boost/log/sinks/text_ostream_backend.hpp>
#include <boost/log/core.hpp>

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/phoenix/bind.hpp>
#include <boost/core/null_deleter.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace spacer
{
namespace core
{
namespace logger
{
namespace sinks
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace logging = boost::log ;
namespace sinks = boost::log::sinks ;
namespace attrs = boost::log::attributes ;
namespace keywords = boost::log::keywords ;
namespace expr = boost::log::expressions ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_LOG_ATTRIBUTE_KEYWORD(line_id, "LineID", unsigned int )
BOOST_LOG_ATTRIBUTE_KEYWORD(channel, "Channel", String)
BOOST_LOG_ATTRIBUTE_KEYWORD(timestamp, "TimeStamp", boost::posix_time::ptime )
BOOST_LOG_ATTRIBUTE_KEYWORD(thread_id, "ThreadID", attrs::current_thread_id::value_type)
BOOST_LOG_ATTRIBUTE_KEYWORD(severity, "Severity", Severity)

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct ConsoleSeverityTag ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Console::Impl
{

    public:

                                Impl                                        (   const   Console*                    aConsolePtr                         ) ;

                                Impl                                        (   const   Impl&                       aConsole                            ) = delete ;

                                Impl                                        (           Impl&&                      aConsole                            ) ;

                                ~Impl                                       ( ) ;

        Impl&                   operator =                                  (   const   Impl&                       aConsole                            ) = delete ;

        friend logging::formatting_ostream& operator <<                     (           logging::formatting_ostream& aFormattingStream,
                                                                                const   logging::to_log_manip<Severity, ConsoleSeverityTag>& aManip     ) ;

        void                    enable                                      ( ) ;
        void                    disable                                     ( ) ;

        void                    associateConsoleSink                        (   const   Console*                    aConsolePtr                         ) ;

    private:

        const Console*            consolePtr_ ;

        boost::shared_ptr<sinks::synchronous_sink<sinks::text_ostream_backend>> sinkPtr_ ;
        boost::shared_ptr<boost::log::sinks::text_ostream_backend> backendPtr_ ;
        boost::shared_ptr<std::ostream> backendStreamPtr_ ;

        bool                    getFilter                                   (   const   logging::value_ref<Severity, tag::severity>& aSeverity,
                                                                                const   logging::value_ref<String, tag::channel>& aChannel              ) ;

} ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                Console::Impl::Impl                         (   const   Console*                    aConsolePtr                         )
                                :    consolePtr_(aConsolePtr),
                                    sinkPtr_(nullptr),
                                    backendPtr_(nullptr),
                                    backendStreamPtr_(nullptr)
{

}

                                Console::Impl::Impl                         (           Console::Impl&&             aConsole                            )
                                :   consolePtr_(std::move(aConsole.consolePtr_)),
                                    sinkPtr_(std::move(aConsole.sinkPtr_)),
                                    backendPtr_(std::move(aConsole.backendPtr_)),
                                    backendStreamPtr_(std::move(aConsole.backendStreamPtr_))
{
    
}

                                Console::Impl::~Impl                        ( )
{
    
    if (consolePtr_->isEnabled())
    {
        this->disable() ;
    }

}

logging::formatting_ostream&    operator <<                                 (           logging::formatting_ostream& aFormattingStream,
                                                                                const   logging::to_log_manip<Severity, ConsoleSeverityTag>& aManip     )
{

    switch (aManip.get())
    {

        case Severity::Trace:
            aFormattingStream << "[" + Console::ColorizeMessage("TRACE", Console::Color::DarkGray) + "]" ;
            break ;

        case Severity::Debug:
            aFormattingStream << "[" + Console::ColorizeMessage("DEBUG", Console::Color::LightGray) + "]" ;
            break ;

        case Severity::Info:
            aFormattingStream << "[" + Console::ColorizeMessage("INFO", Console::Color::LightBlue) + "]" ;
            break ;

        case Severity::Warning:
            aFormattingStream << "[" + Console::ColorizeMessage("WARNING", Console::Color::Yellow) + "]" ;
            break ;

        case Severity::Error:
            aFormattingStream << "[" + Console::ColorizeMessage("ERROR", Console::Color::Red) + "]" ;
            break ;

        case Severity::Fatal:
            aFormattingStream << "[" + Console::ColorizeMessage("FATAL", Console::Color::LightMagenta) + "]" ;
            break ;

        default:
            aFormattingStream << "[" + Console::ColorizeMessage("????", Console::Color::LightCyan) + "]" ;
            break ;

    }

    return aFormattingStream ;

}

void                            Console::Impl::enable                       ( )
{

    backendPtr_ = boost::make_shared<sinks::text_ostream_backend>() ;
    
    backendPtr_->auto_flush(true) ;

    backendStreamPtr_ = boost::shared_ptr<std::ostream>(&std::clog, boost::null_deleter()) ;
    
    backendPtr_->add_stream(backendStreamPtr_) ;

    logging::core::get()->add_global_attribute("ThreadID", attrs::current_thread_id()) ;

    sinkPtr_ = boost::make_shared<sinks::synchronous_sink<sinks::text_ostream_backend>>(backendPtr_) ;

    logging::formatter formatter = expr::stream
    <<  expr::if_(boost::phoenix::cref(consolePtr_->lineIdEnabled_))
    [
        expr::stream << std::right << std::setw(7) << std::setfill('.') << line_id << std::setfill(' ') << " | "
    ]
    <<  expr::if_(boost::phoenix::cref(consolePtr_->severityEnabled_))
    [
        expr::stream << std::left << std::setw(18) << std::setfill(' ') << expr::attr<Severity, ConsoleSeverityTag>("Severity") << " | "
    ]
    <<  expr::if_(boost::phoenix::cref(consolePtr_->timestampEnabled_))
    [
        expr::stream << expr::format_date_time(timestamp, "%Y-%m-%d %H:%M:%S.%f") << " | "
    ]
    <<  expr::if_(boost::phoenix::cref(consolePtr_->threadEnabled_))
    [
        expr::stream << thread_id << " | "
    ]
    <<  expr::if_(boost::phoenix::cref(consolePtr_->fileEnabled_))
    [
        expr::stream << expr::if_((expr::attr<std::string>("File") != ""))
        [
            expr::stream
            <<  "["
            <<  expr::attr<std::string>("File")
            <<  expr::if_(boost::phoenix::cref(consolePtr_->lineEnabled_))
            [
                expr::stream << expr::if_(expr::attr<int>("Line") > 0)
                [
                    expr::stream << ":" << expr::attr<int>("Line")
                ]
            ]
            <<  "] "
        ]
    ]
    <<  expr::if_(boost::phoenix::cref(consolePtr_->functionEnabled_))
    [
        expr::stream << expr::if_(expr::attr<std::string>("Function") != "")
        [
            expr::stream << "@ " << expr::attr<std::string>("Function") << " "
        ]
    ]
    <<  expr::if_(boost::phoenix::cref(consolePtr_->scopeEnabled_))
    [
        expr::stream << expr::format_named_scope("Scope", keywords::format = "%n :: ", keywords::delimiter = "") // keywords::depth = 2
    ]
    <<  expr::if_(boost::phoenix::cref(consolePtr_->channelEnabled_))
    [
        expr::stream << expr::if_(expr::attr<String>("Channel") != "Global")
        [
            expr::stream << "#" << expr::attr<String>("Channel") << ": "
        ]
    ]
    <<  expr::smessage ;

    sinkPtr_->set_formatter(formatter) ;

    sinkPtr_->set_filter(boost::phoenix::bind(&Console::Impl::getFilter, this, severity.or_none(), channel.or_none())) ;

    logging::core::get()->add_sink(sinkPtr_) ;

}

void                            Console::Impl::disable                      ( )
{

    if (backendPtr_ != nullptr)
    {

        backendPtr_->remove_stream(backendStreamPtr_) ;

        logging::core::get()->remove_sink(sinkPtr_) ;

    }

}

void                            Console::Impl::associateConsoleSink         (   const   Console*                    aConsolePtr                         )
{
    consolePtr_ = aConsolePtr ;
}

bool                            Console::Impl::getFilter                   (    const   logging::value_ref<Severity, tag::severity>& aSeverity,
                                                                                const   logging::value_ref<String, tag::channel>& aChannel              )
{
    
    if (!aSeverity)
    {
        return true ;
    }

    if (!aChannel)
    {
        return true ;
    }

    if (aSeverity >= consolePtr_->severity_)
    {

        if (consolePtr_->channels_.isEmpty())
        {
            return true ;
        }

        for (const auto& channelName : consolePtr_->channels_)
        {
            
            if (aChannel == channelName)
            {
                return true ;
            }

        }

    }
    
    return false ;
    
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                Console::Console                            (   const   Severity&                   aSeverity                           )
                                :   Sink(aSeverity),
                                    implUPtr_(std::make_unique<Console::Impl>(this))
{

}

                                Console::Console                            (   const   Console&                    aConsole                            )
                                :   Sink(aConsole),
                                    implUPtr_(std::make_unique<Console::Impl>(this))
{

}


                                Console::~Console                           ( )
{

}


Console*                        Console::clone                              ( ) const

{
    return new Console(*this) ;
}

void                            Console::enable                             ( )
{

    if (!enabled_)
    {

        implUPtr_->enable() ;

        enabled_ = true ;

    }

}

void                            Console::disable                            ( )
{

    if (enabled_)
    {

        implUPtr_->disable() ;

        enabled_ = false ;

    }

}

String                          Console::ColorizeMessage                    (   const   String&                     aMessage,
                                                                                const   Console::Color&             aColor                              )
{

    // http://misc.flogisoft.com/bash/tip_colors_and_formatting

    switch (aColor)
    {

        case Console::Color::Black:
            return "\x1B[30m" + aMessage + "\x1B[0m" ;

        case Console::Color::Red:
            return "\x1B[31m" + aMessage + "\x1B[0m" ;

        case Console::Color::Green:
            return "\x1B[32m" + aMessage + "\x1B[0m" ;

        case Console::Color::Yellow:
            return "\x1B[33m" + aMessage + "\x1B[0m" ;

        case Console::Color::Blue:
            return "\x1B[34m" + aMessage + "\x1B[0m" ;

        case Console::Color::Magenta:
            return "\x1B[35m" + aMessage + "\x1B[0m" ;

        case Console::Color::Cyan:
            return "\x1B[36m" + aMessage + "\x1B[0m" ;

        case Console::Color::LightGray:
            return "\x1B[37m" + aMessage + "\x1B[0m" ;

        case Console::Color::DarkGray:
            return "\x1B[90m" + aMessage + "\x1B[0m" ;

        case Console::Color::LightRed:
            return "\x1B[91m" + aMessage + "\x1B[0m" ;

        case Console::Color::LightGreen:
            return "\x1B[92m" + aMessage + "\x1B[0m" ;

        case Console::Color::LightYellow:
            return "\x1B[93m" + aMessage + "\x1B[0m" ;

        case Console::Color::LightBlue:
            return "\x1B[94m" + aMessage + "\x1B[0m" ;

        case Console::Color::LightMagenta:
            return "\x1B[95m" + aMessage + "\x1B[0m" ;

        case Console::Color::LightCyan:
            return "\x1B[96m" + aMessage + "\x1B[0m" ;

        case Console::Color::White:
            return "\x1B[97m" + aMessage + "\x1B[0m" ;

    }

    return aMessage ;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////