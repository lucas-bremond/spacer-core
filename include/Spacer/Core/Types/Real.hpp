////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Copyright (C) 2018 by Lucas Brémond
///
/// This file is part of the Spacer project.
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @file                       Spacer/Core/Types/Real.hpp
/// @author                     Lucas Brémond <lucas.bremond@gmail.com>
/// @date                       2 Dec 2017

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __Spacer_Core_Types_Real__
#define __Spacer_Core_Types_Real__

#include <Spacer/Core/Types/Sign.hpp>
#include <Spacer/Core/Types/String.hpp>
#include <Spacer/Core/Containers/Object.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace spacer
{
namespace core
{
namespace types
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace ctnr = spacer::core::ctnr ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief                      A real class

class Real
{

    public:

        typedef double          ValueType ;

                                Real                                        ( ) = delete ;

                                Real                                        (           Real::ValueType             aReal                               ) ;

        Real&                   operator =                                  (           Real::ValueType             aReal                               ) ;

        bool                    operator ==                                 (   const   Real&                       aReal                               ) const ;
        bool                    operator !=                                 (   const   Real&                       aReal                               ) const ;
        bool                    operator <                                  (   const   Real&                       aReal                               ) const ;
        bool                    operator <=                                 (   const   Real&                       aReal                               ) const ;
        bool                    operator >                                  (   const   Real&                       aReal                               ) const ;
        bool                    operator >=                                 (   const   Real&                       aReal                               ) const ;

        bool                    operator ==                                 (   const   Real::ValueType&            aReal                               ) const ;
        bool                    operator !=                                 (   const   Real::ValueType&            aReal                               ) const ;
        bool                    operator <                                  (   const   Real::ValueType&            aReal                               ) const ;
        bool                    operator <=                                 (   const   Real::ValueType&            aReal                               ) const ;
        bool                    operator >                                  (   const   Real::ValueType&            aReal                               ) const ;
        bool                    operator >=                                 (   const   Real::ValueType&            aReal                               ) const ;

        Real                    operator +                                  (   const   Real&                       aReal                               ) const ;
        Real                    operator -                                  (   const   Real&                       aReal                               ) const ;
        Real                    operator *                                  (   const   Real&                       aReal                               ) const ;
        Real                    operator /                                  (   const   Real&                       aReal                               ) const ;

        Real                    operator +                                  (   const   Real::ValueType&            aReal                               ) const ;
        Real                    operator -                                  (   const   Real::ValueType&            aReal                               ) const ;
        Real                    operator *                                  (   const   Real::ValueType&            aReal                               ) const ;
        Real                    operator /                                  (   const   Real::ValueType&            aReal                               ) const ;

        Real&                   operator +=                                 (   const   Real&                       aReal                               ) ;
        Real&                   operator -=                                 (   const   Real&                       aReal                               ) ;
        Real&                   operator *=                                 (   const   Real&                       aReal                               ) ;
        Real&                   operator /=                                 (   const   Real&                       aReal                               ) ;

        Real&                   operator +=                                 (   const   Real::ValueType&            aReal                               ) ;
        Real&                   operator -=                                 (   const   Real::ValueType&            aReal                               ) ;
        Real&                   operator *=                                 (   const   Real::ValueType&            aReal                               ) ;
        Real&                   operator /=                                 (   const   Real::ValueType&            aReal                               ) ;

        friend Real             operator +                                  (   const    Real::ValueType&           aDouble,
                                                                                const    Real&                      aReal                               ) ;
        friend Real             operator -                                  (   const    Real::ValueType&           aDouble,
                                                                                const    Real&                      aReal                               ) ;
        friend Real             operator *                                  (   const    Real::ValueType&           aDouble,
                                                                                const    Real&                      aReal                               ) ;
        friend Real             operator /                                  (   const    Real::ValueType&           aDouble,
                                                                                const    Real&                      aReal                               ) ;

        Real                    operator +                                  ( ) const ;
        Real                    operator -                                  ( ) const ;

                                operator Real::ValueType                    ( ) const ;

        friend std::ostream&    operator <<                                 (           std::ostream&               anOutputStream,
                                                                                const   Real&                       aReal                               ) ;

        bool                    isDefined                                   ( ) const ;
        bool                    isZero                                      ( ) const ;
        bool                    isPositive                                  ( ) const ;
        bool                    isNegative                                  ( ) const ;
        bool                    isStrictlyPositive                          ( ) const ;
        bool                    isStrictlyNegative                          ( ) const ;
        bool                    isInfinity                                  ( ) const ;
        bool                    isPositiveInfinity                          ( ) const ;
        bool                    isNegativeInfinity                          ( ) const ;

        types::Sign             getSign                                     ( ) const ;

        types::String           getString                                   ( ) const ;

        ctnr::Object            getObject                                   ( ) const ;

        static Real             Undefined                                   ( ) ;

        static Real             Zero                                        ( ) ;

        static Real             PositiveInfinity                            ( ) ;

        static Real             NegativeInfinity                            ( ) ;

        static Real             String                                      (   const   types::String&              aString                             ) ;

        static Real             Object                                      (   const   ctnr::Object&               anObject                            ) ;

    private:

        enum class Type
        {
            
            Undefined,
            Defined,
            PositiveInfinity,
            NegativeInfinity

        } ;

        Real::Type              type_ ;
        Real::ValueType         value_ ;

                                Real                                        (   const   Real::Type&                 aType,
                                                                                const   Real::ValueType&            aReal                               ) ;

} ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////