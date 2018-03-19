////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Copyright (C) 2018 by Lucas Brémond
///
/// This file is part of the Spacer project.
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @file                       Spacer/Core/Containers/Array.hpp
/// @author                     Lucas Brémond <lucas.bremond@gmail.com>
/// @date                       11 Dec 2017

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __Spacer_Core_Containers_Array__
#define __Spacer_Core_Containers_Array__

#include <vector>
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

/// @brief                      Array container

template <class T>
class Array : public std::vector<T>
{

    public:

        typedef typename std::vector<T>::const_iterator ConstIterator ;
        typedef typename std::vector<T>::iterator Iterator ;
        typedef std::function<bool(const T&)> Predicate ;

                                Array                                       (   const   std::vector<T>&             aVector                             ) ;

                                Array                                       (   const   Size&                       aSize,
                                                                                const   T&                          aValue                              =    T() ) ;

                                Array                                       (           std::initializer_list<T>    aList                               ) ;

        template <class U>
        friend std::ostream&    operator <<                                 (           std::ostream&               anOutputStream,
                                                                                const   Array<U>&                   anArray                             ) ;

        bool                    isEmpty                                     ( ) const ;
        bool                    contains                                    (   const   T&                          anElement                           ) const ;

        const T&                accessFirst                                 ( ) const ;
        const T&                accessLast                                  ( ) const ;

        Size                    getSize                                     ( ) const ;
        Index                   getIndexOf                                  (   const   T&                          anElement                           ) const ;

        types::String           getString                                   ( ) const ;
        ctnr::Object            getObject                                   ( ) const ;

        Array<const T*>         accessWhere                                 (   const   Array<T>::Predicate&        aPredicate                          ) const ;
        Array<T>                getWhere                                    (   const   Array<T>::Predicate&        aPredicate                          ) const ;

        typename Array<T>::ConstIterator find                               (   const   T&                          anElement                           ) const ;

        T&                      accessFirst                                 ( ) ;
        T&                      accessLast                                  ( ) ;

        void                    add                                         (   const   T&                          anElement                           ) ;
        void                    remove                                      (   const   T&                          anElement                           ) ;

        void                    add                                         (   const   Array<T>&                   anArray                             ) ;
        void                    remove                                      (   const   Array<T>&                   anArray                             ) ;

        void                    mergeWith                                   (   const   Array<T>&                   anArray                             ) ;

        void                    removeWhere                                 (   const   Array<T>::Predicate&        aPredicate                          ) ;

        typename Array<T>::Iterator find                                    (   const   T&                          anElement                           ) ;
        
        static Array<T>         Empty                                       ( ) ;

} ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Spacer/Core/Containers/Array.tpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////