////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Copyright (C) 2018 by Lucas Brémond
///
/// This file is part of the Spacer project.
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @file                       Spacer/Core/Logger/Pump.hpp
/// @author                     Lucas Brémond <lucas.bremond@gmail.com>
/// @date                       27 Dec 2017

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __Spacer_Core_Logger_Pump__
#define __Spacer_Core_Logger_Pump__

#include <Spacer/Core/Types/Unique.hpp>
#include <Spacer/Core/Types/Integer.hpp>
#include <Spacer/Core/Types/String.hpp>
#include <Spacer/Core/Logger/Severity.hpp>
#include <Spacer/Core/Logger/Source.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace spacer
{
namespace core
{
namespace logger
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

using spacer::core::types::Unique ;
using spacer::core::types::Integer ;
using spacer::core::types::String ;
using spacer::core::logger::Severity ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief                      Log pump

class Pump
{

    public:

                                Pump                                        (   const   Severity&                   aSeverity,
                                                                                const   Integer&                    aLine,
                                                                                const   String&                     aFile,
                                                                                const   String&                     aFunction,
                                                                                        Source*                     aSource                             ) ;

                                Pump                                        (   const   Pump&                       aPump                               ) = delete ;

                                Pump                                        (           Pump&&                      aPump                               ) ;

                                ~Pump                                       ( ) ;

        Pump&                   operator =                                  (   const   Pump&                       aPump                               ) = delete ;

        template <class T>
        Pump&                   operator <<                                 (   const   T&                          anObject                            )
        {

            if (this->canAccessStream())
            {
                this->accessStream() << anObject ;
            }

            return (*this) ;

        }

    private:

        class Impl ;

        Unique<Pump::Impl>      implPtr_ ;

        bool                    canAccessStream                             ( ) const ;

        std::ostream&           accessStream                                ( ) ;

} ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////