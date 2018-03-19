////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Copyright (C) 2018 by Lucas Brémond
///
/// This file is part of the Spacer project.
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @file                       Spacer/Core/Types/Weak.hpp
/// @author                     Lucas Brémond <lucas.bremond@gmail.com>
/// @date                       2 Dec 2017

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __Spacer_Core_Types_Weak__
#define __Spacer_Core_Types_Weak__

#include <memory>
#include <functional>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace spacer
{
namespace core
{
namespace types
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T> using Weak = std::weak_ptr<T> ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////