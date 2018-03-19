////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Copyright (C) 2018 by Lucas Brémond
///
/// This file is part of the Spacer project.
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @file                       Spacer/Core/Logger/Pump.cpp
/// @author                     Lucas Brémond <lucas.bremond@gmail.com>
/// @date                       27 Dec 2017

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Spacer/Core/Logger/Pump.hpp>

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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace logging = boost::log ;
namespace src = boost::log::sources ;
namespace attrs = boost::log::attributes ;
namespace keywords = boost::log::keywords ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Pump::Impl
{

    public:
    
                                Impl                                        (   const   Severity&                   aSeverity,
                                                                                const   Integer&                    aLine,
                                                                                const   String&                     aFile,
                                                                                const   String&                     aFunction,
                                                                                        Source*                     aSource                             ) ;

                                Impl                                        (           Pump::Impl&&                aPumpImpl                           ) ;

                                ~Impl                                       ( ) ;

        bool                    canAccessStream                             ( ) const ;

        std::ostream&           accessStream                                ( ) ;

    private:

        Source*                 sourcePtr_ ;
        logging::record         record_ ;
        logging::record_ostream* recordStreamPtr_ ;
        bool                    swap_ ;

} ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                Pump::Impl::Impl                            (   const   Severity&                   aSeverity,
                                                                                const   Integer&                    aLine,
                                                                                const   String&                     aFile,
                                                                                const   String&                     aFunction,
                                                                                        Source*                     aSource                             )
                                :   sourcePtr_(aSource),
                                    recordStreamPtr_(nullptr),
                                    swap_(false)
{

    src::severity_channel_logger_mt<Severity, String>* loggerPtr = static_cast<src::severity_channel_logger_mt<Severity, String>*>(sourcePtr_->sourceUPtr_->accessLogger()) ;

    if (record_ = loggerPtr->open_record(keywords::severity = aSeverity))
    {

        auto extractFilename =
        [ ]
        (const std::string& aPath) -> std::string
        {
            return aPath.substr(aPath.find_last_of("/\\") + 1) ;
        } ;

        recordStreamPtr_ = new logging::record_ostream(record_) ;

        if (aLine.isDefined())
        {
            (*recordStreamPtr_) << boost::log::add_value("Line", int(aLine)) ;
        }

        if (aFile != "")
        {
            (*recordStreamPtr_) << boost::log::add_value("File", extractFilename(aFile)) ;
        }
        
        if (aFunction != "")
        {
            (*recordStreamPtr_) << boost::log::add_value("Function", std::string(aFunction)) ;
        }

    }

}

                                Pump::Impl::Impl                            (           Pump::Impl&&                aPumpImpl                           )
                                :   sourcePtr_(aPumpImpl.sourcePtr_),
                                    record_(std::move(aPumpImpl.record_)),
                                    recordStreamPtr_(aPumpImpl.recordStreamPtr_),
                                    swap_(false)
{

    aPumpImpl.swap_ = true ;

}

                                Pump::Impl::~Impl                           ( )
{

    if ((!swap_) && (recordStreamPtr_ != nullptr))
    {

        recordStreamPtr_->flush() ;

        src::severity_channel_logger_mt<Severity, String>* loggerPtr = static_cast<src::severity_channel_logger_mt<Severity, String>*>(sourcePtr_->sourceUPtr_->accessLogger()) ;

        loggerPtr->push_record(boost::move(record_)) ;

        delete recordStreamPtr_ ;

    }

}

bool                            Pump::Impl::canAccessStream                 ( ) const
{
    return recordStreamPtr_ != nullptr ;
}

std::ostream&                   Pump::Impl::accessStream                    ( )
{

    if (recordStreamPtr_ == nullptr)
    {
        throw spacer::core::error::runtime::Undefined("Record") ;
    }

    return recordStreamPtr_->stream() ;
    
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                Pump::Pump                                  (   const   Severity&                   aSeverity,
                                                                                const   Integer&                    aLine,
                                                                                const   String&                     aFile,
                                                                                const   String&                     aFunction,
                                                                                        Source*                     aSource                             )
                                :   implPtr_(std::make_unique<Pump::Impl>(aSeverity, aLine, aFile, aFunction, aSource))
{

    

}

                                Pump::Pump                                  (           Pump&&                      aPump                               )
                                :   implPtr_(std::move(aPump.implPtr_))
{

}

                                Pump::~Pump                                 ( )
{

}

bool                            Pump::canAccessStream                       ( ) const
{
    return implPtr_->canAccessStream() ;
}

std::ostream&                   Pump::accessStream                          ( )
{
    return implPtr_->accessStream() ;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////