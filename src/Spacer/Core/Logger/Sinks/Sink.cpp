////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Copyright (C) 2018 by Lucas Brémond
///
/// This file is part of the Spacer project.
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @file                       Spacer/Core/Logger/Sinks/Sink.cpp
/// @author                     Lucas Brémond <lucas.bremond@gmail.com>
/// @date                       20 Dec 2017

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Spacer/Core/Logger/Sinks/Sink.hpp>

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

                                Sink::Sink                                  (   const   Severity&                   aSeverity                           )
                                :   enabled_(false),
                                    severity_(aSeverity),
                                    lineIdEnabled_(true),
                                    severityEnabled_(true),
                                    timestampEnabled_(true),
                                    threadEnabled_(true),
                                    scopeEnabled_(true),
                                    fileEnabled_(true),
                                    lineEnabled_(true),
                                    functionEnabled_(true),
                                    channelEnabled_(true),
                                    channels_(Array<String>::Empty())
{

}

                                Sink::~Sink                                 ( )
{

}

bool                            Sink::isEnabled                             ( ) const
{
    return enabled_ ;
}

bool                            Sink::isLineIdLogged                        ( ) const
{
    return lineIdEnabled_ ;
}

bool                            Sink::isSeverityLogged                      ( ) const
{
    return severityEnabled_ ;
}

bool                            Sink::isTimestampLogged                     ( ) const
{
    return timestampEnabled_ ;
}

bool                            Sink::isThreadLogged                        ( ) const
{
    return threadEnabled_ ;
}

bool                            Sink::isScopeLogged                         ( ) const
{
    return scopeEnabled_ ;
}

bool                            Sink::isFileLogged                          ( ) const
{
    return fileEnabled_ ;
}

bool                            Sink::isLineLogged                          ( ) const
{
    return lineEnabled_ ;
}

bool                            Sink::isFunctionLogged                      ( ) const
{
    return functionEnabled_ ;
}

bool                            Sink::isChannelLogged                       ( ) const
{
    return channelEnabled_ ;
}

void                            Sink::addChannel                            (   const   String&                     aChannel                            )
{
    channels_.add(aChannel) ;
}

void                            Sink::removeChannel                         (   const   String&                     aChannel                            )
{
    channels_.remove(aChannel) ;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////