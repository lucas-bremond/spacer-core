////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Copyright (C) 2017 by Lucas Brémond
///
/// This file is part of the Spacer project.
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @file                       Spacer/Core/Logger/Sources/Source.cpp
/// @author                     Lucas Brémond <lucas.bremond@gmail.com>
/// @date                       20 Dec 2017

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Spacer/Core/Logger/Sources/Source.hpp>
#include <Spacer/Core/Logger/Severity.hpp>

#include <boost/log/sources/severity_channel_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/attributes/named_scope.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/utility/manipulators/add_value.hpp>

#include <iostream>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace spacer
{
namespace core
{
namespace logger
{
namespace sources
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace logging = boost::log ;
namespace src = boost::log::sources ;
namespace attrs = boost::log::attributes ;
namespace keywords = boost::log::keywords ;

using spacer::core::logger::Severity ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Source::Impl
{

    public:

        typedef src::severity_channel_logger_mt<Severity, String> SeverityChannelLogger ;

                                Impl                                        (   const   Source*                     aSourcePtr,
                                                                                const   String&                     aChannel                            ) ;

                                Impl                                        (   const   Impl&                       aSource                             ) = delete ;

                                Impl                                        (           Impl&&                      aSource                             ) ;

                                ~Impl                                       ( ) ;

        Impl&                   operator =                                  (   const   Impl&                       aSource                             ) = delete ;

        String                  getChannel                                  ( ) const ;

        void                    setChannel                                  (   const   String&                     aChannel                            ) ;

        void                    log                                         (   const   Severity&                   aSeverity,
                                                                                const   String&                     aMessage                            ) ;

    Source::Impl::SeverityChannelLogger& accessLogger                       ( ) ;

    private:

        const Source*           sourcePtr_ ;

        String                  channel_ ;

        Source::Impl::SeverityChannelLogger logger_ ;

        void                    initialize                                  ( ) ;

} ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                Source::Impl::Impl                          (   const   Source*                     aSourcePtr,
                                                                                const   String&                     aChannel                            )
                                :   sourcePtr_(aSourcePtr),
                                    channel_(aChannel)
{
    
    this->initialize() ;

}

                                Source::Impl::Impl                          (           Impl&&                      aSource                               )
                                :   sourcePtr_(std::move(aSource.sourcePtr_)),
                                    channel_(std::move(aSource.channel_)),
                                    logger_(std::move(aSource.logger_))
{
    
}

                                Source::Impl::~Impl                         ( )
{
    
}

String                          Source::Impl::getChannel                    ( ) const
{
    return channel_ ;
}

void                            Source::Impl::setChannel                    (   const   String&                     aChannel                            )
{

    if (aChannel.isEmpty())
    {
        throw spacer::core::error::runtime::Undefined("Channel") ;
    }

    channel_ = aChannel ;

    this->initialize() ;

}

Source::Impl::SeverityChannelLogger& Source::Impl::accessLogger ( )
{
    return logger_ ;
}

void                            Source::Impl::initialize                    ( )
{

    if (!channel_.isEmpty())
    {
        
        logger_ = Source::Impl::SeverityChannelLogger(keywords::channel = channel_) ;

        logger_.add_attribute("LineID", logging::attributes::counter<unsigned int>(1)) ;
        logger_.add_attribute("TimeStamp", logging::attributes::local_clock()) ;
        logger_.add_attribute("Scope", attrs::named_scope()) ;

    }

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                Source::Source                              (   const   String&                     aChannel                            )
                                :    implPtr_(std::make_unique<Source::Impl>(this, aChannel))
{

}

                                Source::Source                              (   const   Source&                     aSource                             )
                                :    implPtr_((aSource.implPtr_ != nullptr) ? std::make_unique<Source::Impl>(this, aSource.implPtr_->getChannel()) : nullptr)
{

}

                                Source::~Source                             ( )
{

}

Source*                         Source::clone                               ( ) const
{
    return new Source(*this) ;
}

void*                           Source::accessLogger                        ( )
{
    return &implPtr_->accessLogger() ;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////