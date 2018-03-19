////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Copyright (C) 2018 by Lucas Brémond
///
/// This file is part of the Spacer project.
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @file                       Spacer/Core/Logger/Sources/Source.hpp
/// @author                     Lucas Brémond <lucas.bremond@gmail.com>
/// @date                       20 Dec 2017

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __Spacer_Core_Logger_Sources_Source__
#define __Spacer_Core_Logger_Sources_Source__

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Spacer/Core/Types/Unique.hpp>
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
namespace sources
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

using spacer::core::types::Unique ;
using spacer::core::types::String ;
using spacer::core::ctnr::Array ;
using spacer::core::logger::Severity ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief                      Log source base

class Source
{

    friend class Pump ;

    public:

                                Source                                      (   const   String&                     aChannel                            ) ;
                                
                                Source                                      (   const   Source&                     aSource                             ) ;

                                ~Source                                     ( ) ;

        virtual Source*         clone                                       ( ) const ;

        Source&                 operator =                                  (   const   Source&                     aSource                             ) = default ;

        void*                   accessLogger                                ( ) ;

    private:

        class Impl ;

        Unique<Source::Impl>    implPtr_ ;

} ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////