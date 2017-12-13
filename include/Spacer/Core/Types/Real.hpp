////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Copyright (C) 2017 by Lucas Brémond
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

#include <ostream>

#include <Spacer/Core/Types/String.hpp>
#include <Spacer/Core/Types/Object.hpp>

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

                                Real                                        (   const   Real::ValueType&            aReal                               ) ;

        bool                    operator ==                                 (   const   Real&                       aReal                               ) const ;
        bool                    operator !=                                 (   const   Real&                       aReal                               ) const ;
        bool                    operator <                                  (   const   Real&                       aReal                               ) const ;
        bool                    operator <=                                 (   const   Real&                       aReal                               ) const ;
        bool                    operator >                                  (   const   Real&                       aReal                               ) const ;
        bool                    operator >=                                 (   const   Real&                       aReal                               ) const ;

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

        Real&                   operator ++                                 ( ) ;
        Real&                   operator --                                 ( ) ;

        Real&                   operator ++                                 (            Real::ValueType            aDouble                             ) ;
        Real&                   operator --                                 (            Real::ValueType            aDouble                             ) ;

                                operator Real::ValueType                    ( ) const ;

                                operator const Real::ValueType&             ( ) const ;

                                operator Real::ValueType&                   ( ) ;

        friend std::ostream&    operator <<                                 (            std::ostream&              anOutputStream,
                                                                                const    Real&                      aReal                               ) ;

        bool                    isDefined                                   ( ) const ;
        bool                    isInfinite                                  ( ) const ;

        ctnr::Object            getObject                                   ( ) const ;

        static Real             Undefined                                   ( ) ;

        static Real             Infinite                                    ( ) ;

        static Real             String                                      (   const   types::String&              aString                             ) ;

        static Real             Object                                      (   const   ctnr::Object&               anObject                            ) ;

    private:

        enum class Type
        {
            
            Undefined,
            Infinite,
            Defined

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