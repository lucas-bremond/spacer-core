////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Copyright (C) 2018 by Lucas Brémond
///
/// This file is part of the Spacer project.
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @file                       Spacer/Core/Types/String.cpp
/// @author                     Lucas Brémond <lucas.bremond@gmail.com>
/// @date                       2 Dec 2017

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <boost/algorithm/string.hpp>

#include <Spacer/Core/Types/String.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace spacer
{
namespace core
{
namespace types
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                String::String                              ( )
                                :   std::string()
{

}

                                String::String                              (   const   std::string&                aString                             )
                                :   std::string(aString)
{

}

                                String::~String                             ( )
{
    
}

bool                            String::isEmpty                             ( ) const
{
    return this->empty() ;
}

bool                            String::isUppercase                         ( ) const

{
    return (!this->empty()) && !std::any_of(this->begin(), this->end(), [] (char ch) { return ::islower(ch) ; }) ;
}

bool                            String::isLowercase                         ( ) const

{
    return (!this->empty()) && !std::any_of(this->begin(), this->end(), [] (char ch) { return ::isupper(ch) ; }) ;
}

Size                            String::getLength                           ( ) const
{
    return this->length() ;
}

String                          String::Empty                               ( )

{
    return String("") ;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////