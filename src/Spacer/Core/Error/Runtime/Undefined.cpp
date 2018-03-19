////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Copyright (C) 2018 by Lucas Brémond
///
/// This file is part of the Spacer project.
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @file                       Spacer/Core/Error/Runtime/Undefined.cpp
/// @author                     Lucas Brémond <lucas.bremond@gmail.com>
/// @date                       2 Dec 2017

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Spacer/Core/Error/Runtime/Undefined.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace spacer
{
namespace core
{
namespace error
{
namespace runtime
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                Undefined::Undefined                        (   const   String&                     aVariableName                       )
                                :   RuntimeError("{" + aVariableName + "} is undefined.")
{
    
}

                                Undefined::Undefined                        (   const   String&                     aScope,
                                                                                const   String&                     aVariableName                       )
                                :   RuntimeError(aScope, "{" + aVariableName + "} is undefined.")
{
    
}

                                Undefined::~Undefined                       ( )
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////