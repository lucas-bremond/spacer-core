////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Copyright (C) 2018 by Lucas Brémond
///
/// This file is part of the Spacer project.
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @file                       Spacer/Core/Logger/Sink.cpp
/// @author                     Lucas Brémond <lucas.bremond@gmail.com>
/// @date                       20 Dec 2017

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Spacer/Core/Logger/Sink.hpp>
#include <Spacer/Core/Logger/Sinks/Console.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace spacer
{
namespace core
{
namespace logger
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                Sink::Sink                                  (   const   sinks::Sink&                aSink                               )
                                :   sinkUPtr_(aSink.clone())
{

}

                                Sink::Sink                                  (   const   Sink&                       aSink                               )
                                :   sinkUPtr_((aSink.sinkUPtr_ != nullptr) ? aSink.sinkUPtr_->clone() : nullptr)
{

}

void                            Sink::enable                                ( )
{
    sinkUPtr_->enable() ;
}

void                            Sink::disable                               ( )
{
    sinkUPtr_->disable() ;
}

void                            Sink::addChannel                            (   const   String&                     aChannel                            )
{
    sinkUPtr_->addChannel(aChannel) ;
}

void                            Sink::removeChannel                         (   const   String&                     aChannel                            )
{
    sinkUPtr_->removeChannel(aChannel) ;
}

Sink                            Sink::Console                               (   const   Severity&                   aSeverity                           )
{
    return {sinks::Console(aSeverity)} ;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////