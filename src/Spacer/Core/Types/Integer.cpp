////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Copyright (C) 2017 by Lucas Brémond
///
/// This file is part of the Spacer project.
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @file                       Spacer/Core/Types/Integer.cpp
/// @author                     Lucas Brémond <lucas.bremond@gmail.com>
/// @date                       2 Dec 2017

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <limits>
#include <iostream>

#include <boost/lexical_cast.hpp>

#include <Spacer/Core/Types/Integer.hpp>
#include <Spacer/Core/Error.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace spacer
{
namespace core
{
namespace types
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                Integer::Integer                            (           Integer::ValueType          anInteger                           )
                                :   type_(Integer::Type::Defined),
                                    value_(anInteger)
{

}

Integer&                        Integer::operator =                         (           Integer::ValueType          anInteger                           )
{

    type_ = Integer::Type::Defined ;
    value_ = anInteger ;

    return (*this) ;

}

bool                            Integer::operator ==                        (   const   Integer&                    anInteger                           ) const
{
    return (type_ == Integer::Type::Defined) && (anInteger.type_ == Integer::Type::Defined) && (value_ == anInteger.value_) ;
}

bool                            Integer::operator !=                        (   const   Integer&                    anInteger                           ) const
{
    return (type_ == Integer::Type::Defined) && (anInteger.type_ == Integer::Type::Defined) && (value_ != anInteger.value_) ;
}

bool                            Integer::operator <                         (   const   Integer&                    anInteger                           ) const
{
    return (type_ == Integer::Type::Defined) && (anInteger.type_ == Integer::Type::Defined) && (value_ < anInteger.value_) ;
}

bool                            Integer::operator <=                        (   const   Integer&                    anInteger                           ) const
{
    return (type_ == Integer::Type::Defined) && (anInteger.type_ == Integer::Type::Defined) && (value_ <= anInteger.value_) ;
}

bool                            Integer::operator >                         (   const   Integer&                    anInteger                           ) const
{
    return (type_ == Integer::Type::Defined) && (anInteger.type_ == Integer::Type::Defined) && (value_ > anInteger.value_) ;
}

bool                            Integer::operator >=                        (   const   Integer&                    anInteger                           ) const
{
    return (type_ == Integer::Type::Defined) && (anInteger.type_ == Integer::Type::Defined) && (value_ >= anInteger.value_) ;
}

Integer                         Integer::operator +                         (   const   Integer&                    anInteger                           ) const
{

    if ((type_ != Integer::Type::Undefined) && (anInteger.type_ != Integer::Type::Undefined))
    {

        if ((type_ == Integer::Type::PositiveInfinity) && (anInteger.type_ == Integer::Type::PositiveInfinity))
        {
            return Integer::PositiveInfinity() ;
        }
        else if ((type_ == Integer::Type::NegativeInfinity) && (anInteger.type_ == Integer::Type::NegativeInfinity))
        {
            return Integer::NegativeInfinity() ;
        }
        else if ((type_ == Integer::Type::Defined) || (anInteger.type_ == Integer::Type::Defined))
        {

            if (type_ != Integer::Type::Defined)
            {
                return (*this) ;
            }
            else if (anInteger.type_ != Integer::Type::Defined)
            {
                return anInteger ;
            }

            // [TBC] Use __builtin_add_overflow instead?
            
            if ((anInteger.value_ > 0) && (value_ > (std::numeric_limits<Integer::ValueType>::max() - anInteger.value_))) // Addition would overflow
            {
                return Integer::PositiveInfinity() ;
            }

            if ((anInteger.value_ < 0) && (value_ < (std::numeric_limits<Integer::ValueType>::min() - anInteger.value_))) // Addition would underflow
            {
                return Integer::NegativeInfinity() ;
            }

            return Integer(value_ + anInteger.value_) ;

        }

    }

    return Integer::Undefined() ;

}

Integer                         Integer::operator -                         (   const   Integer&                    anInteger                           ) const
{

    if ((type_ != Integer::Type::Undefined) && (anInteger.type_ != Integer::Type::Undefined))
    {

        if ((type_ == Integer::Type::PositiveInfinity) && (anInteger.type_ == Integer::Type::NegativeInfinity))
        {
            return Integer::PositiveInfinity() ;
        }
        else if ((type_ == Integer::Type::NegativeInfinity) && (anInteger.type_ == Integer::Type::PositiveInfinity))
        {
            return Integer::NegativeInfinity() ;
        }
        else if ((type_ == Integer::Type::Defined) || (anInteger.type_ == Integer::Type::Defined))
        {

            if (type_ != Integer::Type::Defined)
            {
                return (*this) ;
            }
            else if (anInteger.type_ != Integer::Type::Defined)
            {

                if (anInteger.type_ == Integer::Type::PositiveInfinity)
                {
                    return Integer::NegativeInfinity() ;
                }

                return Integer::PositiveInfinity() ;

            }

            if ((anInteger.value_ < 0) && (value_ > (std::numeric_limits<Integer::ValueType>::max() + anInteger.value_))) // Subtraction would overflow
            {
                return Integer::PositiveInfinity() ;
            }

            if ((anInteger.value_ > 0) && (value_ < (std::numeric_limits<Integer::ValueType>::min() + anInteger.value_))) // Subtraction would underflow
            {
                return Integer::NegativeInfinity() ;
            }

            return Integer(value_ - anInteger.value_) ;

        }

    }

    return Integer::Undefined() ;

}

Integer                         Integer::operator *                         (   const   Integer&                    anInteger                           ) const
{

    if ((type_ != Integer::Type::Undefined) && (anInteger.type_ != Integer::Type::Undefined))
    {

        if (type_ == Integer::Type::PositiveInfinity)
        {

            if (anInteger.isStrictlyPositive())
            {
                return Integer::PositiveInfinity() ;
            }
            else if (anInteger.isStrictlyNegative())
            {
                return Integer::NegativeInfinity() ;
            }
            
            return Integer::Undefined() ;

        }
        else if (type_ == Integer::Type::NegativeInfinity)
        {
            
            if (anInteger.isStrictlyPositive())
            {
                return Integer::NegativeInfinity() ;
            }
            else if (anInteger.isStrictlyNegative())
            {
                return Integer::PositiveInfinity() ;
            }
            
            return Integer::Undefined() ;

        }
        else if (anInteger.type_ == Integer::Type::PositiveInfinity)
        {
            
            if (this->isStrictlyPositive())
            {
                return Integer::PositiveInfinity() ;
            }
            else if (this->isStrictlyNegative())
            {
                return Integer::NegativeInfinity() ;
            }
            
            return Integer::Undefined() ;
            
        }
        else if (anInteger.type_ == Integer::Type::NegativeInfinity)
        {
            
            if (this->isStrictlyPositive())
            {
                return Integer::NegativeInfinity() ;
            }
            else if (this->isStrictlyNegative())
            {
                return Integer::PositiveInfinity() ;
            }
            
            return Integer::Undefined() ;

        }
        else
        {

            if (this->isZero() || anInteger.isZero())
            {
                return Integer::Zero() ;
            }
            
            // Check for -1 for two's complement machines
            
            if ((value_ < 0) && (anInteger.value_ == std::numeric_limits<Integer::ValueType>::min())) // Multiplication can overflow
            {
                return Integer::PositiveInfinity() ;
            }
            
            if ((anInteger.value_ < 0) && (value_ == std::numeric_limits<Integer::ValueType>::min())) // Multiplication can overflow
            {
                return Integer::PositiveInfinity() ;
            }
            
            if ((this->getSign() == anInteger.getSign()) && (std::abs(value_) > (std::numeric_limits<Integer::ValueType>::max() / std::abs(anInteger.value_)))) // Multiplication would overflow
            {
                return Integer::PositiveInfinity() ;
            }

            if ((value_ == +1) && (anInteger.value_ == std::numeric_limits<Integer::ValueType>::min()))
            {
                return Integer(std::numeric_limits<Integer::ValueType>::min()) ;
            }

            if ((value_ == -1) && (anInteger.value_ == std::numeric_limits<Integer::ValueType>::min()))
            {
                return Integer::PositiveInfinity() ;
            }
            
            if ((anInteger.value_ != -1) && (this->getSign() != anInteger.getSign()) && ((-std::abs(value_)) < (std::numeric_limits<Integer::ValueType>::min() / std::abs(anInteger.value_)))) // Multiplication would underflow
            {
                return Integer::NegativeInfinity() ;
            }
            
            return Integer(value_ * anInteger.value_) ;

        }

    }

    return Integer::Undefined() ;

}

Integer                         Integer::operator /                         (   const   Integer&                    anInteger                           ) const
{

    if (anInteger.isZero())
    {
        return Integer::Undefined() ;
    }

    if ((type_ != Integer::Type::Undefined) && (anInteger.type_ != Integer::Type::Undefined))
    {

        if (type_ == Integer::Type::PositiveInfinity)
        {

            if (anInteger.isInfinity())
            {
                return Integer::Undefined() ;
            }
            else if (anInteger.isStrictlyPositive())
            {
                return Integer::PositiveInfinity() ;
            }
            else if (anInteger.isStrictlyNegative())
            {
                return Integer::NegativeInfinity() ;
            }
            
            return Integer::Undefined() ;

        }
        else if (type_ == Integer::Type::NegativeInfinity)
        {
            
            if (anInteger.isInfinity())
            {
                return Integer::Undefined() ;
            }
            else if (anInteger.isStrictlyPositive())
            {
                return Integer::NegativeInfinity() ;
            }
            else if (anInteger.isStrictlyNegative())
            {
                return Integer::PositiveInfinity() ;
            }
            
            return Integer::Undefined() ;

        }
        else
        {

            if (this->isZero() || anInteger.isInfinity())
            {
                return Integer::Zero() ;
            }
            else
            {

                if ((value_ == std::numeric_limits<Integer::ValueType>::min()) && (anInteger.value_ == -1))
                {
                    return Integer::PositiveInfinity() ;
                }
                
                return Integer(value_ / anInteger.value_) ;

            }

        }

    }

    return Integer::Undefined() ;

}

Integer                         Integer::operator %                         (   const   Integer&                    anInteger                           ) const
{

    if (anInteger.isZero())
    {
        return Integer::Undefined() ;
    }

    if ((type_ != Integer::Type::Undefined) && (anInteger.type_ != Integer::Type::Undefined))
    {

        if (this->isZero())
        {
            return Integer::Zero() ;
        }
        else if (!this->isInfinity() && anInteger.isInfinity())
        {
            return (*this) ;
        }
        else if ((!this->isInfinity()) && this->isStrictlyPositive() && (!anInteger.isInfinity()) && (anInteger.value_ == std::numeric_limits<Integer::ValueType>::min()))
        {
            return (*this) ;
        }
        else if ((!anInteger.isInfinity()) && (std::abs(anInteger.value_) == 1))
        {
            return Integer::Zero() ;
        }
        else if (this->isInfinity())
        {
            return Integer::Undefined() ;
        }
        else
        {
            return Integer(value_ % anInteger.value_) ;
        }

    }

    return Integer::Undefined() ;

}

Integer                         Integer::operator +                         (   const   Integer::ValueType&         anInteger                           ) const
{
    return (*this) + Integer(anInteger) ;
}

Integer                         Integer::operator -                         (   const   Integer::ValueType&         anInteger                           ) const
{
    return (*this) - Integer(anInteger) ;
}

Integer                         Integer::operator *                         (   const   Integer::ValueType&         anInteger                           ) const
{
    return (*this) * Integer(anInteger) ;
}

Integer                         Integer::operator /                         (   const   Integer::ValueType&         anInteger                           ) const
{
    return (*this) / Integer(anInteger) ;
}

Integer                         Integer::operator %                         (   const   Integer::ValueType&         anInteger                           ) const
{
    return (*this) % Integer(anInteger) ;
}

Integer&                        Integer::operator +=                        (   const   Integer&                    anInteger                           )
{

    (*this) = (*this) + anInteger ;

    return (*this) ;

}

Integer&                        Integer::operator -=                        (   const   Integer&                    anInteger                           )
{

    (*this) = (*this) - anInteger ;

    return (*this) ;

}

Integer&                        Integer::operator *=                        (   const   Integer&                    anInteger                           )
{

    (*this) = (*this) * anInteger ;

    return (*this) ;

}

Integer&                        Integer::operator /=                        (   const   Integer&                    anInteger                           )
{

    (*this) = (*this) / anInteger ;

    return (*this) ;

}

Integer&                        Integer::operator %=                        (   const   Integer&                    anInteger                           )
{

    (*this) = (*this) % anInteger ;

    return (*this) ;

}

Integer&                        Integer::operator +=                        (   const   Integer::ValueType&         anInteger                           )
{

    (*this) = (*this) + Integer(anInteger) ;

    return (*this) ;

}

Integer&                        Integer::operator -=                        (   const   Integer::ValueType&         anInteger                           )
{

    (*this) = (*this) - Integer(anInteger) ;

    return (*this) ;

}

Integer&                        Integer::operator *=                        (   const   Integer::ValueType&         anInteger                           )
{

    (*this) = (*this) * Integer(anInteger) ;

    return (*this) ;

}

Integer&                        Integer::operator /=                        (   const   Integer::ValueType&         anInteger                           )
{

    (*this) = (*this) / Integer(anInteger) ;

    return (*this) ;

}

Integer&                        Integer::operator %=                        (   const   Integer::ValueType&         anInteger                           )
{

    (*this) = (*this) % Integer(anInteger) ;

    return (*this) ;

}

Integer                         operator +                                  (   const   Integer::ValueType&         anInt,
                                                                                const   Integer&                    anInteger                           )
{
    return Integer(anInt) + anInteger ;
}

Integer                         operator -                                  (   const   Integer::ValueType&         anInt,
                                                                                const   Integer&                    anInteger                           )
{
    return Integer(anInt) - anInteger ;
}

Integer                         operator *                                  (   const   Integer::ValueType&         anInt,
                                                                                const   Integer&                    anInteger                           )
{
    return Integer(anInt) * anInteger ;
}

Integer                         operator /                                  (   const   Integer::ValueType&         anInt,
                                                                                const   Integer&                    anInteger                           )
{
    return Integer(anInt) / anInteger ;
}

Integer                         operator %                                  (   const   Integer::ValueType&         anInt,
                                                                                const   Integer&                    anInteger                           )
{
    return Integer(anInt) % anInteger ;
}

Integer                         Integer::operator +                         ( ) const
{
    return (*this) ;
}

Integer                         Integer::operator -                         ( ) const
{
    
    switch (type_)
    {
    
        case Integer::Type::Defined:
        {

            if (value_ == std::numeric_limits<Integer::ValueType>::min())
            {
                return Integer::PositiveInfinity() ;
            }
            
            return Integer(-value_) ;

        }

        case Integer::Type::Undefined:
            return Integer::Undefined() ;

        case Integer::Type::PositiveInfinity:
            return Integer::NegativeInfinity() ;
        
        case Integer::Type::NegativeInfinity:
            return Integer::PositiveInfinity() ;
        
        default:
            break ;

    }

    return Integer::Undefined() ;

}

Integer&                        Integer::operator ++                        ( )
{

    switch (type_)
    {
    
        case Integer::Type::Defined:
        {

            if (value_ == std::numeric_limits<Integer::ValueType>::max())
            {
                type_ = Integer::Type::PositiveInfinity ;
            }
            else
            {
                ++value_ ;
            }

            break ;

        }

        case Integer::Type::Undefined:
        case Integer::Type::PositiveInfinity:
        case Integer::Type::NegativeInfinity:
        default:
            break ;

    }

    return (*this) ;

}

Integer&                        Integer::operator --                        ( )
{

    switch (type_)
    {
    
        case Integer::Type::Defined:
        {

            if (value_ == std::numeric_limits<Integer::ValueType>::min())
            {
                type_ = Integer::Type::NegativeInfinity ;
            }
            else
            {
                --value_ ;
            }

            break ;

        }

        case Integer::Type::Undefined:
        case Integer::Type::PositiveInfinity:
        case Integer::Type::NegativeInfinity:
        default:
            break ;

    }

    return (*this) ;

}

Integer                         Integer::operator ++                        (           int                         anInteger                           )
{

    (void) anInteger ;

    Integer integerCopy(*this) ;

    switch (type_)
    {
    
        case Integer::Type::Defined:
        {

            if (value_ == std::numeric_limits<Integer::ValueType>::max())
            {
                type_ = Integer::Type::PositiveInfinity ;
            }
            else
            {
                value_++ ;
            }

            break ;

        }

        case Integer::Type::Undefined:
        case Integer::Type::PositiveInfinity:
        case Integer::Type::NegativeInfinity:
        default:
            break ;

    }

    return integerCopy ;

}

Integer                         Integer::operator --                        (           int                         anInteger                           )
{

    (void) anInteger ;

    Integer integerCopy(*this) ;

    switch (type_)
    {
    
        case Integer::Type::Defined:
        {

            if (value_ == std::numeric_limits<Integer::ValueType>::min())
            {
                type_ = Integer::Type::NegativeInfinity ;
            }
            else
            {
                value_-- ;
            }

            break ;

        }

        case Integer::Type::Undefined:
        case Integer::Type::PositiveInfinity:
        case Integer::Type::NegativeInfinity:
        default:
            break ;

    }

    return integerCopy ;

}

                                Integer::operator Integer::ValueType        ( ) const
{

    if (type_ != Integer::Type::Defined)
    {
        throw spacer::core::error::runtime::Undefined("Integer") ;
    }
    
    return value_ ;

}

std::ostream&                   operator <<                                 (           std::ostream&               anOutputStream,
                                                                                const   Integer&                    anInteger                           )
{

    (void) anInteger ;

    switch (anInteger.type_)
    {

        case Integer::Type::Undefined:
            anOutputStream << "Undefined" ;
            break ;

        case Integer::Type::Defined:
            anOutputStream << anInteger.value_ ;
            break ;

        case Integer::Type::PositiveInfinity:
            anOutputStream << "+Inf" ;
            break ;

        case Integer::Type::NegativeInfinity:
            anOutputStream << "-Inf" ;
            break ;

    }

    // spacer::core::utilities::Output::Header(anOutputStream, "Integer") ;

    // spacer::core::utilities::Output::Line(anOutputStream) << "Type:" << anInteger.type_ ;
    // spacer::core::utilities::Output::Line(anOutputStream) << "Value:" << anInteger.value_ ;

    // spacer::core::utilities::Output::Footer(anOutputStream) ;

    return anOutputStream ;

}

bool                            Integer::isDefined                          ( ) const
{
    return type_ != Integer::Type::Undefined ;
}

bool                            Integer::isZero                             ( ) const
{
    return (type_ == Integer::Type::Defined) && (value_ == 0) ;
}

bool                            Integer::isPositive                         ( ) const
{
    return ((type_ == Integer::Type::Defined) && (value_ >= 0)) || this->isPositiveInfinity() ;
}

bool                            Integer::isNegative                         ( ) const
{
    return ((type_ == Integer::Type::Defined) && (value_ <= 0)) || this->isNegativeInfinity() ;
}

bool                            Integer::isStrictlyPositive                 ( ) const
{
    return ((type_ == Integer::Type::Defined) && (value_ > 0)) || this->isPositiveInfinity() ;
}

bool                            Integer::isStrictlyNegative                 ( ) const
{
    return ((type_ == Integer::Type::Defined) && (value_ < 0)) || this->isNegativeInfinity() ;
}

bool                            Integer::isInfinity                         ( ) const
{
    return this->isPositiveInfinity() || this->isNegativeInfinity() ;
}

bool                            Integer::isPositiveInfinity                 ( ) const
{
    return type_ == Integer::Type::PositiveInfinity ;
}

bool                            Integer::isNegativeInfinity                 ( ) const
{
    return type_ == Integer::Type::NegativeInfinity ;
}

types::Sign                     Integer::getSign                            ( ) const
{

    switch (type_)
    {

        case Integer::Type::Undefined:
            return types::Sign::Undefined ;

        case Integer::Type::Defined:
        {

            if (value_ > 0)
            {
                return types::Sign::Positive ;
            }
            else if (value_ < 0)
            {
                return types::Sign::Negative ;
            }
            
            return types::Sign::None ;

        }

        case Integer::Type::PositiveInfinity:
            return types::Sign::Positive ;

        case Integer::Type::NegativeInfinity:
            return types::Sign::Negative ;

        default:
           return types::Sign::Undefined ; 

    }

    return types::Sign::Undefined ;

}

types::String                   Integer::getString                          ( ) const
{

    switch (type_)
    {

        case Integer::Type::Undefined:
            return "Undefined" ;

        case Integer::Type::Defined:
            return boost::lexical_cast<std::string>(value_) ;

        case Integer::Type::PositiveInfinity:
            return "+Inf" ;

        case Integer::Type::NegativeInfinity:
            return "-Inf" ;

    }

    return types::String::Empty() ;

}

// ctnr::Object                    Integer::getObject                          ( ) const
// {

// }

Integer                         Integer::Undefined                          ( )
{
    return Integer(Integer::Type::Undefined, 0) ;
}

Integer                         Integer::Zero                               ( )
{
    return Integer(Integer::Type::Defined, 0) ;
}

Integer                         Integer::PositiveInfinity                   ( )
{
    return Integer(Integer::Type::PositiveInfinity, std::numeric_limits<Integer::ValueType>::max()) ;
}

Integer                         Integer::NegativeInfinity                   ( )
{
    return Integer(Integer::Type::NegativeInfinity, std::numeric_limits<Integer::ValueType>::min()) ;
}

// Integer                         Integer::String                             (   const   types::String&              aString                             )
// {
    
// }

// Integer                         Integer::Object                             (   const   ctnr::Object&               anObject                            )
// {
    
// }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                Integer::Integer                            (   const   Integer::Type&              aType,
                                                                                const   Integer::ValueType&         anInteger                           )
                                :   type_(aType),
                                    value_(anInteger)
{
    
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////