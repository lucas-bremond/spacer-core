////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Copyright (C) 2018 by Lucas Brémond
///
/// This file is part of the Spacer project.
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @file                       Spacer/Core/Containers/Object.hpp
/// @author                     Lucas Brémond <lucas.bremond@gmail.com>
/// @date                       2 Dec 2017

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __Spacer_Core_Containers_Object__
#define __Spacer_Core_Containers_Object__

#include <ostream>

#include <Spacer/Core/Types/Unique.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace spacer
{
namespace core
{
namespace ctnr
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

using spacer::core::types::Unique ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief                      An object class

class Object
{

    public:

        enum class Type
        {

            Undefined,
            Integer,
            Real,
            String,
            Array,
            Dictionary

        } ;

                                Object                                      ( ) = delete ;

                                Object                                      (   const   Object&                     anObject                            ) ;

                                ~Object                                     ( ) ;

        Object&                 operator =                                  (   const   Object&                     anObject                            ) const ;

        friend std::ostream&    operator <<                                 (           std::ostream&               anOutputStream,
                                                                                const   Object&                     anObject                            ) ;

        bool                    isDefined                                   ( ) const ;

        bool                    isInteger                                   ( ) const ;
        bool                    isReal                                      ( ) const ;
        bool                    isString                                    ( ) const ;
        bool                    isArray                                     ( ) const ;
        bool                    isDictionary                                ( ) const ;

        Object::Type            getType                                     ( ) const ;

        static Object           Undefined                                   ( ) ;

    private:

        class Impl ;

        Unique<Object::Impl>    objectImplUPtr_ ;

} ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////