////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Copyright (C) 2017 by Lucas Brémond
///
/// This file is part of the Spacer project.
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @file                       Spacer/Core/Types/Integer.hpp
/// @author                     Lucas Brémond <lucas.bremond@gmail.com>
/// @date                       2 Dec 2017

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __Spacer_Core_Types_Integer__
#define __Spacer_Core_Types_Integer__

#include <ostream>

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

/// @brief                      Integer class

class Integer
{

    public:

        typedef int32_t         ValueType ;

                                Integer                                     ( ) = delete ;

                                Integer                                     (           Integer::ValueType          anInteger                           ) ;
                                
                                Integer                                     (           float                                                           ) = delete ;
                                Integer                                     (           double                                                          ) = delete ;

        Integer&                operator =                                  (           Integer::ValueType          anInteger                           ) ;

        bool                    operator ==                                 (   const   Integer&                    anInteger                           ) const ;
        bool                    operator !=                                 (   const   Integer&                    anInteger                           ) const ;
        bool                    operator <                                  (   const   Integer&                    anInteger                           ) const ;
        bool                    operator <=                                 (   const   Integer&                    anInteger                           ) const ;
        bool                    operator >                                  (   const   Integer&                    anInteger                           ) const ;
        bool                    operator >=                                 (   const   Integer&                    anInteger                           ) const ;

        Integer                 operator +                                  (   const   Integer&                    anInteger                           ) const ;
        Integer                 operator -                                  (   const   Integer&                    anInteger                           ) const ;
        Integer                 operator *                                  (   const   Integer&                    anInteger                           ) const ;
        Integer                 operator /                                  (   const   Integer&                    anInteger                           ) const ;
        Integer                 operator %                                  (   const   Integer&                    anInteger                           ) const ;

        Integer                 operator +                                  (   const   Integer::ValueType&         anInteger                           ) const ;
        Integer                 operator -                                  (   const   Integer::ValueType&         anInteger                           ) const ;
        Integer                 operator *                                  (   const   Integer::ValueType&         anInteger                           ) const ;
        Integer                 operator /                                  (   const   Integer::ValueType&         anInteger                           ) const ;
        Integer                 operator %                                  (   const   Integer::ValueType&         anInteger                           ) const ;

        Integer&                operator +=                                 (   const   Integer&                    anInteger                           ) ;
        Integer&                operator -=                                 (   const   Integer&                    anInteger                           ) ;
        Integer&                operator *=                                 (   const   Integer&                    anInteger                           ) ;
        Integer&                operator /=                                 (   const   Integer&                    anInteger                           ) ;
        Integer&                operator %=                                 (   const   Integer&                    anInteger                           ) ;

        Integer&                operator +=                                 (   const   Integer::ValueType&         anInteger                           ) ;
        Integer&                operator -=                                 (   const   Integer::ValueType&         anInteger                           ) ;
        Integer&                operator *=                                 (   const   Integer::ValueType&         anInteger                           ) ;
        Integer&                operator /=                                 (   const   Integer::ValueType&         anInteger                           ) ;
        Integer&                operator %=                                 (   const   Integer::ValueType&         anInteger                           ) ;

        friend Integer          operator +                                  (   const   Integer::ValueType&         anInt,
                                                                                const   Integer&                    anInteger                           ) ;
        friend Integer          operator -                                  (   const   Integer::ValueType&         anInt,
                                                                                const   Integer&                    anInteger                           ) ;
        friend Integer          operator *                                  (   const   Integer::ValueType&         anInt,
                                                                                const   Integer&                    anInteger                           ) ;
        friend Integer          operator /                                  (   const   Integer::ValueType&         anInt,
                                                                                const   Integer&                    anInteger                           ) ;
        friend Integer          operator %                                  (   const   Integer::ValueType&         anInt,
                                                                                const   Integer&                    anInteger                           ) ;

        Integer                 operator +                                  ( ) const ;
        Integer                 operator -                                  ( ) const ;
        
        Integer&                operator ++                                 ( ) ;
        Integer&                operator --                                 ( ) ;

        Integer                 operator ++                                 (           int                         anInteger                           ) ;
        Integer                 operator --                                 (           int                         anInteger                           ) ;

                                operator Integer::ValueType                 ( ) const ;

        friend std::ostream&    operator <<                                 (           std::ostream&               anOutputStream,
                                                                                const   Integer&                    anInteger                           ) ;

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

        static Integer          Undefined                                   ( ) ;

        static Integer          Zero                                        ( ) ;

        static Integer          PositiveInfinity                            ( ) ;

        static Integer          NegativeInfinity                            ( ) ;

        static Integer          String                                      (   const   types::String&              aString                             ) ;

        static Integer          Object                                      (   const   ctnr::Object&               anObject                            ) ;

    private:

        enum class Type
        {
            
            Undefined,
            Defined,
            PositiveInfinity,
            NegativeInfinity

        } ;

        Integer::Type           type_ ;
        Integer::ValueType      value_ ;

                                Integer                                     (   const   Integer::Type&              aType,
                                                                                const   Integer::ValueType&         anInteger                           ) ;

} ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////