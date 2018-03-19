////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Copyright (C) 2018 by Lucas Brémond
///
/// This file is part of the Spacer project.
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @file                       Spacer/Core/Logger/Sinks/Sink.hpp
/// @author                     Lucas Brémond <lucas.bremond@gmail.com>
/// @date                       20 Dec 2017

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __Spacer_Core_Logger_Sinks_Sink__
#define __Spacer_Core_Logger_Sinks_Sink__

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Spacer/Core/Types/String.hpp>
#include <Spacer/Core/Containers/Array.hpp>
#include <Spacer/Core/Logger/Severity.hpp>

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

using spacer::core::types::String ;
using spacer::core::ctnr::Array ;
using spacer::core::logger::Severity ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief                      Log sink base

class Sink
{

    public:

                                Sink                                        (   const   Severity&                   aSeverity                           ) ;

        virtual                 ~Sink                                       ( ) = 0 ;

        virtual Sink*           clone                                       ( ) const = 0 ;

        bool                    isEnabled                                   ( ) const ;

        bool                    isLineIdLogged                              ( ) const ;
        bool                    isSeverityLogged                            ( ) const ;
        bool                    isTimestampLogged                           ( ) const ;
        bool                    isThreadLogged                              ( ) const ;
        bool                    isScopeLogged                               ( ) const ;
        bool                    isFileLogged                                ( ) const ;
        bool                    isLineLogged                                ( ) const ;
        bool                    isFunctionLogged                            ( ) const ;
        bool                    isChannelLogged                             ( ) const ;

        virtual void            enable                                      ( ) = 0 ;
        virtual void            disable                                     ( ) = 0 ;

        void                    addChannel                                  (   const   String&                     aChannel                            ) ;
        void                    removeChannel                               (   const   String&                     aChannel                            ) ;

    protected:

        // String                  name_ ;

        bool                    enabled_ ;

        Severity                severity_ ;

        bool                    lineIdEnabled_ ;
        bool                    severityEnabled_ ;
        bool                    timestampEnabled_ ;
        bool                    threadEnabled_ ;
        bool                    scopeEnabled_ ;
        bool                    fileEnabled_ ;
        bool                    lineEnabled_ ;
        bool                    functionEnabled_ ;
        bool                    channelEnabled_ ;

        Array<String>           channels_ ;

} ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////