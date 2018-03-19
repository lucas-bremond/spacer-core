////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Copyright (C) 2018 by Lucas Brémond
///
/// This file is part of the Spacer project.
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @file                       Spacer/Core/Types/Real.cpp
/// @author                     Lucas Brémond <lucas.bremond@gmail.com>
/// @date                       27 Dec 2017

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <limits>
#include <iostream>

#include <boost/lexical_cast.hpp>

#include <Spacer/Core/Types/Real.hpp>
#include <Spacer/Core/Error.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace spacer
{
namespace core
{
namespace types
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                Real::Real                                  (           Real::ValueType             aReal                               )
                                :   type_(Real::Type::Defined),
                                    value_(aReal)
{

}

Real&                           Real::operator =                            (           Real::ValueType             aReal                               )
{

    type_ = Real::Type::Defined ;
    value_ = aReal ;

    return (*this) ;

}

bool                            Real::operator ==                           (   const   Real&                       aReal                               ) const
{
    return (type_ == Real::Type::Defined) && (aReal.type_ == Real::Type::Defined) && (value_ == aReal.value_) ;
}

bool                            Real::operator !=                           (   const   Real&                       aReal                               ) const
{
    return (type_ == Real::Type::Defined) && (aReal.type_ == Real::Type::Defined) && (value_ != aReal.value_) ;
}

bool                            Real::operator <                            (   const   Real&                       aReal                               ) const
{
    return (type_ == Real::Type::Defined) && (aReal.type_ == Real::Type::Defined) && (value_ < aReal.value_) ;
}

bool                            Real::operator <=                           (   const   Real&                       aReal                               ) const
{
    return (type_ == Real::Type::Defined) && (aReal.type_ == Real::Type::Defined) && (value_ <= aReal.value_) ;
}

bool                            Real::operator >                            (   const   Real&                       aReal                               ) const
{
    return (type_ == Real::Type::Defined) && (aReal.type_ == Real::Type::Defined) && (value_ > aReal.value_) ;
}

bool                            Real::operator >=                           (   const   Real&                       aReal                               ) const
{
    return (type_ == Real::Type::Defined) && (aReal.type_ == Real::Type::Defined) && (value_ >= aReal.value_) ;
}

bool                            Real::operator ==                           (   const   Real::ValueType&            aReal                               ) const
{
    return (type_ == Real::Type::Defined) && (value_ == aReal) ;
}

bool                            Real::operator !=                           (   const   Real::ValueType&            aReal                               ) const
{
    return (type_ == Real::Type::Defined) && (value_ != aReal) ;
}

bool                            Real::operator <                            (   const   Real::ValueType&            aReal                               ) const
{
    return (type_ == Real::Type::Defined) && (value_ < aReal) ;
}

bool                            Real::operator <=                           (   const   Real::ValueType&            aReal                               ) const
{
    return (type_ == Real::Type::Defined) && (value_ <= aReal) ;
}

bool                            Real::operator >                            (   const   Real::ValueType&            aReal                               ) const
{
    return (type_ == Real::Type::Defined) && (value_ > aReal) ;
}

bool                            Real::operator >=                           (   const   Real::ValueType&            aReal                               ) const
{
    return (type_ == Real::Type::Defined) && (value_ >= aReal) ;
}

Real                            Real::operator +                            (   const   Real&                       aReal                               ) const
{

    if ((type_ != Real::Type::Undefined) && (aReal.type_ != Real::Type::Undefined))
    {

        if ((type_ == Real::Type::PositiveInfinity) && (aReal.type_ == Real::Type::PositiveInfinity))
        {
            return Real::PositiveInfinity() ;
        }
        else if ((type_ == Real::Type::NegativeInfinity) && (aReal.type_ == Real::Type::NegativeInfinity))
        {
            return Real::NegativeInfinity() ;
        }
        else if ((type_ == Real::Type::Defined) || (aReal.type_ == Real::Type::Defined))
        {

            if (type_ != Real::Type::Defined)
            {
                return (*this) ;
            }
            else if (aReal.type_ != Real::Type::Defined)
            {
                return aReal ;
            }

            // [TBC] Use __builtin_add_overflow instead?
            
            if ((aReal.value_ > 0.0) && (value_ > (std::numeric_limits<Real::ValueType>::max() - aReal.value_))) // Addition would overflow
            {
                return Real::PositiveInfinity() ;
            }

            if ((aReal.value_ < 0.0) && (value_ < (std::numeric_limits<Real::ValueType>::min() - aReal.value_))) // Addition would underflow
            {
                return Real::NegativeInfinity() ;
            }

            return Real(value_ + aReal.value_) ;

        }

    }

    return Real::Undefined() ;

}

Real                            Real::operator -                            (   const   Real&                       aReal                               ) const
{

    if ((type_ != Real::Type::Undefined) && (aReal.type_ != Real::Type::Undefined))
    {

        if ((type_ == Real::Type::PositiveInfinity) && (aReal.type_ == Real::Type::NegativeInfinity))
        {
            return Real::PositiveInfinity() ;
        }
        else if ((type_ == Real::Type::NegativeInfinity) && (aReal.type_ == Real::Type::PositiveInfinity))
        {
            return Real::NegativeInfinity() ;
        }
        else if ((type_ == Real::Type::Defined) || (aReal.type_ == Real::Type::Defined))
        {

            if (type_ != Real::Type::Defined)
            {
                return (*this) ;
            }
            else if (aReal.type_ != Real::Type::Defined)
            {

                if (aReal.type_ == Real::Type::PositiveInfinity)
                {
                    return Real::NegativeInfinity() ;
                }

                return Real::PositiveInfinity() ;

            }

            if ((aReal.value_ < 0.0) && (value_ > (std::numeric_limits<Real::ValueType>::max() + aReal.value_))) // Subtraction would overflow
            {
                return Real::PositiveInfinity() ;
            }

            if ((aReal.value_ > 0.0) && (value_ < (std::numeric_limits<Real::ValueType>::min() + aReal.value_))) // Subtraction would underflow
            {
                return Real::NegativeInfinity() ;
            }

            return Real(value_ - aReal.value_) ;

        }

    }

    return Real::Undefined() ;

}

Real                            Real::operator *                            (   const   Real&                       aReal                               ) const
{

    if ((type_ != Real::Type::Undefined) && (aReal.type_ != Real::Type::Undefined))
    {

        if (type_ == Real::Type::PositiveInfinity)
        {

            if (aReal.isStrictlyPositive())
            {
                return Real::PositiveInfinity() ;
            }
            else if (aReal.isStrictlyNegative())
            {
                return Real::NegativeInfinity() ;
            }
            
            return Real::Undefined() ;

        }
        else if (type_ == Real::Type::NegativeInfinity)
        {
            
            if (aReal.isStrictlyPositive())
            {
                return Real::NegativeInfinity() ;
            }
            else if (aReal.isStrictlyNegative())
            {
                return Real::PositiveInfinity() ;
            }
            
            return Real::Undefined() ;

        }
        else if (aReal.type_ == Real::Type::PositiveInfinity)
        {
            
            if (this->isStrictlyPositive())
            {
                return Real::PositiveInfinity() ;
            }
            else if (this->isStrictlyNegative())
            {
                return Real::NegativeInfinity() ;
            }
            
            return Real::Undefined() ;
            
        }
        else if (aReal.type_ == Real::Type::NegativeInfinity)
        {
            
            if (this->isStrictlyPositive())
            {
                return Real::NegativeInfinity() ;
            }
            else if (this->isStrictlyNegative())
            {
                return Real::PositiveInfinity() ;
            }
            
            return Real::Undefined() ;

        }
        else
        {

            if (this->isZero() || aReal.isZero())
            {
                return Real::Zero() ;
            }
            
            // Check for -1 for two's complement machines
            
            if ((value_ < 0.0) && (aReal.value_ == std::numeric_limits<Real::ValueType>::min())) // Multiplication can overflow
            {
                return Real::PositiveInfinity() ;
            }
            
            if ((aReal.value_ < 0.0) && (value_ == std::numeric_limits<Real::ValueType>::min())) // Multiplication can overflow
            {
                return Real::PositiveInfinity() ;
            }
            
            if ((this->getSign() == aReal.getSign()) && (std::abs(value_) > (std::numeric_limits<Real::ValueType>::max() / std::abs(aReal.value_)))) // Multiplication would overflow
            {
                return Real::PositiveInfinity() ;
            }

            if ((value_ == +1) && (aReal.value_ == std::numeric_limits<Real::ValueType>::min()))
            {
                return Real(std::numeric_limits<Real::ValueType>::min()) ;
            }

            if ((value_ == -1) && (aReal.value_ == std::numeric_limits<Real::ValueType>::min()))
            {
                return Real::PositiveInfinity() ;
            }
            
            if ((aReal.value_ != -1) && (this->getSign() != aReal.getSign()) && ((-std::abs(value_)) < (std::numeric_limits<Real::ValueType>::min() / std::abs(aReal.value_)))) // Multiplication would underflow
            {
                return Real::NegativeInfinity() ;
            }
            
            return Real(value_ * aReal.value_) ;

        }

    }

    return Real::Undefined() ;

}

Real                            Real::operator /                            (   const   Real&                       aReal                               ) const
{

    if (aReal.isZero())
    {
        return Real::Undefined() ;
    }

    if ((type_ != Real::Type::Undefined) && (aReal.type_ != Real::Type::Undefined))
    {

        if (type_ == Real::Type::PositiveInfinity)
        {

            if (aReal.isInfinity())
            {
                return Real::Undefined() ;
            }
            else if (aReal.isStrictlyPositive())
            {
                return Real::PositiveInfinity() ;
            }
            else if (aReal.isStrictlyNegative())
            {
                return Real::NegativeInfinity() ;
            }
            
            return Real::Undefined() ;

        }
        else if (type_ == Real::Type::NegativeInfinity)
        {
            
            if (aReal.isInfinity())
            {
                return Real::Undefined() ;
            }
            else if (aReal.isStrictlyPositive())
            {
                return Real::NegativeInfinity() ;
            }
            else if (aReal.isStrictlyNegative())
            {
                return Real::PositiveInfinity() ;
            }
            
            return Real::Undefined() ;

        }
        else
        {

            if (this->isZero() || aReal.isInfinity())
            {
                return Real::Zero() ;
            }
            else
            {

                if ((value_ == std::numeric_limits<Real::ValueType>::min()) && (aReal.value_ == -1))
                {
                    return Real::PositiveInfinity() ;
                }
                
                return Real(value_ / aReal.value_) ;

            }

        }

    }

    return Real::Undefined() ;

}

Real                            Real::operator +                            (   const   Real::ValueType&            aReal                               ) const
{
    return (*this) + Real(aReal) ;
}

Real                            Real::operator -                            (   const   Real::ValueType&            aReal                               ) const
{
    return (*this) - Real(aReal) ;
}

Real                            Real::operator *                            (   const   Real::ValueType&            aReal                               ) const
{
    return (*this) * Real(aReal) ;
}

Real                            Real::operator /                            (   const   Real::ValueType&            aReal                               ) const
{
    return (*this) / Real(aReal) ;
}

Real&                           Real::operator +=                           (   const   Real&                       aReal                               )
{

    (*this) = (*this) + aReal ;

    return (*this) ;

}

Real&                           Real::operator -=                           (   const   Real&                       aReal                               )
    {

    (*this) = (*this) - aReal ;

    return (*this) ;

}

Real&                           Real::operator *=                           (   const   Real&                       aReal                               )
    {

    (*this) = (*this) * aReal ;

    return (*this) ;

}

Real&                           Real::operator /=                           (   const   Real&                       aReal                               )
    {

    (*this) = (*this) / aReal ;

    return (*this) ;

}

Real&                           Real::operator +=                           (   const   Real::ValueType&            aReal                               )
{

    (*this) = (*this) + Real(aReal) ;

    return (*this) ;

}

Real&                           Real::operator -=                           (   const   Real::ValueType&            aReal                               )
{

    (*this) = (*this) - Real(aReal) ;

    return (*this) ;

}

Real&                           Real::operator *=                           (   const   Real::ValueType&            aReal                               )
{

    (*this) = (*this) * Real(aReal) ;

    return (*this) ;

}

Real&                           Real::operator /=                           (   const   Real::ValueType&            aReal                               )
{

    (*this) = (*this) / Real(aReal) ;

    return (*this) ;

}

Real                            operator +                                  (   const   Real::ValueType&            anInt,
                                                                                const   Real&                       aReal                               )
{
    return Real(anInt) + aReal ;
}

Real                            operator -                                  (   const   Real::ValueType&            anInt,
                                                                                const   Real&                       aReal                               )
{
    return Real(anInt) - aReal ;
}

Real                            operator *                                  (   const   Real::ValueType&            anInt,
                                                                                const   Real&                       aReal                               )
{
    return Real(anInt) * aReal ;
}

Real                            operator /                                  (   const   Real::ValueType&            anInt,
                                                                                const   Real&                       aReal                               )
{
    return Real(anInt) / aReal ;
}

Real                            Real::operator +                            ( ) const
{
    return (*this) ;
}

Real                            Real::operator -                            ( ) const
{
    
    switch (type_)
    {
    
        case Real::Type::Defined:
        {

            if (value_ == std::numeric_limits<Real::ValueType>::min())
            {
                return Real::PositiveInfinity() ;
            }
            
            return Real(-value_) ;

        }

        case Real::Type::Undefined:
            return Real::Undefined() ;

        case Real::Type::PositiveInfinity:
            return Real::NegativeInfinity() ;
        
        case Real::Type::NegativeInfinity:
            return Real::PositiveInfinity() ;
        
        default:
            break ;

    }

    return Real::Undefined() ;

}

                                Real::operator Real::ValueType        ( ) const
{

    if (type_ != Real::Type::Defined)
    {
        throw spacer::core::error::runtime::Undefined("Real") ;
    }
    
    return value_ ;

}

std::ostream&                   operator <<                                 (           std::ostream&               anOutputStream,
                                                                                const   Real&                       aReal                               )
{

    (void) aReal ;

    switch (aReal.type_)
    {

        case Real::Type::Undefined:
            anOutputStream << "Undefined" ;
            break ;

        case Real::Type::Defined:
            anOutputStream << aReal.value_ ;
            break ;

        case Real::Type::PositiveInfinity:
            anOutputStream << "+Inf" ;
            break ;

        case Real::Type::NegativeInfinity:
            anOutputStream << "-Inf" ;
            break ;

    }

    // spacer::core::utilities::Output::Header(anOutputStream, "Real") ;

    // spacer::core::utilities::Output::Line(anOutputStream) << "Type:" << aReal.type_ ;
    // spacer::core::utilities::Output::Line(anOutputStream) << "Value:" << aReal.value_ ;

    // spacer::core::utilities::Output::Footer(anOutputStream) ;

    return anOutputStream ;

}

bool                            Real::isDefined                             ( ) const
{
    return type_ != Real::Type::Undefined ;
}

bool                            Real::isZero                                ( ) const
{
    return (type_ == Real::Type::Defined) && (value_ == 0.0) ;
}

bool                            Real::isPositive                            ( ) const
{
    return ((type_ == Real::Type::Defined) && (value_ >= 0.0)) || this->isPositiveInfinity() ;
}

bool                            Real::isNegative                            ( ) const
{
    return ((type_ == Real::Type::Defined) && (value_ <= 0.0)) || this->isNegativeInfinity() ;
}

bool                            Real::isStrictlyPositive                    ( ) const
{
    return ((type_ == Real::Type::Defined) && (value_ > 0.0)) || this->isPositiveInfinity() ;
}

bool                            Real::isStrictlyNegative                    ( ) const
{
    return ((type_ == Real::Type::Defined) && (value_ < 0.0)) || this->isNegativeInfinity() ;
}

bool                            Real::isInfinity                            ( ) const
{
    return this->isPositiveInfinity() || this->isNegativeInfinity() ;
}

bool                            Real::isPositiveInfinity                    ( ) const
{
    return type_ == Real::Type::PositiveInfinity ;
}

bool                            Real::isNegativeInfinity                    ( ) const
{
    return type_ == Real::Type::NegativeInfinity ;
}

types::Sign                     Real::getSign                               ( ) const
{

    switch (type_)
    {

        case Real::Type::Undefined:
            return types::Sign::Undefined ;

        case Real::Type::Defined:
        {

            if (value_ > 0.0)
            {
                return types::Sign::Positive ;
            }
            else if (value_ < 0.0)
            {
                return types::Sign::Negative ;
            }
            
            return types::Sign::None ;

        }

        case Real::Type::PositiveInfinity:
            return types::Sign::Positive ;

        case Real::Type::NegativeInfinity:
            return types::Sign::Negative ;

        default:
           return types::Sign::Undefined ; 

    }

    return types::Sign::Undefined ;

}

types::String                   Real::getString                             ( ) const
{

    switch (type_)
    {

        case Real::Type::Undefined:
            return "Undefined" ;

        case Real::Type::Defined:
            return boost::lexical_cast<std::string>(value_) ;

        case Real::Type::PositiveInfinity:
            return "+Inf" ;

        case Real::Type::NegativeInfinity:
            return "-Inf" ;

    }

    return types::String::Empty() ;

}

// ctnr::Object                    Real::getObject                              ( ) const
// {

// }

Real                            Real::Undefined                             ( )
{
    return Real(Real::Type::Undefined, 0.0) ;
}

Real                            Real::Zero                                  ( )
{
    return Real(Real::Type::Defined, 0.0) ;
}

Real                            Real::PositiveInfinity                      ( )
{
    return Real(Real::Type::PositiveInfinity, std::numeric_limits<Real::ValueType>::max()) ;
}

Real                            Real::NegativeInfinity                      ( )
{
    return Real(Real::Type::NegativeInfinity, std::numeric_limits<Real::ValueType>::min()) ;
}

Real                            Real::String                                (   const   types::String&              aString                             )
{

    if (aString.isEmpty() || (aString == "Undefined"))
    {
        return Real::Undefined() ;
    }

    if ((aString == "Inf") || (aString == "+Inf"))
    {
        return Real::PositiveInfinity() ;
    }

    if (aString == "-Inf")
    {
        return Real::NegativeInfinity() ;
    }

    try
    {
        return Real(boost::lexical_cast<Real::ValueType>(aString)) ;
    }
    catch (const boost::bad_lexical_cast&)
    {
        throw spacer::core::error::RuntimeError("Cannot cast string [" + aString + "] to Real.") ;
    }

    return Real::Undefined() ;
    
}

// Real                             Real::Object                             (   const   ctnr::Object&               anObject                            )
// {
    
// }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                Real::Real                                  (   const   Real::Type&                 aType,
                                                                                const   Real::ValueType&            aReal                               )
                                :   type_(aType),
                                    value_(aReal)
{
    
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////