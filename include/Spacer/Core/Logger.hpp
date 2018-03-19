////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Copyright (C) 2018 by Lucas Brémond
///
/// This file is part of the Spacer project.
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @file                       Spacer/Core/Logger.hpp
/// @author                     Lucas Brémond <lucas.bremond@gmail.com>
/// @date                       20 Dec 2017

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __Spacer_Core_Logger__
#define __Spacer_Core_Logger__

#include <Spacer/Core/Types/Integer.hpp>
#include <Spacer/Core/Types/String.hpp>
#include <Spacer/Core/Containers/Array.hpp>
#include <Spacer/Core/Logger/Severity.hpp>
#include <Spacer/Core/Logger/Source.hpp>
#include <Spacer/Core/Logger/Sink.hpp>
#include <Spacer/Core/Logger/Pump.hpp>

#include <boost/log/attributes.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace spacer
{
namespace core
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

using spacer::core::types::Unique ;
using spacer::core::types::Integer ;
using spacer::core::types::String ;
using spacer::core::ctnr::Array ;
using spacer::core::logger::Severity ;
using spacer::core::logger::Source ;
using spacer::core::logger::Sink ;
using spacer::core::logger::Pump ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief                      Log management

class Logger
{

    public:

                                Logger                                      (   const   String&                     aChannel                            ) ;

        Pump                    operator ()                                 (   const   Severity&                   aSeverity,
                                                                                const   Integer&                    aLine,
                                                                                const   String&                     aFile,
                                                                                const   String&                     aFunction                           ) ;

        template <class T>
        Pump                    operator <<                                    (    const    T&                            anObject                            )
        {

            Pump pump(Severity::Info, Integer::Undefined(), String::Empty(), String::Empty(), &source_) ;

            pump << anObject ;
            
            return std::move(pump) ;

        }

        String                  getChannel                                  ( ) const ;

        static Logger           Console                                     (   const   Severity&                   aSeverity                           ) ;
        
        static Logger           Console                                     (   const   String&                     aChannel,
                                                                                const   Severity&                   aSeverity                           ) ;

        static Logger&          Global                                      ( ) ;

    private:

        String                  channel_ ;
        Source                  source_ ;
        Array<Sink>             sinks_ ;
        
} ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define                         LOG(aLogger, aSeverity)                         aLogger(aSeverity, __LINE__, __FILE__, __PRETTY_FUNCTION__)

#define                         LOG_TRACE(aLogger)                              LOG(aLogger, spacer::core::logger::Severity::Trace)
#define                         LOG_DEBUG(aLogger)                              LOG(aLogger, spacer::core::logger::Severity::Debug)
#define                         LOG_INFO(aLogger)                               LOG(aLogger, spacer::core::logger::Severity::Info)
#define                         LOG_WARNING(aLogger)                            LOG(aLogger, spacer::core::logger::Severity::Warning)
#define                         LOG_ERROR(aLogger)                              LOG(aLogger, spacer::core::logger::Severity::Error)
#define                         LOG_FATAL(aLogger)                              LOG(aLogger, spacer::core::logger::Severity::Fatal)

#define                         GLOBAL_LOG_TRACE                                LOG_TRACE(spacer::core::Logger::Global())
#define                         GLOBAL_LOG_DEBUG                                LOG_DEBUG(spacer::core::Logger::Global())
#define                         GLOBAL_LOG_INFO                                 LOG_INFO(spacer::core::Logger::Global())
#define                         GLOBAL_LOG_WARNING                              LOG_WARNING(spacer::core::Logger::Global())
#define                         GLOBAL_LOG_ERROR                                LOG_ERROR(spacer::core::Logger::Global())
#define                         GLOBAL_LOG_FATAL                                LOG_FATAL(spacer::core::Logger::Global())

#define                         GET_MACRO(_0, _1, _2, NAME, ...)                NAME

#define                         LOG_SCOPE0()                                    BOOST_LOG_NAMED_SCOPE("?")
#define                         LOG_SCOPE1(aScope)                              BOOST_LOG_NAMED_SCOPE(aScope)
#define                         LOG_SCOPE2(aClass, aMethod)                     BOOST_LOG_NAMED_SCOPE(aClass " :: " aMethod)

#define                         LOG_SCOPE(...)                                  GET_MACRO(_0, ##__VA_ARGS__, LOG_SCOPE2, LOG_SCOPE1, LOG_SCOPE0)(__VA_ARGS__)

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////