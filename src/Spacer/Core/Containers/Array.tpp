////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Copyright (C) 2018 by Lucas Brémond
///
/// This file is part of the Spacer project.
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @file                       Spacer/Core/Containers/Array.tpp
/// @author                     Lucas Brémond <lucas.bremond@gmail.com>
/// @date                       2 Dec 2017

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <algorithm>

#include <Spacer/Core/Error.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace spacer
{
namespace core
{
namespace ctnr
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                template <class T>
                                Array<T>::Array                             (   const   Size&                       aSize,
                                                                                const   T&                          anElement                           )
                                :    std::vector<T>(aSize, anElement)
{

}

                                template <class T>
                                Array<T>::Array                             (   const   std::vector<T>&             aVector                             )
                                :    std::vector<T>(aVector)
{

}

                                template <class T>
                                Array<T>::Array                             (           std::initializer_list<T>    aList                               )
                                :    std::vector<T>(aList)
{

}

                                template <class U>
std::ostream&                   operator <<                                 (           std::ostream&               anOutputStream,
                                                                                const   Array<U>&                   anArray                             )
{

    // anOutputStream                                                                 <<        "-- Array -------------------------------------------------" << std::endl ;

    // for (const auto& element : anArray)
    // {
    //     anOutputStream                                                            <<        element << std::endl ;    
    // }

    // anOutputStream                                                                 <<        "---------------------------------------------------------------" << std::endl ;

    return anOutputStream ;

}

                                template <class T>
const T&                        Array<T>::accessFirst                       ( ) const
{
    return this->front() ;
}

                                template <class T>
const T&                        Array<T>::accessLast                        ( ) const
{
    return this->back() ;
}

                                template <class T>
bool                            Array<T>::isEmpty                           ( ) const
{
    return this->empty() ;
}

                                template <class T>
bool                            Array<T>::contains                          (   const   T&                          anElement                           ) const
{
    return std::find(this->begin(), this->end(), anElement) != this->end() ;
}

                                template <class T>
Size                            Array<T>::getSize                           ( ) const
{
    return this->size() ;
}

                                template <class T>
Index                           Array<T>::getIndexOf                        (   const   T&                          anElement                           ) const
{

    typename Array<T>::const_iterator arrayIt = std::find(this->begin(), this->end(), anElement) ;

    if (arrayIt == this->end())
    {
        throw spacer::core::error::RuntimeError("Array does not contain element.") ;
    }

    return std::distance(this->begin(), arrayIt) ;

}

                                template <class T>
types::String                   Array<T>::getString                         ( ) const
{

    types::String string = "[" ;

    for (const auto& item : (*this))
    {
        
        string += item.getString() ;

        if (&item != &(this->back()))
        {
            string += ", " ;
        }

    }

    string += "]" ;

    return string ;

}

                                template <class T>
typename Array<T>::ConstIterator Array<T>::find                             (   const   T&                          anElement                           ) const
{
    return std::find(this->begin(), this->end(), anElement) ;
}

//                                 template <class T>
// Array<const T*>            Array<T>::accessWhere                            (   const   std::function<bool(const T&)>& aPredicate                        ) const
// {

//     Array<const T*>        filteredArray ;

//     for (const auto& item : (*this))
//     {

//         if (aPredicate(item))
//         {
//             filteredArray.add(&item) ;
//         }

//     }

//     return filteredArray ;

// }

//                                 template <class T>
// Array<T>                    Array<T>::getWhere                        (    const    std::function<bool(const T&)>& aPredicate                        ) const
// {

//     Array<T>                filteredArray ;

//     std::copy_if
//     (
//         this->begin(),
//         this->end(),
//         std::back_inserter(filteredArray),
//         aPredicate
//     ) ;

//     return filteredArray ;

// }

                                template <class T>
T&                              Array<T>::accessFirst                       ( )
{
    return this->front() ;
}

                                template <class T>
T&                              Array<T>::accessLast                        ( )
{
    return this->back() ;
}

                                template <class T>
void                            Array<T>::add                               (   const   T&                          anElement                           )
{
    this->emplace_back(anElement) ;
}

                                template <class T>
void                            Array<T>::remove                            (   const   T&                          anElement                           )
{
    this->erase(std::remove(this->begin(), this->end(), anElement), this->end()) ;
}

                                template <class T>
void                            Array<T>::mergeWith                         (   const   Array<T>&                   anArray                             )
{
    this->insert(this->end(), anArray.begin(), anArray.end()) ;
}

//                                 template <class T>
// void                            Array<T>::removeWhere                    (    const    std::function<bool(const T&)>& aPredicate                        )
// {

//     LOG_SCOPE("Array :: removeWhere") ;

//     this->erase
//     (
//         std::remove_if
//         (
//             this->begin(), 
//             this->end(),
//             aPredicate
//         ),
//         this->end()
//     ) ;

// }

                                template <class T>
typename Array<T>::Iterator     Array<T>::find                              (   const   T&                          anElement                           )
{
    return std::find(this->begin(), this->end(), anElement) ;
}

                                template <class T>
Array<T>                        Array<T>::Empty                             ( )
{
    return Array<T>(std::vector<T>()) ;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////