////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Copyright (C) 2018 by Lucas Brémond
///
/// This file is part of the Spacer project.
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @file                       Spacer/Core/Logger.cpp
/// @author                     Lucas Brémond <lucas.bremond@gmail.com>
/// @date                       20 Dec 2017

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Spacer/Core/Logger.hpp>

#include <mutex>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace spacer
{
namespace core
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static std::mutex GlobalMutex ;
static Logger* GlobalLoggerPtr = nullptr ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                Logger::Logger                              (   const   String&                     aChannel                            )
                                :   channel_(aChannel),
                                    source_(Source::Undefined()),
                                    sinks_(Array<Sink>::Empty())
{

}

Pump                            Logger::operator ()                         (   const   Severity&                   aSeverity,
                                                                                const   Integer&                    aLine,
                                                                                const   String&                     aFile,
                                                                                const   String&                     aFunction                           )
{
    return {aSeverity, aLine, aFile, aFunction, &source_} ;
}

String                          Logger::getChannel                          ( ) const
{
    return channel_ ;
}

Logger                          Logger::Console                             (   const   Severity&                   aSeverity                           )
{
    return Logger::Console("Console", aSeverity) ;   
}

Logger                          Logger::Console                             (   const   String&                     aChannel,
                                                                                const   Severity&                   aSeverity                           )
{

    Logger logger(aChannel) ;

    logger.source_ = Source(aChannel) ;
    
    logger.sinks_.add(Sink::Console(aSeverity)) ;

    logger.sinks_.accessFirst().addChannel(aChannel) ;
    
    logger.sinks_.accessFirst().enable() ;

    return logger ;

}

Logger&                         Logger::Global                              ( )
{

    if (GlobalLoggerPtr == nullptr)
    {

        std::lock_guard<std::mutex> lock(GlobalMutex) ;

        if (GlobalLoggerPtr == nullptr)
        {
            GlobalLoggerPtr = new Logger(Logger::Console("Global", Severity::Info)) ;
        }

    }

    return (*GlobalLoggerPtr) ;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////