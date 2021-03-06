////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Copyright (C) 2018 by Lucas Brémond
///
/// This file is part of the Spacer project.
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @file                       Spacer/Core/Containers/Pair.hpp
/// @author                     Lucas Brémond <lucas.bremond@gmail.com>
/// @date                       11 Dec 2017

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __Spacer_Core_Containers_Pair__
#define __Spacer_Core_Containers_Pair__

#include <utility>
#include <ostream>

#include <Spacer/Core/Types/Index.hpp>
#include <Spacer/Core/Types/Size.hpp>
#include <Spacer/Core/Types/String.hpp>
#include <Spacer/Core/Containers/Object.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace spacer
{
namespace core
{
namespace ctnr
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

using spacer::core::types::Index ;
using spacer::core::types::Size ;
using spacer::core::types::String ;

using spacer::core::ctnr::Object ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief                      Pair container

template <class T, class U> using Pair = std::pair<T, U> ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////