////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Copyright (C) 2018 by Lucas Brémond
///
/// This file is part of the Spacer project.
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @file                       Spacer/Core/Types/String.hpp
/// @author                     Lucas Brémond <lucas.bremond@gmail.com>
/// @date                       2 Dec 2017

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __Spacer_Core_Types_String__
#define __Spacer_Core_Types_String__

#include <ostream>
#include <string>

#include <Spacer/Core/Types/Size.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace spacer
{
namespace core
{
namespace types
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

using spacer::core::types::Size ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief                      A string class

class String : public std::string
{

    public:

        using std::string::string ;

                                String                                      ( ) ;

                                String                                      (   const   std::string&                aString                             ) ;

                                ~String                                     ( ) ;

        bool                    isEmpty                                     ( ) const ;

        bool                    isUppercase                                 ( ) const ;

        bool                    isLowercase                                 ( ) const ;

        Size                    getLength                                   ( ) const ;

        static String           Empty                                       ( ) ;

} ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////