////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Copyright (C) 2018 by Lucas Brémond
///
/// This file is part of the Spacer project.
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @file                       Spacer/Core/Containers/Triple.tpp
/// @author                     Lucas Brémond <lucas.bremond@gmail.com>
/// @date                       2 Dec 2017

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace spacer
{
namespace core
{
namespace ctnr
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T, typename U, typename V>
Triple<T,U,V>                   make_triple                                (    const   T&                          aFirstElement,
                                                                                const   U&                          aSecondElement,
                                                                                const   V&                          aThirdElement                       )
{

    Triple<T,U,V> triple ;

    triple.first = aFirstElement ;
    triple.second = aSecondElement ;
    triple.third = aThirdElement ;

    return triple ;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////