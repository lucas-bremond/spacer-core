////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Copyright (C) 2018 by Lucas Brémond
///
/// This file is part of the Spacer project.
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @file                       Spacer/Core/Types/Real.test.cpp
/// @author                     Lucas Brémond <lucas.bremond@gmail.com>
/// @date                       27 Dec 2017

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Global.test.hpp>

#include <Spacer/Core/Types/Real.hpp>
#include <Spacer/Core/Containers/Pair.hpp>
#include <Spacer/Core/Containers/Triple.hpp>
#include <Spacer/Core/Containers/Array.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(Spacer_Core_Types_Real, DefaultConstructor)
{

    using spacer::core::types::Real ;

    EXPECT_NO_THROW(Real(0.0)) ;
    EXPECT_NO_THROW(Real(1.0)) ;
    EXPECT_NO_THROW(Real(123.0)) ;
    EXPECT_NO_THROW(Real(+123.0)) ;
    EXPECT_NO_THROW(Real(-123.0)) ;

}

TEST(Spacer_Core_Types_Real, AssignmentOperator)
{

    using spacer::core::types::Real ;

    EXPECT_NO_THROW(Real a = 0.0 ; (void) a ; ) ;
    EXPECT_NO_THROW(Real a = 0.0 ; (void) a ; ) ;
    EXPECT_NO_THROW(Real a = 1.0 ; (void) a ; ) ;
    EXPECT_NO_THROW(Real a = 123.0 ; (void) a ; ) ;
    EXPECT_NO_THROW(Real a = +123.0 ; (void) a ; ) ;
    EXPECT_NO_THROW(Real a = -123.0 ; (void) a ; ) ;

}

TEST(Spacer_Core_Types_Real, EqualToOperator)
{

    using spacer::core::types::Real ;

    EXPECT_TRUE(Real(0.0) == Real(0.0)) ;
    EXPECT_TRUE(Real(123.0) == Real(123.0)) ;
    EXPECT_TRUE(Real(+123.0) == Real(+123.0)) ;
    EXPECT_TRUE(Real(-123.0) == Real(-123.0)) ;

    EXPECT_FALSE(Real(0.0) == Real(1.0)) ;
    EXPECT_FALSE(Real(1.0) == Real(0.0)) ;
    EXPECT_FALSE(Real(-1.0) == Real(+1.0)) ;

    EXPECT_FALSE(Real::Undefined() == Real::Undefined()) ;
    EXPECT_FALSE(Real::PositiveInfinity() == Real::PositiveInfinity()) ;
    EXPECT_FALSE(Real::NegativeInfinity() == Real::NegativeInfinity()) ;
    EXPECT_FALSE(Real::PositiveInfinity() == Real::NegativeInfinity()) ;
    EXPECT_FALSE(Real::NegativeInfinity() == Real::PositiveInfinity()) ;

}

TEST(Spacer_Core_Types_Real, NotEqualToOperator)
{

    using spacer::core::types::Real ;    

    EXPECT_TRUE(Real(0.0) != Real(1.0)) ;
    EXPECT_TRUE(Real(1.0) != Real(0.0)) ;
    EXPECT_TRUE(Real(-1.0) != Real(+1.0)) ;

    EXPECT_FALSE(Real(0.0) != Real(0.0)) ;
    EXPECT_FALSE(Real(123.0) != Real(123.0)) ;
    EXPECT_FALSE(Real(+123.0) != Real(+123.0)) ;
    EXPECT_FALSE(Real(-123.0) != Real(-123.0)) ;

    EXPECT_FALSE(Real::Undefined() != Real::Undefined()) ;
    EXPECT_FALSE(Real::PositiveInfinity() != Real::PositiveInfinity()) ;
    EXPECT_FALSE(Real::NegativeInfinity() != Real::NegativeInfinity()) ;
    EXPECT_FALSE(Real::PositiveInfinity() != Real::NegativeInfinity()) ;
    EXPECT_FALSE(Real::NegativeInfinity() != Real::PositiveInfinity()) ;

}

TEST(Spacer_Core_Types_Real, LessThanOperator)
{

    using spacer::core::types::Real ;

    EXPECT_TRUE(Real(0.0) < Real(1.0)) ;
    EXPECT_TRUE(Real(1.0) < Real(2.0)) ;
    EXPECT_TRUE(Real(-1.0) < Real(0.0)) ;
    EXPECT_TRUE(Real(-1.0) < Real(+1.0)) ;
    EXPECT_TRUE(Real(-123.0) < Real(+123.0)) ;

    EXPECT_FALSE(Real(0.0) < Real(0.0)) ;
    EXPECT_FALSE(Real(1.0) < Real(0.0)) ;
    EXPECT_FALSE(Real(+1.0) < Real(-1.0)) ;
    EXPECT_FALSE(Real(+123.0) < Real(-123.0)) ;
    EXPECT_FALSE(Real(+123.0) < Real(+123.0)) ;
    EXPECT_FALSE(Real(-123.0) < Real(-123.0)) ;
    
    EXPECT_FALSE(Real::Undefined() < Real::Undefined()) ;
    EXPECT_FALSE(Real::PositiveInfinity() < Real::PositiveInfinity()) ;
    EXPECT_FALSE(Real::NegativeInfinity() < Real::NegativeInfinity()) ;
    EXPECT_FALSE(Real::PositiveInfinity() < Real::NegativeInfinity()) ;
    EXPECT_FALSE(Real::NegativeInfinity() < Real::PositiveInfinity()) ;

}

TEST(Spacer_Core_Types_Real, LessThanOrEqualToOperator)
{

    using spacer::core::types::Real ;

    EXPECT_TRUE(Real(0.0) <= Real(1.0)) ;
    EXPECT_TRUE(Real(1.0) <= Real(2.0)) ;
    EXPECT_TRUE(Real(-1.0) <= Real(0.0)) ;
    EXPECT_TRUE(Real(-1.0) <= Real(+1.0)) ;
    EXPECT_TRUE(Real(-123.0) <= Real(+123.0)) ;
    EXPECT_TRUE(Real(0.0) <= Real(0.0)) ;
    EXPECT_TRUE(Real(+123.0) <= Real(+123.0)) ;
    EXPECT_TRUE(Real(-123.0) <= Real(-123.0)) ;

    EXPECT_FALSE(Real(1.0) <= Real(0.0)) ;
    EXPECT_FALSE(Real(+1.0) <= Real(-1.0)) ;
    EXPECT_FALSE(Real(+123.0) <= Real(-123.0)) ;
    
    EXPECT_FALSE(Real::Undefined() <= Real::Undefined()) ;
    EXPECT_FALSE(Real::PositiveInfinity() <= Real::PositiveInfinity()) ;
    EXPECT_FALSE(Real::NegativeInfinity() <= Real::NegativeInfinity()) ;
    EXPECT_FALSE(Real::PositiveInfinity() <= Real::NegativeInfinity()) ;
    EXPECT_FALSE(Real::NegativeInfinity() <= Real::PositiveInfinity()) ;

}

TEST(Spacer_Core_Types_Real, GreaterThanOperator)
{

    using spacer::core::types::Real ;

    EXPECT_TRUE(Real(1.0) > Real(0.0)) ;
    EXPECT_TRUE(Real(2.0) > Real(1.0)) ;
    EXPECT_TRUE(Real(+1.0) > Real(0.0)) ;
    EXPECT_TRUE(Real(+1.0) > Real(-1.0)) ;
    EXPECT_TRUE(Real(+123.0) > Real(-123.0)) ;

    EXPECT_FALSE(Real(0.0) > Real(0.0)) ;
    EXPECT_FALSE(Real(0.0) > Real(1.0)) ;
    EXPECT_FALSE(Real(-1.0) > Real(+1.0)) ;
    EXPECT_FALSE(Real(-123.0) > Real(+123.0)) ;
    EXPECT_FALSE(Real(+123.0) > Real(+123.0)) ;
    EXPECT_FALSE(Real(-123.0) > Real(-123.0)) ;
    
    EXPECT_FALSE(Real::Undefined() > Real::Undefined()) ;
    EXPECT_FALSE(Real::PositiveInfinity() > Real::PositiveInfinity()) ;
    EXPECT_FALSE(Real::NegativeInfinity() > Real::NegativeInfinity()) ;
    EXPECT_FALSE(Real::PositiveInfinity() > Real::NegativeInfinity()) ;
    EXPECT_FALSE(Real::NegativeInfinity() > Real::PositiveInfinity()) ;

}

TEST(Spacer_Core_Types_Real, GreaterThanOrEqualToOperator)
{

    using spacer::core::types::Real ;

    EXPECT_TRUE(Real(1.0) >= Real(0.0)) ;
    EXPECT_TRUE(Real(2.0) >= Real(1.0)) ;
    EXPECT_TRUE(Real(+1.0) >= Real(0.0)) ;
    EXPECT_TRUE(Real(+1.0) >= Real(-1.0)) ;
    EXPECT_TRUE(Real(+123.0) >= Real(-123.0)) ;
    EXPECT_TRUE(Real(0.0) >= Real(0.0)) ;
    EXPECT_TRUE(Real(+123.0) >= Real(+123.0)) ;
    EXPECT_TRUE(Real(-123.0) >= Real(-123.0)) ;

    EXPECT_FALSE(Real(0.0) >= Real(1.0)) ;
    EXPECT_FALSE(Real(-1.0) >= Real(+1.0)) ;
    EXPECT_FALSE(Real(-123.0) >= Real(+123.0)) ;
    
    EXPECT_FALSE(Real::Undefined() >= Real::Undefined()) ;
    EXPECT_FALSE(Real::PositiveInfinity() >= Real::PositiveInfinity()) ;
    EXPECT_FALSE(Real::NegativeInfinity() >= Real::NegativeInfinity()) ;
    EXPECT_FALSE(Real::PositiveInfinity() >= Real::NegativeInfinity()) ;
    EXPECT_FALSE(Real::NegativeInfinity() >= Real::PositiveInfinity()) ;

}

TEST(Spacer_Core_Types_Real, AdditionOperator)
{

    using spacer::core::types::Real ;
    using spacer::core::ctnr::Triple ;
    using spacer::core::ctnr::Array ;

    Array<Triple<Real, Real, Real>> testCases =
    {

        {Real::Undefined(), Real::Undefined(), Real::Undefined()},
        {Real::Undefined(), Real::NegativeInfinity(), Real::Undefined()},
        {Real::Undefined(), std::numeric_limits<Real::ValueType>::min(), Real::Undefined()},
        {Real::Undefined(), -2.0, Real::Undefined()},
        {Real::Undefined(), -1.0, Real::Undefined()},
        {Real::Undefined(), +0.0, Real::Undefined()},
        {Real::Undefined(), +1.0, Real::Undefined()},
        {Real::Undefined(), +2.0, Real::Undefined()},
        {Real::Undefined(), std::numeric_limits<Real::ValueType>::max(), Real::Undefined()},
        {Real::Undefined(), Real::PositiveInfinity(), Real::Undefined()},

        {Real::NegativeInfinity(), Real::Undefined(), Real::Undefined()},
        {Real::NegativeInfinity(), Real::NegativeInfinity(), Real::NegativeInfinity()},
        {Real::NegativeInfinity(), std::numeric_limits<Real::ValueType>::min(), Real::NegativeInfinity()},
        {Real::NegativeInfinity(), -2.0, Real::NegativeInfinity()},
        {Real::NegativeInfinity(), -1.0, Real::NegativeInfinity()},
        {Real::NegativeInfinity(), +0.0, Real::NegativeInfinity()},
        {Real::NegativeInfinity(), +1.0, Real::NegativeInfinity()},
        {Real::NegativeInfinity(), +2.0, Real::NegativeInfinity()},
        {Real::NegativeInfinity(), std::numeric_limits<Real::ValueType>::max(), Real::NegativeInfinity()},
        {Real::NegativeInfinity(), Real::PositiveInfinity(), Real::Undefined()},

        {std::numeric_limits<Real::ValueType>::min(), Real::Undefined(), Real::Undefined()},
        {std::numeric_limits<Real::ValueType>::min(), Real::NegativeInfinity(), Real::NegativeInfinity()},
        {std::numeric_limits<Real::ValueType>::min(), std::numeric_limits<Real::ValueType>::min(), Real::NegativeInfinity()},
        {std::numeric_limits<Real::ValueType>::min(), -2.0, Real::NegativeInfinity()},
        {std::numeric_limits<Real::ValueType>::min(), -1.0, Real::NegativeInfinity()},
        {std::numeric_limits<Real::ValueType>::min(), +0.0, std::numeric_limits<Real::ValueType>::min()},
        {std::numeric_limits<Real::ValueType>::min(), +1.0, std::numeric_limits<Real::ValueType>::min() + 1},
        {std::numeric_limits<Real::ValueType>::min(), +2.0, std::numeric_limits<Real::ValueType>::min() + 2},
        {std::numeric_limits<Real::ValueType>::min(), std::numeric_limits<Real::ValueType>::max(), std::numeric_limits<Real::ValueType>::min() + std::numeric_limits<Real::ValueType>::max()},
        {std::numeric_limits<Real::ValueType>::min(), Real::PositiveInfinity(), Real::PositiveInfinity()},

        {-2.0, Real::Undefined(), Real::Undefined()},
        {-2.0, Real::NegativeInfinity(), Real::NegativeInfinity()},
        {-2.0, std::numeric_limits<Real::ValueType>::min(), Real::NegativeInfinity()},
        {-2.0, -2.0, -4.0},
        {-2.0, -1.0, -3.0},
        {-2.0, +0.0, -2.0},
        {-2.0, +1.0, -1.0},
        {-2.0, +2.0, +0.0},
        {-2.0, std::numeric_limits<Real::ValueType>::max(), std::numeric_limits<Real::ValueType>::max() - 2},
        {-2.0, Real::PositiveInfinity(), Real::PositiveInfinity()},

        {-1.0, Real::Undefined(), Real::Undefined()},
        {-1.0, Real::NegativeInfinity(), Real::NegativeInfinity()},
        {-1.0, std::numeric_limits<Real::ValueType>::min(), Real::NegativeInfinity()},
        {-1.0, -2.0, -3.0},
        {-1.0, -1.0, -2.0},
        {-1.0, +0.0, -1.0},
        {-1.0, +1.0, +0.0},
        {-1.0, +2.0, +1.0},
        {-1.0, std::numeric_limits<Real::ValueType>::max(), std::numeric_limits<Real::ValueType>::max() - 1},
        {-1.0, Real::PositiveInfinity(), Real::PositiveInfinity()},

        {+0.0, Real::Undefined(), Real::Undefined()},
        {+0.0, Real::NegativeInfinity(), Real::NegativeInfinity()},
        {+0.0, std::numeric_limits<Real::ValueType>::min(), std::numeric_limits<Real::ValueType>::min()},
        {+0.0, -2.0, -2.0},
        {+0.0, -1.0, -1.0},
        {+0.0, +0.0, +0.0},
        {+0.0, +1.0, +1.0},
        {+0.0, +2.0, +2.0},
        {+0.0, std::numeric_limits<Real::ValueType>::max(), std::numeric_limits<Real::ValueType>::max()},
        {+0.0, Real::PositiveInfinity(), Real::PositiveInfinity()},

        {+1.0, Real::Undefined(), Real::Undefined()},
        {+1.0, Real::NegativeInfinity(), Real::NegativeInfinity()},
        {+1.0, std::numeric_limits<Real::ValueType>::min(), std::numeric_limits<Real::ValueType>::min() + 1},
        {+1.0, -2.0, -1.0},
        {+1.0, -1.0, +0.0},
        {+1.0, +0.0, +1.0},
        {+1.0, +1.0, +2.0},
        {+1.0, +2.0, +3.0},
        {+1.0, std::numeric_limits<Real::ValueType>::max(), Real::PositiveInfinity()},
        {+1.0, Real::PositiveInfinity(), Real::PositiveInfinity()},
        
        {+2.0, Real::Undefined(), Real::Undefined()},
        {+2.0, Real::NegativeInfinity(), Real::NegativeInfinity()},
        {+2.0, std::numeric_limits<Real::ValueType>::min(), std::numeric_limits<Real::ValueType>::min() + 2},
        {+2.0, -2.0, +0.0},
        {+2.0, -1.0, +1.0},
        {+2.0, +0.0, +2.0},
        {+2.0, +1.0, +3.0},
        {+2.0, +2.0, +4.0},
        {+2.0, std::numeric_limits<Real::ValueType>::max(), Real::PositiveInfinity()},
        {+2.0, Real::PositiveInfinity(), Real::PositiveInfinity()},

        {std::numeric_limits<Real::ValueType>::max(), Real::Undefined(), Real::Undefined()},
        {std::numeric_limits<Real::ValueType>::max(), Real::NegativeInfinity(), Real::NegativeInfinity()},
        {std::numeric_limits<Real::ValueType>::max(), std::numeric_limits<Real::ValueType>::min(), std::numeric_limits<Real::ValueType>::max() + std::numeric_limits<Real::ValueType>::min()},
        {std::numeric_limits<Real::ValueType>::max(), -2.0, std::numeric_limits<Real::ValueType>::max() - 2},
        {std::numeric_limits<Real::ValueType>::max(), -1.0, std::numeric_limits<Real::ValueType>::max() - 1},
        {std::numeric_limits<Real::ValueType>::max(), +0.0, std::numeric_limits<Real::ValueType>::max()},
        {std::numeric_limits<Real::ValueType>::max(), +1.0, Real::PositiveInfinity()},
        {std::numeric_limits<Real::ValueType>::max(), +2.0, Real::PositiveInfinity()},
        {std::numeric_limits<Real::ValueType>::max(), std::numeric_limits<Real::ValueType>::max(), Real::PositiveInfinity()},
        {std::numeric_limits<Real::ValueType>::max(), Real::PositiveInfinity(), Real::PositiveInfinity()},

        {Real::PositiveInfinity(), Real::Undefined(), Real::Undefined()},
        {Real::PositiveInfinity(), Real::NegativeInfinity(), Real::Undefined()},
        {Real::PositiveInfinity(), std::numeric_limits<Real::ValueType>::min(), Real::PositiveInfinity()},
        {Real::PositiveInfinity(), -2.0, Real::PositiveInfinity()},
        {Real::PositiveInfinity(), -1.0, Real::PositiveInfinity()},
        {Real::PositiveInfinity(), +0.0, Real::PositiveInfinity()},
        {Real::PositiveInfinity(), +1.0, Real::PositiveInfinity()},
        {Real::PositiveInfinity(), +2.0, Real::PositiveInfinity()},
        {Real::PositiveInfinity(), std::numeric_limits<Real::ValueType>::max(), Real::PositiveInfinity()},
        {Real::PositiveInfinity(), Real::PositiveInfinity(), Real::PositiveInfinity()}

    } ;

    for (const auto& testCase : testCases)
    {

        const Real& a = testCase.first ;
        const Real& b = testCase.second ;
        const Real& c = testCase.third ;

        if (c.isDefined())
        {

            if (c.isPositiveInfinity())
            {
                EXPECT_TRUE((a + b).isPositiveInfinity()) ;
            }
            else if (c.isNegativeInfinity())
            {
                EXPECT_TRUE((a + b).isNegativeInfinity()) ;
            }
            else
            {
                EXPECT_EQ(c, a + b) ;
            }

        }
        else
        {
            EXPECT_FALSE((a + b).isDefined()) ;
        }

    }

}

TEST(Spacer_Core_Types_Real, SubtractionOperator)
{

    using spacer::core::types::Real ;
    using spacer::core::ctnr::Triple ;
    using spacer::core::ctnr::Array ;

    Array<Triple<Real, Real, Real>> testCases =
    {

        {Real::Undefined(), Real::Undefined(), Real::Undefined()},
        {Real::Undefined(), Real::NegativeInfinity(), Real::Undefined()},
        {Real::Undefined(), std::numeric_limits<Real::ValueType>::min(), Real::Undefined()},
        {Real::Undefined(), -2.0, Real::Undefined()},
        {Real::Undefined(), -1.0, Real::Undefined()},
        {Real::Undefined(), +0.0, Real::Undefined()},
        {Real::Undefined(), +1.0, Real::Undefined()},
        {Real::Undefined(), +2.0, Real::Undefined()},
        {Real::Undefined(), std::numeric_limits<Real::ValueType>::max(), Real::Undefined()},
        {Real::Undefined(), Real::PositiveInfinity(), Real::Undefined()},

        {Real::NegativeInfinity(), Real::Undefined(), Real::Undefined()},
        {Real::NegativeInfinity(), Real::NegativeInfinity(), Real::Undefined()},
        {Real::NegativeInfinity(), std::numeric_limits<Real::ValueType>::min(), Real::NegativeInfinity()},
        {Real::NegativeInfinity(), -2.0, Real::NegativeInfinity()},
        {Real::NegativeInfinity(), -1.0, Real::NegativeInfinity()},
        {Real::NegativeInfinity(), +0.0, Real::NegativeInfinity()},
        {Real::NegativeInfinity(), +1.0, Real::NegativeInfinity()},
        {Real::NegativeInfinity(), +2.0, Real::NegativeInfinity()},
        {Real::NegativeInfinity(), std::numeric_limits<Real::ValueType>::max(), Real::NegativeInfinity()},
        {Real::NegativeInfinity(), Real::PositiveInfinity(), Real::NegativeInfinity()},

        {std::numeric_limits<Real::ValueType>::min(), Real::Undefined(), Real::Undefined()},
        {std::numeric_limits<Real::ValueType>::min(), Real::NegativeInfinity(), Real::PositiveInfinity()},
        {std::numeric_limits<Real::ValueType>::min(), std::numeric_limits<Real::ValueType>::min(), +0.0},
        {std::numeric_limits<Real::ValueType>::min(), -2.0, std::numeric_limits<Real::ValueType>::min() + 2},
        {std::numeric_limits<Real::ValueType>::min(), -1.0, std::numeric_limits<Real::ValueType>::min() + 1},
        {std::numeric_limits<Real::ValueType>::min(), +0.0, std::numeric_limits<Real::ValueType>::min()},
        {std::numeric_limits<Real::ValueType>::min(), +1.0, Real::NegativeInfinity()},
        {std::numeric_limits<Real::ValueType>::min(), +2.0, Real::NegativeInfinity()},
        {std::numeric_limits<Real::ValueType>::min(), std::numeric_limits<Real::ValueType>::max(), Real::NegativeInfinity()},
        {std::numeric_limits<Real::ValueType>::min(), Real::PositiveInfinity(), Real::NegativeInfinity()},

        {-2.0, Real::Undefined(), Real::Undefined()},
        {-2.0, Real::NegativeInfinity(), Real::PositiveInfinity()},
        {-2.0, std::numeric_limits<Real::ValueType>::min(), -2 - std::numeric_limits<Real::ValueType>::min()},
        {-2.0, -2.0, +0.0},
        {-2.0, -1.0, -1.0},
        {-2.0, +0.0, -2.0},
        {-2.0, +1.0, -3.0},
        {-2.0, +2.0, -4.0},
        {-2.0, std::numeric_limits<Real::ValueType>::max(), Real::NegativeInfinity()},
        {-2.0, Real::PositiveInfinity(), Real::NegativeInfinity()},

        {-1.0, Real::Undefined(), Real::Undefined()},
        {-1.0, Real::NegativeInfinity(), Real::PositiveInfinity()},
        {-1.0, std::numeric_limits<Real::ValueType>::min(), std::numeric_limits<Real::ValueType>::max()},
        {-1.0, -2.0, +1.0},
        {-1.0, -1.0, +0.0},
        {-1.0, +0.0, -1.0},
        {-1.0, +1.0, -2.0},
        {-1.0, +2.0, -3.0},
        {-1.0, std::numeric_limits<Real::ValueType>::max(), std::numeric_limits<Real::ValueType>::min()},
        {-1.0, Real::PositiveInfinity(), Real::NegativeInfinity()},

        {+0.0, Real::Undefined(), Real::Undefined()},
        {+0.0, Real::NegativeInfinity(), Real::PositiveInfinity()},
        {+0.0, std::numeric_limits<Real::ValueType>::min(), Real::PositiveInfinity()},
        {+0.0, -2.0, +2.0},
        {+0.0, -1.0, +1.0},
        {+0.0, +0.0, +0.0},
        {+0.0, +1.0, -1.0},
        {+0.0, +2.0, -2.0},
        {+0.0, std::numeric_limits<Real::ValueType>::max(), std::numeric_limits<Real::ValueType>::min() + 1},
        {+0.0, Real::PositiveInfinity(), Real::NegativeInfinity()},

        {+1.0, Real::Undefined(), Real::Undefined()},
        {+1.0, Real::NegativeInfinity(), Real::PositiveInfinity()},
        {+1.0, std::numeric_limits<Real::ValueType>::min(), Real::PositiveInfinity()},
        {+1.0, -2.0, +3.0},
        {+1.0, -1.0, +2.0},
        {+1.0, +0.0, +1.0},
        {+1.0, +1.0, +0.0},
        {+1.0, +2.0, -1.0},
        {+1.0, std::numeric_limits<Real::ValueType>::max(), std::numeric_limits<Real::ValueType>::min() + 2},
        {+1.0, Real::PositiveInfinity(), Real::NegativeInfinity()},
        
        {+2.0, Real::Undefined(), Real::Undefined()},
        {+2.0, Real::NegativeInfinity(), Real::PositiveInfinity()},
        {+2.0, std::numeric_limits<Real::ValueType>::min(), Real::PositiveInfinity()},
        {+2.0, -2.0, +4.0},
        {+2.0, -1.0, +3.0},
        {+2.0, +0.0, +2.0},
        {+2.0, +1.0, +1.0},
        {+2.0, +2.0, +0.0},
        {+2.0, std::numeric_limits<Real::ValueType>::max(), std::numeric_limits<Real::ValueType>::min() + 3},
        {+2.0, Real::PositiveInfinity(), Real::NegativeInfinity()},

        {std::numeric_limits<Real::ValueType>::max(), Real::Undefined(), Real::Undefined()},
        {std::numeric_limits<Real::ValueType>::max(), Real::NegativeInfinity(), Real::PositiveInfinity()},
        {std::numeric_limits<Real::ValueType>::max(), std::numeric_limits<Real::ValueType>::min(), Real::PositiveInfinity()},
        {std::numeric_limits<Real::ValueType>::max(), -2.0, Real::PositiveInfinity()},
        {std::numeric_limits<Real::ValueType>::max(), -1.0, Real::PositiveInfinity()},
        {std::numeric_limits<Real::ValueType>::max(), +0.0, std::numeric_limits<Real::ValueType>::max()},
        {std::numeric_limits<Real::ValueType>::max(), +1.0, std::numeric_limits<Real::ValueType>::max() - 1},
        {std::numeric_limits<Real::ValueType>::max(), +2.0, std::numeric_limits<Real::ValueType>::max() - 2},
        {std::numeric_limits<Real::ValueType>::max(), std::numeric_limits<Real::ValueType>::max(), +0.0},
        {std::numeric_limits<Real::ValueType>::max(), Real::PositiveInfinity(), Real::NegativeInfinity()},

        {Real::PositiveInfinity(), Real::Undefined(), Real::Undefined()},
        {Real::PositiveInfinity(), Real::NegativeInfinity(), Real::PositiveInfinity()},
        {Real::PositiveInfinity(), std::numeric_limits<Real::ValueType>::min(), Real::PositiveInfinity()},
        {Real::PositiveInfinity(), -2.0, Real::PositiveInfinity()},
        {Real::PositiveInfinity(), -1.0, Real::PositiveInfinity()},
        {Real::PositiveInfinity(), +0.0, Real::PositiveInfinity()},
        {Real::PositiveInfinity(), +1.0, Real::PositiveInfinity()},
        {Real::PositiveInfinity(), +2.0, Real::PositiveInfinity()},
        {Real::PositiveInfinity(), std::numeric_limits<Real::ValueType>::max(), Real::PositiveInfinity()},
        {Real::PositiveInfinity(), Real::PositiveInfinity(), Real::Undefined()}

    } ;

    for (const auto& testCase : testCases)
    {

        const Real& a = testCase.first ;
        const Real& b = testCase.second ;
        const Real& c = testCase.third ;
        
        if (c.isDefined())
        {

            if (c.isPositiveInfinity())
            {
                EXPECT_TRUE((a - b).isPositiveInfinity()) ;
            }
            else if (c.isNegativeInfinity())
            {
                EXPECT_TRUE((a - b).isNegativeInfinity()) ;
            }
            else
            {
                EXPECT_EQ(c, a - b) ;
            }

        }
        else
        {
            EXPECT_FALSE((a - b).isDefined()) ;
        }

    }

}

TEST(Spacer_Core_Types_Real, MultiplicationOperator)
{

    using spacer::core::types::Real ;
    using spacer::core::ctnr::Triple ;
    using spacer::core::ctnr::Array ;

    Array<Triple<Real, Real, Real>> testCases =
    {

        {Real::Undefined(), Real::Undefined(), Real::Undefined()},
        {Real::Undefined(), Real::NegativeInfinity(), Real::Undefined()},
        {Real::Undefined(), std::numeric_limits<Real::ValueType>::min(), Real::Undefined()},
        {Real::Undefined(), -2.0, Real::Undefined()},
        {Real::Undefined(), -1.0, Real::Undefined()},
        {Real::Undefined(), +0.0, Real::Undefined()},
        {Real::Undefined(), +1.0, Real::Undefined()},
        {Real::Undefined(), +2.0, Real::Undefined()},
        {Real::Undefined(), std::numeric_limits<Real::ValueType>::max(), Real::Undefined()},
        {Real::Undefined(), Real::PositiveInfinity(), Real::Undefined()},

        {Real::NegativeInfinity(), Real::Undefined(), Real::Undefined()},
        {Real::NegativeInfinity(), Real::NegativeInfinity(), Real::PositiveInfinity()},
        {Real::NegativeInfinity(), std::numeric_limits<Real::ValueType>::min(), Real::PositiveInfinity()},
        {Real::NegativeInfinity(), -2.0, Real::PositiveInfinity()},
        {Real::NegativeInfinity(), -1.0, Real::PositiveInfinity()},
        {Real::NegativeInfinity(), +0.0, Real::Undefined()},
        {Real::NegativeInfinity(), +1.0, Real::NegativeInfinity()},
        {Real::NegativeInfinity(), +2.0, Real::NegativeInfinity()},
        {Real::NegativeInfinity(), std::numeric_limits<Real::ValueType>::max(), Real::NegativeInfinity()},
        {Real::NegativeInfinity(), Real::PositiveInfinity(), Real::NegativeInfinity()},

        {std::numeric_limits<Real::ValueType>::min(), Real::Undefined(), Real::Undefined()},
        {std::numeric_limits<Real::ValueType>::min(), Real::NegativeInfinity(), Real::PositiveInfinity()},
        {std::numeric_limits<Real::ValueType>::min(), std::numeric_limits<Real::ValueType>::min(), Real::PositiveInfinity()},
        {std::numeric_limits<Real::ValueType>::min(), -2.0, Real::PositiveInfinity()},
        {std::numeric_limits<Real::ValueType>::min(), -1.0, Real::PositiveInfinity()},
        {std::numeric_limits<Real::ValueType>::min(), +0.0, +0.0},
        {std::numeric_limits<Real::ValueType>::min(), +1.0, std::numeric_limits<Real::ValueType>::min()},
        {std::numeric_limits<Real::ValueType>::min(), +2.0, Real::NegativeInfinity()},
        {std::numeric_limits<Real::ValueType>::min(), std::numeric_limits<Real::ValueType>::max(), Real::NegativeInfinity()},
        {std::numeric_limits<Real::ValueType>::min(), Real::PositiveInfinity(), Real::NegativeInfinity()},

        {-1073741823, Real::Undefined(), Real::Undefined()},
        {-1073741823, Real::NegativeInfinity(), Real::PositiveInfinity()},
        {-1073741823, std::numeric_limits<Real::ValueType>::min(), Real::PositiveInfinity()},
        {-1073741823, -3.0, Real::PositiveInfinity()},
        {-1073741823, -2.0, +2147483646},
        {-1073741823, -1.0, +1073741823},
        {-1073741823, +0.0, +0.0},
        {-1073741823, +1.0, -1073741823},
        {-1073741823, +2.0, -2147483646},
        {-1073741823, +3.0, Real::NegativeInfinity()},
        {-1073741823, std::numeric_limits<Real::ValueType>::max(), Real::NegativeInfinity()},
        {-1073741823, Real::PositiveInfinity(), Real::NegativeInfinity()},

        {-2.0, Real::Undefined(), Real::Undefined()},
        {-2.0, Real::NegativeInfinity(), Real::PositiveInfinity()},
        {-2.0, std::numeric_limits<Real::ValueType>::min(), Real::PositiveInfinity()},
        {-2.0, -2.0, +4.0},
        {-2.0, -1.0, +2.0},
        {-2.0, +0.0, +0.0},
        {-2.0, +1.0, -2.0},
        {-2.0, +2.0, -4.0},
        {-2.0, std::numeric_limits<Real::ValueType>::max(), Real::NegativeInfinity()},
        {-2.0, Real::PositiveInfinity(), Real::NegativeInfinity()},
        
        {-1.0, Real::Undefined(), Real::Undefined()},
        {-1.0, Real::NegativeInfinity(), Real::PositiveInfinity()},
        {-1.0, std::numeric_limits<Real::ValueType>::min(), Real::PositiveInfinity()},
        {-1.0, -2.0, +2.0},
        {-1.0, -1.0, +1.0},
        {-1.0, +0.0, +0.0},
        {-1.0, +1.0, -1.0},
        {-1.0, +2.0, -2.0},
        {-1.0, std::numeric_limits<Real::ValueType>::max(), -std::numeric_limits<Real::ValueType>::max()},
        {-1.0, Real::PositiveInfinity(), Real::NegativeInfinity()},

        {+0.0, Real::Undefined(), Real::Undefined()},
        {+0.0, Real::NegativeInfinity(), Real::Undefined()},
        {+0.0, std::numeric_limits<Real::ValueType>::min(), +0.0},
        {+0.0, -2.0, +0.0},
        {+0.0, -1.0, +0.0},
        {+0.0, +0.0, +0.0},
        {+0.0, +1.0, +0.0},
        {+0.0, +2.0, +0.0},
        {+0.0, std::numeric_limits<Real::ValueType>::max(), +0.0},
        {+0.0, Real::PositiveInfinity(), Real::Undefined()},

        {+1.0, Real::Undefined(), Real::Undefined()},
        {+1.0, Real::NegativeInfinity(), Real::NegativeInfinity()},
        {+1.0, std::numeric_limits<Real::ValueType>::min(), std::numeric_limits<Real::ValueType>::min()},
        {+1.0, -2.0, -2.0},
        {+1.0, -1.0, -1.0},
        {+1.0, +0.0, +0.0},
        {+1.0, +1.0, +1.0},
        {+1.0, +2.0, +2.0},
        {+1.0, std::numeric_limits<Real::ValueType>::max(), std::numeric_limits<Real::ValueType>::max()},
        {+1.0, Real::PositiveInfinity(), Real::PositiveInfinity()},

        {+2.0, Real::Undefined(), Real::Undefined()},
        {+2.0, Real::NegativeInfinity(), Real::NegativeInfinity()},
        {+2.0, std::numeric_limits<Real::ValueType>::min(), Real::NegativeInfinity()},
        {+2.0, -2.0, -4.0},
        {+2.0, -1.0, -2.0},
        {+2.0, +0.0, +0.0},
        {+2.0, +1.0, +2.0},
        {+2.0, +2.0, +4.0},
        {+2.0, std::numeric_limits<Real::ValueType>::max(), Real::PositiveInfinity()},
        {+2.0, Real::PositiveInfinity(), Real::PositiveInfinity()},

        {+1073741823, Real::Undefined(), Real::Undefined()},
        {+1073741823, Real::NegativeInfinity(), Real::NegativeInfinity()},
        {+1073741823, std::numeric_limits<Real::ValueType>::min(), Real::NegativeInfinity()},
        {+1073741823, -3.0, Real::NegativeInfinity()},
        {+1073741823, -2.0, -2147483646},
        {+1073741823, -1.0, -1073741823},
        {+1073741823, +0.0, +0.0},
        {+1073741823, +1.0, +1073741823},
        {+1073741823, +2.0, +2147483646},
        {+1073741823, +3.0, Real::PositiveInfinity()},
        {+1073741823, std::numeric_limits<Real::ValueType>::max(), Real::PositiveInfinity()},
        {+1073741823, Real::PositiveInfinity(), Real::PositiveInfinity()},

        {std::numeric_limits<Real::ValueType>::max(), Real::Undefined(), Real::Undefined()},
        {std::numeric_limits<Real::ValueType>::max(), Real::NegativeInfinity(), Real::NegativeInfinity()},
        {std::numeric_limits<Real::ValueType>::max(), std::numeric_limits<Real::ValueType>::min(), Real::NegativeInfinity()},
        {std::numeric_limits<Real::ValueType>::max(), -2.0, Real::NegativeInfinity()},
        {std::numeric_limits<Real::ValueType>::max(), -1.0, -std::numeric_limits<Real::ValueType>::max()},
        {std::numeric_limits<Real::ValueType>::max(), +0.0, +0.0},
        {std::numeric_limits<Real::ValueType>::max(), +1.0, std::numeric_limits<Real::ValueType>::max()},
        {std::numeric_limits<Real::ValueType>::max(), +2.0, Real::PositiveInfinity()},
        {std::numeric_limits<Real::ValueType>::max(), std::numeric_limits<Real::ValueType>::max(), Real::PositiveInfinity()},
        {std::numeric_limits<Real::ValueType>::max(), Real::PositiveInfinity(), Real::PositiveInfinity()},

        {Real::PositiveInfinity(), Real::Undefined(), Real::Undefined()},
        {Real::PositiveInfinity(), Real::NegativeInfinity(), Real::NegativeInfinity()},
        {Real::PositiveInfinity(), std::numeric_limits<Real::ValueType>::min(), Real::NegativeInfinity()},
        {Real::PositiveInfinity(), -2.0, Real::NegativeInfinity()},
        {Real::PositiveInfinity(), -1.0, Real::NegativeInfinity()},
        {Real::PositiveInfinity(), +0.0, Real::Undefined()},
        {Real::PositiveInfinity(), +1.0, Real::PositiveInfinity()},
        {Real::PositiveInfinity(), +2.0, Real::PositiveInfinity()},
        {Real::PositiveInfinity(), std::numeric_limits<Real::ValueType>::max(), Real::PositiveInfinity()},
        {Real::PositiveInfinity(), Real::PositiveInfinity(), Real::PositiveInfinity()}

    } ;

    for (const auto& testCase : testCases)
    {

        const Real& a = testCase.first ;
        const Real& b = testCase.second ;
        const Real& c = testCase.third ;
        
        if (c.isDefined())
        {

            if (c.isPositiveInfinity())
            {
                EXPECT_TRUE((a * b).isPositiveInfinity()) ;
            }
            else if (c.isNegativeInfinity())
            {
                EXPECT_TRUE((a * b).isNegativeInfinity()) ;
            }
            else
            {
                EXPECT_EQ(c, a * b) ;
            }

        }
        else
        {
            EXPECT_FALSE((a * b).isDefined()) ;
        }

    }

}

TEST(Spacer_Core_Types_Real, DivisionOperator)
{

    using spacer::core::types::Real ;
    using spacer::core::ctnr::Triple ;
    using spacer::core::ctnr::Array ;

    Array<Triple<Real, Real, Real>> testCases =
    {

        {Real::Undefined(), Real::Undefined(), Real::Undefined()},
        {Real::Undefined(), Real::NegativeInfinity(), Real::Undefined()},
        {Real::Undefined(), std::numeric_limits<Real::ValueType>::min(), Real::Undefined()},
        {Real::Undefined(), -2.0, Real::Undefined()},
        {Real::Undefined(), -1.0, Real::Undefined()},
        {Real::Undefined(), +0.0, Real::Undefined()},
        {Real::Undefined(), +1.0, Real::Undefined()},
        {Real::Undefined(), +2.0, Real::Undefined()},
        {Real::Undefined(), std::numeric_limits<Real::ValueType>::max(), Real::Undefined()},
        {Real::Undefined(), Real::PositiveInfinity(), Real::Undefined()},

        {Real::NegativeInfinity(), Real::Undefined(), Real::Undefined()},
        {Real::NegativeInfinity(), Real::NegativeInfinity(), Real::Undefined()},
        {Real::NegativeInfinity(), std::numeric_limits<Real::ValueType>::min(), Real::PositiveInfinity()},
        {Real::NegativeInfinity(), -2.0, Real::PositiveInfinity()},
        {Real::NegativeInfinity(), -1.0, Real::PositiveInfinity()},
        {Real::NegativeInfinity(), +0.0, Real::Undefined()},
        {Real::NegativeInfinity(), +1.0, Real::NegativeInfinity()},
        {Real::NegativeInfinity(), +2.0, Real::NegativeInfinity()},
        {Real::NegativeInfinity(), std::numeric_limits<Real::ValueType>::max(), Real::NegativeInfinity()},
        {Real::NegativeInfinity(), Real::PositiveInfinity(), Real::Undefined()},

        {std::numeric_limits<Real::ValueType>::min(), Real::Undefined(), Real::Undefined()},
        {std::numeric_limits<Real::ValueType>::min(), Real::NegativeInfinity(), +0.0},
        {std::numeric_limits<Real::ValueType>::min(), std::numeric_limits<Real::ValueType>::min(), 1},
        {std::numeric_limits<Real::ValueType>::min(), -2.0, std::numeric_limits<Real::ValueType>::min() / -2.0},
        {std::numeric_limits<Real::ValueType>::min(), -1.0, Real::PositiveInfinity()},
        {std::numeric_limits<Real::ValueType>::min(), +0.0, Real::Undefined()},
        {std::numeric_limits<Real::ValueType>::min(), +1.0, std::numeric_limits<Real::ValueType>::min()},
        {std::numeric_limits<Real::ValueType>::min(), +2.0, std::numeric_limits<Real::ValueType>::min() / 2},
        {std::numeric_limits<Real::ValueType>::min(), std::numeric_limits<Real::ValueType>::max(), -1.0},
        {std::numeric_limits<Real::ValueType>::min(), Real::PositiveInfinity(), +0.0},

        {-2.0, Real::Undefined(), Real::Undefined()},
        {-2.0, Real::NegativeInfinity(), +0.0},
        {-2.0, std::numeric_limits<Real::ValueType>::min(), +0.0},
        {-2.0, -2.0, +1.0},
        {-2.0, -1.0, +2.0},
        {-2.0, +0.0, Real::Undefined()},
        {-2.0, +1.0, -2.0},
        {-2.0, +2.0, -1.0},
        {-2.0, std::numeric_limits<Real::ValueType>::max(), +0.0},
        {-2.0, Real::PositiveInfinity(), +0.0},
        
        {-1.0, Real::Undefined(), Real::Undefined()},
        {-1.0, Real::NegativeInfinity(), +0.0},
        {-1.0, std::numeric_limits<Real::ValueType>::min(), +0.0},
        {-1.0, -2.0, +0.0},
        {-1.0, -1.0, +1.0},
        {-1.0, +0.0, Real::Undefined()},
        {-1.0, +1.0, -1.0},
        {-1.0, +2.0, +0.0},
        {-1.0, std::numeric_limits<Real::ValueType>::max(), +0.0},
        {-1.0, Real::PositiveInfinity(), +0.0},

        {+0.0, Real::Undefined(), Real::Undefined()},
        {+0.0, Real::NegativeInfinity(), +0.0},
        {+0.0, std::numeric_limits<Real::ValueType>::min(), +0.0},
        {+0.0, -2.0, +0.0},
        {+0.0, -1.0, +0.0},
        {+0.0, +0.0, Real::Undefined()},
        {+0.0, +1.0, +0.0},
        {+0.0, +2.0, +0.0},
        {+0.0, std::numeric_limits<Real::ValueType>::max(), +0.0},
        {+0.0, Real::PositiveInfinity(), +0.0},

        {+1.0, Real::Undefined(), Real::Undefined()},
        {+1.0, Real::NegativeInfinity(), +0.0},
        {+1.0, std::numeric_limits<Real::ValueType>::min(), +0.0},
        {+1.0, -2.0, +0.0},
        {+1.0, -1.0, -1.0},
        {+1.0, +0.0, Real::Undefined()},
        {+1.0, +1.0, +1.0},
        {+1.0, +2.0, +0.0},
        {+1.0, std::numeric_limits<Real::ValueType>::max(), +0.0},
        {+1.0, Real::PositiveInfinity(), +0.0},

        {+2.0, Real::Undefined(), Real::Undefined()},
        {+2.0, Real::NegativeInfinity(), +0.0},
        {+2.0, std::numeric_limits<Real::ValueType>::min(), +0.0},
        {+2.0, -2.0, -1.0},
        {+2.0, -1.0, -2.0},
        {+2.0, +0.0, Real::Undefined()},
        {+2.0, +1.0, +2.0},
        {+2.0, +2.0, +1.0},
        {+2.0, std::numeric_limits<Real::ValueType>::max(), +0.0},
        {+2.0, Real::PositiveInfinity(), +0.0},

        {std::numeric_limits<Real::ValueType>::max(), Real::Undefined(), Real::Undefined()},
        {std::numeric_limits<Real::ValueType>::max(), Real::NegativeInfinity(), +0.0},
        {std::numeric_limits<Real::ValueType>::max(), std::numeric_limits<Real::ValueType>::min(), +0.0},
        {std::numeric_limits<Real::ValueType>::max(), -2.0, std::numeric_limits<Real::ValueType>::max() / -2.0},
        {std::numeric_limits<Real::ValueType>::max(), -1.0, std::numeric_limits<Real::ValueType>::max() / -1.0},
        {std::numeric_limits<Real::ValueType>::max(), +0.0, Real::Undefined()},
        {std::numeric_limits<Real::ValueType>::max(), +1.0, std::numeric_limits<Real::ValueType>::max()},
        {std::numeric_limits<Real::ValueType>::max(), +2.0, std::numeric_limits<Real::ValueType>::max() / 2},
        {std::numeric_limits<Real::ValueType>::max(), std::numeric_limits<Real::ValueType>::max(), +1.0},
        {std::numeric_limits<Real::ValueType>::max(), Real::PositiveInfinity(), +0.0},

        {Real::PositiveInfinity(), Real::Undefined(), Real::Undefined()},
        {Real::PositiveInfinity(), Real::NegativeInfinity(), Real::Undefined()},
        {Real::PositiveInfinity(), std::numeric_limits<Real::ValueType>::min(), Real::NegativeInfinity()},
        {Real::PositiveInfinity(), -2.0, Real::NegativeInfinity()},
        {Real::PositiveInfinity(), -1.0, Real::NegativeInfinity()},
        {Real::PositiveInfinity(), +0.0, Real::Undefined()},
        {Real::PositiveInfinity(), +1.0, Real::PositiveInfinity()},
        {Real::PositiveInfinity(), +2.0, Real::PositiveInfinity()},
        {Real::PositiveInfinity(), std::numeric_limits<Real::ValueType>::max(), Real::PositiveInfinity()},
        {Real::PositiveInfinity(), Real::PositiveInfinity(), Real::Undefined()}

    } ;

    for (const auto& testCase : testCases)
    {

        const Real& a = testCase.first ;
        const Real& b = testCase.second ;
        const Real& c = testCase.third ;
        
        if (c.isDefined())
        {

            if (c.isPositiveInfinity())
            {
                EXPECT_TRUE((a / b).isPositiveInfinity()) ;
            }
            else if (c.isNegativeInfinity())
            {
                EXPECT_TRUE((a / b).isNegativeInfinity()) ;
            }
            else
            {
                EXPECT_EQ(c, a / b) ;
            }

        }
        else
        {
            EXPECT_FALSE((a / b).isDefined()) ;
        }

    }

}

TEST(Spacer_Core_Types_Real, AdditionAssignmentOperator)
{

    using spacer::core::types::Real ;
    using spacer::core::ctnr::Triple ;
    using spacer::core::ctnr::Array ;

    Array<Triple<Real, Real, Real>> testCases =
    {

        {Real::Undefined(), Real::Undefined(), Real::Undefined()},
        {Real::Undefined(), Real::NegativeInfinity(), Real::Undefined()},
        {Real::Undefined(), std::numeric_limits<Real::ValueType>::min(), Real::Undefined()},
        {Real::Undefined(), -2.0, Real::Undefined()},
        {Real::Undefined(), -1.0, Real::Undefined()},
        {Real::Undefined(), +0.0, Real::Undefined()},
        {Real::Undefined(), +1.0, Real::Undefined()},
        {Real::Undefined(), +2.0, Real::Undefined()},
        {Real::Undefined(), std::numeric_limits<Real::ValueType>::max(), Real::Undefined()},
        {Real::Undefined(), Real::PositiveInfinity(), Real::Undefined()},

        {Real::NegativeInfinity(), Real::Undefined(), Real::Undefined()},
        {Real::NegativeInfinity(), Real::NegativeInfinity(), Real::NegativeInfinity()},
        {Real::NegativeInfinity(), std::numeric_limits<Real::ValueType>::min(), Real::NegativeInfinity()},
        {Real::NegativeInfinity(), -2.0, Real::NegativeInfinity()},
        {Real::NegativeInfinity(), -1.0, Real::NegativeInfinity()},
        {Real::NegativeInfinity(), +0.0, Real::NegativeInfinity()},
        {Real::NegativeInfinity(), +1.0, Real::NegativeInfinity()},
        {Real::NegativeInfinity(), +2.0, Real::NegativeInfinity()},
        {Real::NegativeInfinity(), std::numeric_limits<Real::ValueType>::max(), Real::NegativeInfinity()},
        {Real::NegativeInfinity(), Real::PositiveInfinity(), Real::Undefined()},

        {std::numeric_limits<Real::ValueType>::min(), Real::Undefined(), Real::Undefined()},
        {std::numeric_limits<Real::ValueType>::min(), Real::NegativeInfinity(), Real::NegativeInfinity()},
        {std::numeric_limits<Real::ValueType>::min(), std::numeric_limits<Real::ValueType>::min(), Real::NegativeInfinity()},
        {std::numeric_limits<Real::ValueType>::min(), -2.0, Real::NegativeInfinity()},
        {std::numeric_limits<Real::ValueType>::min(), -1.0, Real::NegativeInfinity()},
        {std::numeric_limits<Real::ValueType>::min(), +0.0, std::numeric_limits<Real::ValueType>::min()},
        {std::numeric_limits<Real::ValueType>::min(), +1.0, std::numeric_limits<Real::ValueType>::min() + 1},
        {std::numeric_limits<Real::ValueType>::min(), +2.0, std::numeric_limits<Real::ValueType>::min() + 2},
        {std::numeric_limits<Real::ValueType>::min(), std::numeric_limits<Real::ValueType>::max(), std::numeric_limits<Real::ValueType>::min() + std::numeric_limits<Real::ValueType>::max()},
        {std::numeric_limits<Real::ValueType>::min(), Real::PositiveInfinity(), Real::PositiveInfinity()},

        {-2.0, Real::Undefined(), Real::Undefined()},
        {-2.0, Real::NegativeInfinity(), Real::NegativeInfinity()},
        {-2.0, std::numeric_limits<Real::ValueType>::min(), Real::NegativeInfinity()},
        {-2.0, -2.0, -4.0},
        {-2.0, -1.0, -3.0},
        {-2.0, +0.0, -2.0},
        {-2.0, +1.0, -1.0},
        {-2.0, +2.0, +0.0},
        {-2.0, std::numeric_limits<Real::ValueType>::max(), std::numeric_limits<Real::ValueType>::max() - 2},
        {-2.0, Real::PositiveInfinity(), Real::PositiveInfinity()},

        {-1.0, Real::Undefined(), Real::Undefined()},
        {-1.0, Real::NegativeInfinity(), Real::NegativeInfinity()},
        {-1.0, std::numeric_limits<Real::ValueType>::min(), Real::NegativeInfinity()},
        {-1.0, -2.0, -3.0},
        {-1.0, -1.0, -2.0},
        {-1.0, +0.0, -1.0},
        {-1.0, +1.0, +0.0},
        {-1.0, +2.0, +1.0},
        {-1.0, std::numeric_limits<Real::ValueType>::max(), std::numeric_limits<Real::ValueType>::max() - 1},
        {-1.0, Real::PositiveInfinity(), Real::PositiveInfinity()},

        {+0.0, Real::Undefined(), Real::Undefined()},
        {+0.0, Real::NegativeInfinity(), Real::NegativeInfinity()},
        {+0.0, std::numeric_limits<Real::ValueType>::min(), std::numeric_limits<Real::ValueType>::min()},
        {+0.0, -2.0, -2.0},
        {+0.0, -1.0, -1.0},
        {+0.0, +0.0, +0.0},
        {+0.0, +1.0, +1.0},
        {+0.0, +2.0, +2.0},
        {+0.0, std::numeric_limits<Real::ValueType>::max(), std::numeric_limits<Real::ValueType>::max()},
        {+0.0, Real::PositiveInfinity(), Real::PositiveInfinity()},

        {+1.0, Real::Undefined(), Real::Undefined()},
        {+1.0, Real::NegativeInfinity(), Real::NegativeInfinity()},
        {+1.0, std::numeric_limits<Real::ValueType>::min(), std::numeric_limits<Real::ValueType>::min() + 1},
        {+1.0, -2.0, -1.0},
        {+1.0, -1.0, +0.0},
        {+1.0, +0.0, +1.0},
        {+1.0, +1.0, +2.0},
        {+1.0, +2.0, +3.0},
        {+1.0, std::numeric_limits<Real::ValueType>::max(), Real::PositiveInfinity()},
        {+1.0, Real::PositiveInfinity(), Real::PositiveInfinity()},
        
        {+2.0, Real::Undefined(), Real::Undefined()},
        {+2.0, Real::NegativeInfinity(), Real::NegativeInfinity()},
        {+2.0, std::numeric_limits<Real::ValueType>::min(), std::numeric_limits<Real::ValueType>::min() + 2},
        {+2.0, -2.0, +0.0},
        {+2.0, -1.0, +1.0},
        {+2.0, +0.0, +2.0},
        {+2.0, +1.0, +3.0},
        {+2.0, +2.0, +4.0},
        {+2.0, std::numeric_limits<Real::ValueType>::max(), Real::PositiveInfinity()},
        {+2.0, Real::PositiveInfinity(), Real::PositiveInfinity()},

        {std::numeric_limits<Real::ValueType>::max(), Real::Undefined(), Real::Undefined()},
        {std::numeric_limits<Real::ValueType>::max(), Real::NegativeInfinity(), Real::NegativeInfinity()},
        {std::numeric_limits<Real::ValueType>::max(), std::numeric_limits<Real::ValueType>::min(), std::numeric_limits<Real::ValueType>::max() + std::numeric_limits<Real::ValueType>::min()},
        {std::numeric_limits<Real::ValueType>::max(), -2.0, std::numeric_limits<Real::ValueType>::max() - 2},
        {std::numeric_limits<Real::ValueType>::max(), -1.0, std::numeric_limits<Real::ValueType>::max() - 1},
        {std::numeric_limits<Real::ValueType>::max(), +0.0, std::numeric_limits<Real::ValueType>::max()},
        {std::numeric_limits<Real::ValueType>::max(), +1.0, Real::PositiveInfinity()},
        {std::numeric_limits<Real::ValueType>::max(), +2.0, Real::PositiveInfinity()},
        {std::numeric_limits<Real::ValueType>::max(), std::numeric_limits<Real::ValueType>::max(), Real::PositiveInfinity()},
        {std::numeric_limits<Real::ValueType>::max(), Real::PositiveInfinity(), Real::PositiveInfinity()},

        {Real::PositiveInfinity(), Real::Undefined(), Real::Undefined()},
        {Real::PositiveInfinity(), Real::NegativeInfinity(), Real::Undefined()},
        {Real::PositiveInfinity(), std::numeric_limits<Real::ValueType>::min(), Real::PositiveInfinity()},
        {Real::PositiveInfinity(), -2.0, Real::PositiveInfinity()},
        {Real::PositiveInfinity(), -1.0, Real::PositiveInfinity()},
        {Real::PositiveInfinity(), +0.0, Real::PositiveInfinity()},
        {Real::PositiveInfinity(), +1.0, Real::PositiveInfinity()},
        {Real::PositiveInfinity(), +2.0, Real::PositiveInfinity()},
        {Real::PositiveInfinity(), std::numeric_limits<Real::ValueType>::max(), Real::PositiveInfinity()},
        {Real::PositiveInfinity(), Real::PositiveInfinity(), Real::PositiveInfinity()}

    } ;

    for (auto& testCase : testCases)
    {

        Real& a = testCase.first ;
        const Real& b = testCase.second ;
        const Real& c = testCase.third ;

        a += b ;

        if (c.isDefined())
        {

            if (c.isPositiveInfinity())
            {
                EXPECT_TRUE(a.isPositiveInfinity()) ;
            }
            else if (c.isNegativeInfinity())
            {
                EXPECT_TRUE(a.isNegativeInfinity()) ;
            }
            else
            {
                EXPECT_EQ(c, a) ;
            }

        }
        else
        {
            EXPECT_FALSE(a.isDefined()) ;
        }

    }

}

TEST(Spacer_Core_Types_Real, SubtractionAssignmentOperator)
{

    using spacer::core::types::Real ;
    using spacer::core::ctnr::Triple ;
    using spacer::core::ctnr::Array ;

    Array<Triple<Real, Real, Real>> testCases =
    {

        {Real::Undefined(), Real::Undefined(), Real::Undefined()},
        {Real::Undefined(), Real::NegativeInfinity(), Real::Undefined()},
        {Real::Undefined(), std::numeric_limits<Real::ValueType>::min(), Real::Undefined()},
        {Real::Undefined(), -2.0, Real::Undefined()},
        {Real::Undefined(), -1.0, Real::Undefined()},
        {Real::Undefined(), +0.0, Real::Undefined()},
        {Real::Undefined(), +1.0, Real::Undefined()},
        {Real::Undefined(), +2.0, Real::Undefined()},
        {Real::Undefined(), std::numeric_limits<Real::ValueType>::max(), Real::Undefined()},
        {Real::Undefined(), Real::PositiveInfinity(), Real::Undefined()},

        {Real::NegativeInfinity(), Real::Undefined(), Real::Undefined()},
        {Real::NegativeInfinity(), Real::NegativeInfinity(), Real::Undefined()},
        {Real::NegativeInfinity(), std::numeric_limits<Real::ValueType>::min(), Real::NegativeInfinity()},
        {Real::NegativeInfinity(), -2.0, Real::NegativeInfinity()},
        {Real::NegativeInfinity(), -1.0, Real::NegativeInfinity()},
        {Real::NegativeInfinity(), +0.0, Real::NegativeInfinity()},
        {Real::NegativeInfinity(), +1.0, Real::NegativeInfinity()},
        {Real::NegativeInfinity(), +2.0, Real::NegativeInfinity()},
        {Real::NegativeInfinity(), std::numeric_limits<Real::ValueType>::max(), Real::NegativeInfinity()},
        {Real::NegativeInfinity(), Real::PositiveInfinity(), Real::NegativeInfinity()},

        {std::numeric_limits<Real::ValueType>::min(), Real::Undefined(), Real::Undefined()},
        {std::numeric_limits<Real::ValueType>::min(), Real::NegativeInfinity(), Real::PositiveInfinity()},
        {std::numeric_limits<Real::ValueType>::min(), std::numeric_limits<Real::ValueType>::min(), +0.0},
        {std::numeric_limits<Real::ValueType>::min(), -2.0, std::numeric_limits<Real::ValueType>::min() + 2},
        {std::numeric_limits<Real::ValueType>::min(), -1.0, std::numeric_limits<Real::ValueType>::min() + 1},
        {std::numeric_limits<Real::ValueType>::min(), +0.0, std::numeric_limits<Real::ValueType>::min()},
        {std::numeric_limits<Real::ValueType>::min(), +1.0, Real::NegativeInfinity()},
        {std::numeric_limits<Real::ValueType>::min(), +2.0, Real::NegativeInfinity()},
        {std::numeric_limits<Real::ValueType>::min(), std::numeric_limits<Real::ValueType>::max(), Real::NegativeInfinity()},
        {std::numeric_limits<Real::ValueType>::min(), Real::PositiveInfinity(), Real::NegativeInfinity()},

        {-2.0, Real::Undefined(), Real::Undefined()},
        {-2.0, Real::NegativeInfinity(), Real::PositiveInfinity()},
        {-2.0, std::numeric_limits<Real::ValueType>::min(), -2 - std::numeric_limits<Real::ValueType>::min()},
        {-2.0, -2.0, +0.0},
        {-2.0, -1.0, -1.0},
        {-2.0, +0.0, -2.0},
        {-2.0, +1.0, -3.0},
        {-2.0, +2.0, -4.0},
        {-2.0, std::numeric_limits<Real::ValueType>::max(), Real::NegativeInfinity()},
        {-2.0, Real::PositiveInfinity(), Real::NegativeInfinity()},

        {-1.0, Real::Undefined(), Real::Undefined()},
        {-1.0, Real::NegativeInfinity(), Real::PositiveInfinity()},
        {-1.0, std::numeric_limits<Real::ValueType>::min(), std::numeric_limits<Real::ValueType>::max()},
        {-1.0, -2.0, +1.0},
        {-1.0, -1.0, +0.0},
        {-1.0, +0.0, -1.0},
        {-1.0, +1.0, -2.0},
        {-1.0, +2.0, -3.0},
        {-1.0, std::numeric_limits<Real::ValueType>::max(), std::numeric_limits<Real::ValueType>::min()},
        {-1.0, Real::PositiveInfinity(), Real::NegativeInfinity()},

        {+0.0, Real::Undefined(), Real::Undefined()},
        {+0.0, Real::NegativeInfinity(), Real::PositiveInfinity()},
        {+0.0, std::numeric_limits<Real::ValueType>::min(), Real::PositiveInfinity()},
        {+0.0, -2.0, +2.0},
        {+0.0, -1.0, +1.0},
        {+0.0, +0.0, +0.0},
        {+0.0, +1.0, -1.0},
        {+0.0, +2.0, -2.0},
        {+0.0, std::numeric_limits<Real::ValueType>::max(), std::numeric_limits<Real::ValueType>::min() + 1},
        {+0.0, Real::PositiveInfinity(), Real::NegativeInfinity()},

        {+1.0, Real::Undefined(), Real::Undefined()},
        {+1.0, Real::NegativeInfinity(), Real::PositiveInfinity()},
        {+1.0, std::numeric_limits<Real::ValueType>::min(), Real::PositiveInfinity()},
        {+1.0, -2.0, +3.0},
        {+1.0, -1.0, +2.0},
        {+1.0, +0.0, +1.0},
        {+1.0, +1.0, +0.0},
        {+1.0, +2.0, -1.0},
        {+1.0, std::numeric_limits<Real::ValueType>::max(), std::numeric_limits<Real::ValueType>::min() + 2},
        {+1.0, Real::PositiveInfinity(), Real::NegativeInfinity()},
        
        {+2.0, Real::Undefined(), Real::Undefined()},
        {+2.0, Real::NegativeInfinity(), Real::PositiveInfinity()},
        {+2.0, std::numeric_limits<Real::ValueType>::min(), Real::PositiveInfinity()},
        {+2.0, -2.0, +4.0},
        {+2.0, -1.0, +3.0},
        {+2.0, +0.0, +2.0},
        {+2.0, +1.0, +1.0},
        {+2.0, +2.0, +0.0},
        {+2.0, std::numeric_limits<Real::ValueType>::max(), std::numeric_limits<Real::ValueType>::min() + 3},
        {+2.0, Real::PositiveInfinity(), Real::NegativeInfinity()},

        {std::numeric_limits<Real::ValueType>::max(), Real::Undefined(), Real::Undefined()},
        {std::numeric_limits<Real::ValueType>::max(), Real::NegativeInfinity(), Real::PositiveInfinity()},
        {std::numeric_limits<Real::ValueType>::max(), std::numeric_limits<Real::ValueType>::min(), Real::PositiveInfinity()},
        {std::numeric_limits<Real::ValueType>::max(), -2.0, Real::PositiveInfinity()},
        {std::numeric_limits<Real::ValueType>::max(), -1.0, Real::PositiveInfinity()},
        {std::numeric_limits<Real::ValueType>::max(), +0.0, std::numeric_limits<Real::ValueType>::max()},
        {std::numeric_limits<Real::ValueType>::max(), +1.0, std::numeric_limits<Real::ValueType>::max() - 1},
        {std::numeric_limits<Real::ValueType>::max(), +2.0, std::numeric_limits<Real::ValueType>::max() - 2},
        {std::numeric_limits<Real::ValueType>::max(), std::numeric_limits<Real::ValueType>::max(), +0.0},
        {std::numeric_limits<Real::ValueType>::max(), Real::PositiveInfinity(), Real::NegativeInfinity()},

        {Real::PositiveInfinity(), Real::Undefined(), Real::Undefined()},
        {Real::PositiveInfinity(), Real::NegativeInfinity(), Real::PositiveInfinity()},
        {Real::PositiveInfinity(), std::numeric_limits<Real::ValueType>::min(), Real::PositiveInfinity()},
        {Real::PositiveInfinity(), -2.0, Real::PositiveInfinity()},
        {Real::PositiveInfinity(), -1.0, Real::PositiveInfinity()},
        {Real::PositiveInfinity(), +0.0, Real::PositiveInfinity()},
        {Real::PositiveInfinity(), +1.0, Real::PositiveInfinity()},
        {Real::PositiveInfinity(), +2.0, Real::PositiveInfinity()},
        {Real::PositiveInfinity(), std::numeric_limits<Real::ValueType>::max(), Real::PositiveInfinity()},
        {Real::PositiveInfinity(), Real::PositiveInfinity(), Real::Undefined()}

    } ;

    for (auto& testCase : testCases)
    {

        Real& a = testCase.first ;
        const Real& b = testCase.second ;
        const Real& c = testCase.third ;

        a -= b ;

        if (c.isDefined())
        {

            if (c.isPositiveInfinity())
            {
                EXPECT_TRUE(a.isPositiveInfinity()) ;
            }
            else if (c.isNegativeInfinity())
            {
                EXPECT_TRUE(a.isNegativeInfinity()) ;
            }
            else
            {
                EXPECT_EQ(c, a) ;
            }

        }
        else
        {
            EXPECT_FALSE(a.isDefined()) ;
        }

    }

}

TEST(Spacer_Core_Types_Real, MultiplicationAssignmentOperator)
{

    using spacer::core::types::Real ;
    using spacer::core::ctnr::Triple ;
    using spacer::core::ctnr::Array ;

    Array<Triple<Real, Real, Real>> testCases =
    {

        {Real::Undefined(), Real::Undefined(), Real::Undefined()},
        {Real::Undefined(), Real::NegativeInfinity(), Real::Undefined()},
        {Real::Undefined(), std::numeric_limits<Real::ValueType>::min(), Real::Undefined()},
        {Real::Undefined(), -2.0, Real::Undefined()},
        {Real::Undefined(), -1.0, Real::Undefined()},
        {Real::Undefined(), +0.0, Real::Undefined()},
        {Real::Undefined(), +1.0, Real::Undefined()},
        {Real::Undefined(), +2.0, Real::Undefined()},
        {Real::Undefined(), std::numeric_limits<Real::ValueType>::max(), Real::Undefined()},
        {Real::Undefined(), Real::PositiveInfinity(), Real::Undefined()},

        {Real::NegativeInfinity(), Real::Undefined(), Real::Undefined()},
        {Real::NegativeInfinity(), Real::NegativeInfinity(), Real::PositiveInfinity()},
        {Real::NegativeInfinity(), std::numeric_limits<Real::ValueType>::min(), Real::PositiveInfinity()},
        {Real::NegativeInfinity(), -2.0, Real::PositiveInfinity()},
        {Real::NegativeInfinity(), -1.0, Real::PositiveInfinity()},
        {Real::NegativeInfinity(), +0.0, Real::Undefined()},
        {Real::NegativeInfinity(), +1.0, Real::NegativeInfinity()},
        {Real::NegativeInfinity(), +2.0, Real::NegativeInfinity()},
        {Real::NegativeInfinity(), std::numeric_limits<Real::ValueType>::max(), Real::NegativeInfinity()},
        {Real::NegativeInfinity(), Real::PositiveInfinity(), Real::NegativeInfinity()},

        {std::numeric_limits<Real::ValueType>::min(), Real::Undefined(), Real::Undefined()},
        {std::numeric_limits<Real::ValueType>::min(), Real::NegativeInfinity(), Real::PositiveInfinity()},
        {std::numeric_limits<Real::ValueType>::min(), std::numeric_limits<Real::ValueType>::min(), Real::PositiveInfinity()},
        {std::numeric_limits<Real::ValueType>::min(), -2.0, Real::PositiveInfinity()},
        {std::numeric_limits<Real::ValueType>::min(), -1.0, Real::PositiveInfinity()},
        {std::numeric_limits<Real::ValueType>::min(), +0.0, +0.0},
        {std::numeric_limits<Real::ValueType>::min(), +1.0, std::numeric_limits<Real::ValueType>::min()},
        {std::numeric_limits<Real::ValueType>::min(), +2.0, Real::NegativeInfinity()},
        {std::numeric_limits<Real::ValueType>::min(), std::numeric_limits<Real::ValueType>::max(), Real::NegativeInfinity()},
        {std::numeric_limits<Real::ValueType>::min(), Real::PositiveInfinity(), Real::NegativeInfinity()},

        {-1073741823, Real::Undefined(), Real::Undefined()},
        {-1073741823, Real::NegativeInfinity(), Real::PositiveInfinity()},
        {-1073741823, std::numeric_limits<Real::ValueType>::min(), Real::PositiveInfinity()},
        {-1073741823, -3.0, Real::PositiveInfinity()},
        {-1073741823, -2.0, +2147483646},
        {-1073741823, -1.0, +1073741823},
        {-1073741823, +0.0, +0.0},
        {-1073741823, +1.0, -1073741823},
        {-1073741823, +2.0, -2147483646},
        {-1073741823, +3.0, Real::NegativeInfinity()},
        {-1073741823, std::numeric_limits<Real::ValueType>::max(), Real::NegativeInfinity()},
        {-1073741823, Real::PositiveInfinity(), Real::NegativeInfinity()},

        {-2.0, Real::Undefined(), Real::Undefined()},
        {-2.0, Real::NegativeInfinity(), Real::PositiveInfinity()},
        {-2.0, std::numeric_limits<Real::ValueType>::min(), Real::PositiveInfinity()},
        {-2.0, -2.0, +4.0},
        {-2.0, -1.0, +2.0},
        {-2.0, +0.0, +0.0},
        {-2.0, +1.0, -2.0},
        {-2.0, +2.0, -4.0},
        {-2.0, std::numeric_limits<Real::ValueType>::max(), Real::NegativeInfinity()},
        {-2.0, Real::PositiveInfinity(), Real::NegativeInfinity()},
        
        {-1.0, Real::Undefined(), Real::Undefined()},
        {-1.0, Real::NegativeInfinity(), Real::PositiveInfinity()},
        {-1.0, std::numeric_limits<Real::ValueType>::min(), Real::PositiveInfinity()},
        {-1.0, -2.0, +2.0},
        {-1.0, -1.0, +1.0},
        {-1.0, +0.0, +0.0},
        {-1.0, +1.0, -1.0},
        {-1.0, +2.0, -2.0},
        {-1.0, std::numeric_limits<Real::ValueType>::max(), -std::numeric_limits<Real::ValueType>::max()},
        {-1.0, Real::PositiveInfinity(), Real::NegativeInfinity()},

        {+0.0, Real::Undefined(), Real::Undefined()},
        {+0.0, Real::NegativeInfinity(), Real::Undefined()},
        {+0.0, std::numeric_limits<Real::ValueType>::min(), +0.0},
        {+0.0, -2.0, +0.0},
        {+0.0, -1.0, +0.0},
        {+0.0, +0.0, +0.0},
        {+0.0, +1.0, +0.0},
        {+0.0, +2.0, +0.0},
        {+0.0, std::numeric_limits<Real::ValueType>::max(), +0.0},
        {+0.0, Real::PositiveInfinity(), Real::Undefined()},

        {+1.0, Real::Undefined(), Real::Undefined()},
        {+1.0, Real::NegativeInfinity(), Real::NegativeInfinity()},
        {+1.0, std::numeric_limits<Real::ValueType>::min(), std::numeric_limits<Real::ValueType>::min()},
        {+1.0, -2.0, -2.0},
        {+1.0, -1.0, -1.0},
        {+1.0, +0.0, +0.0},
        {+1.0, +1.0, +1.0},
        {+1.0, +2.0, +2.0},
        {+1.0, std::numeric_limits<Real::ValueType>::max(), std::numeric_limits<Real::ValueType>::max()},
        {+1.0, Real::PositiveInfinity(), Real::PositiveInfinity()},

        {+2.0, Real::Undefined(), Real::Undefined()},
        {+2.0, Real::NegativeInfinity(), Real::NegativeInfinity()},
        {+2.0, std::numeric_limits<Real::ValueType>::min(), Real::NegativeInfinity()},
        {+2.0, -2.0, -4.0},
        {+2.0, -1.0, -2.0},
        {+2.0, +0.0, +0.0},
        {+2.0, +1.0, +2.0},
        {+2.0, +2.0, +4.0},
        {+2.0, std::numeric_limits<Real::ValueType>::max(), Real::PositiveInfinity()},
        {+2.0, Real::PositiveInfinity(), Real::PositiveInfinity()},

        {+1073741823, Real::Undefined(), Real::Undefined()},
        {+1073741823, Real::NegativeInfinity(), Real::NegativeInfinity()},
        {+1073741823, std::numeric_limits<Real::ValueType>::min(), Real::NegativeInfinity()},
        {+1073741823, -3.0, Real::NegativeInfinity()},
        {+1073741823, -2.0, -2147483646},
        {+1073741823, -1.0, -1073741823},
        {+1073741823, +0.0, +0.0},
        {+1073741823, +1.0, +1073741823},
        {+1073741823, +2.0, +2147483646},
        {+1073741823, +3.0, Real::PositiveInfinity()},
        {+1073741823, std::numeric_limits<Real::ValueType>::max(), Real::PositiveInfinity()},
        {+1073741823, Real::PositiveInfinity(), Real::PositiveInfinity()},

        {std::numeric_limits<Real::ValueType>::max(), Real::Undefined(), Real::Undefined()},
        {std::numeric_limits<Real::ValueType>::max(), Real::NegativeInfinity(), Real::NegativeInfinity()},
        {std::numeric_limits<Real::ValueType>::max(), std::numeric_limits<Real::ValueType>::min(), Real::NegativeInfinity()},
        {std::numeric_limits<Real::ValueType>::max(), -2.0, Real::NegativeInfinity()},
        {std::numeric_limits<Real::ValueType>::max(), -1.0, -std::numeric_limits<Real::ValueType>::max()},
        {std::numeric_limits<Real::ValueType>::max(), +0.0, +0.0},
        {std::numeric_limits<Real::ValueType>::max(), +1.0, std::numeric_limits<Real::ValueType>::max()},
        {std::numeric_limits<Real::ValueType>::max(), +2.0, Real::PositiveInfinity()},
        {std::numeric_limits<Real::ValueType>::max(), std::numeric_limits<Real::ValueType>::max(), Real::PositiveInfinity()},
        {std::numeric_limits<Real::ValueType>::max(), Real::PositiveInfinity(), Real::PositiveInfinity()},

        {Real::PositiveInfinity(), Real::Undefined(), Real::Undefined()},
        {Real::PositiveInfinity(), Real::NegativeInfinity(), Real::NegativeInfinity()},
        {Real::PositiveInfinity(), std::numeric_limits<Real::ValueType>::min(), Real::NegativeInfinity()},
        {Real::PositiveInfinity(), -2.0, Real::NegativeInfinity()},
        {Real::PositiveInfinity(), -1.0, Real::NegativeInfinity()},
        {Real::PositiveInfinity(), +0.0, Real::Undefined()},
        {Real::PositiveInfinity(), +1.0, Real::PositiveInfinity()},
        {Real::PositiveInfinity(), +2.0, Real::PositiveInfinity()},
        {Real::PositiveInfinity(), std::numeric_limits<Real::ValueType>::max(), Real::PositiveInfinity()},
        {Real::PositiveInfinity(), Real::PositiveInfinity(), Real::PositiveInfinity()}

    } ;

    for (auto& testCase : testCases)
    {

        Real& a = testCase.first ;
        const Real& b = testCase.second ;
        const Real& c = testCase.third ;

        a *= b ;

        if (c.isDefined())
        {

            if (c.isPositiveInfinity())
            {
                EXPECT_TRUE(a.isPositiveInfinity()) ;
            }
            else if (c.isNegativeInfinity())
            {
                EXPECT_TRUE(a.isNegativeInfinity()) ;
            }
            else
            {
                EXPECT_EQ(c, a) ;
            }

        }
        else
        {
            EXPECT_FALSE(a.isDefined()) ;
        }

    }

}

TEST(Spacer_Core_Types_Real, DivisionAssignmentOperator)
{

    using spacer::core::types::Real ;
    using spacer::core::ctnr::Triple ;
    using spacer::core::ctnr::Array ;

    Array<Triple<Real, Real, Real>> testCases =
    {

        {Real::Undefined(), Real::Undefined(), Real::Undefined()},
        {Real::Undefined(), Real::NegativeInfinity(), Real::Undefined()},
        {Real::Undefined(), std::numeric_limits<Real::ValueType>::min(), Real::Undefined()},
        {Real::Undefined(), -2.0, Real::Undefined()},
        {Real::Undefined(), -1.0, Real::Undefined()},
        {Real::Undefined(), +0.0, Real::Undefined()},
        {Real::Undefined(), +1.0, Real::Undefined()},
        {Real::Undefined(), +2.0, Real::Undefined()},
        {Real::Undefined(), std::numeric_limits<Real::ValueType>::max(), Real::Undefined()},
        {Real::Undefined(), Real::PositiveInfinity(), Real::Undefined()},

        {Real::NegativeInfinity(), Real::Undefined(), Real::Undefined()},
        {Real::NegativeInfinity(), Real::NegativeInfinity(), Real::Undefined()},
        {Real::NegativeInfinity(), std::numeric_limits<Real::ValueType>::min(), Real::PositiveInfinity()},
        {Real::NegativeInfinity(), -2.0, Real::PositiveInfinity()},
        {Real::NegativeInfinity(), -1.0, Real::PositiveInfinity()},
        {Real::NegativeInfinity(), +0.0, Real::Undefined()},
        {Real::NegativeInfinity(), +1.0, Real::NegativeInfinity()},
        {Real::NegativeInfinity(), +2.0, Real::NegativeInfinity()},
        {Real::NegativeInfinity(), std::numeric_limits<Real::ValueType>::max(), Real::NegativeInfinity()},
        {Real::NegativeInfinity(), Real::PositiveInfinity(), Real::Undefined()},

        {std::numeric_limits<Real::ValueType>::min(), Real::Undefined(), Real::Undefined()},
        {std::numeric_limits<Real::ValueType>::min(), Real::NegativeInfinity(), +0.0},
        {std::numeric_limits<Real::ValueType>::min(), std::numeric_limits<Real::ValueType>::min(), 1},
        {std::numeric_limits<Real::ValueType>::min(), -2.0, std::numeric_limits<Real::ValueType>::min() / -2.0},
        {std::numeric_limits<Real::ValueType>::min(), -1.0, Real::PositiveInfinity()},
        {std::numeric_limits<Real::ValueType>::min(), +0.0, Real::Undefined()},
        {std::numeric_limits<Real::ValueType>::min(), +1.0, std::numeric_limits<Real::ValueType>::min()},
        {std::numeric_limits<Real::ValueType>::min(), +2.0, std::numeric_limits<Real::ValueType>::min() / 2},
        {std::numeric_limits<Real::ValueType>::min(), std::numeric_limits<Real::ValueType>::max(), -1.0},
        {std::numeric_limits<Real::ValueType>::min(), Real::PositiveInfinity(), +0.0},

        {-2.0, Real::Undefined(), Real::Undefined()},
        {-2.0, Real::NegativeInfinity(), +0.0},
        {-2.0, std::numeric_limits<Real::ValueType>::min(), +0.0},
        {-2.0, -2.0, +1.0},
        {-2.0, -1.0, +2.0},
        {-2.0, +0.0, Real::Undefined()},
        {-2.0, +1.0, -2.0},
        {-2.0, +2.0, -1.0},
        {-2.0, std::numeric_limits<Real::ValueType>::max(), +0.0},
        {-2.0, Real::PositiveInfinity(), +0.0},
        
        {-1.0, Real::Undefined(), Real::Undefined()},
        {-1.0, Real::NegativeInfinity(), +0.0},
        {-1.0, std::numeric_limits<Real::ValueType>::min(), +0.0},
        {-1.0, -2.0, +0.0},
        {-1.0, -1.0, +1.0},
        {-1.0, +0.0, Real::Undefined()},
        {-1.0, +1.0, -1.0},
        {-1.0, +2.0, +0.0},
        {-1.0, std::numeric_limits<Real::ValueType>::max(), +0.0},
        {-1.0, Real::PositiveInfinity(), +0.0},

        {+0.0, Real::Undefined(), Real::Undefined()},
        {+0.0, Real::NegativeInfinity(), +0.0},
        {+0.0, std::numeric_limits<Real::ValueType>::min(), +0.0},
        {+0.0, -2.0, +0.0},
        {+0.0, -1.0, +0.0},
        {+0.0, +0.0, Real::Undefined()},
        {+0.0, +1.0, +0.0},
        {+0.0, +2.0, +0.0},
        {+0.0, std::numeric_limits<Real::ValueType>::max(), +0.0},
        {+0.0, Real::PositiveInfinity(), +0.0},

        {+1.0, Real::Undefined(), Real::Undefined()},
        {+1.0, Real::NegativeInfinity(), +0.0},
        {+1.0, std::numeric_limits<Real::ValueType>::min(), +0.0},
        {+1.0, -2.0, +0.0},
        {+1.0, -1.0, -1.0},
        {+1.0, +0.0, Real::Undefined()},
        {+1.0, +1.0, +1.0},
        {+1.0, +2.0, +0.0},
        {+1.0, std::numeric_limits<Real::ValueType>::max(), +0.0},
        {+1.0, Real::PositiveInfinity(), +0.0},

        {+2.0, Real::Undefined(), Real::Undefined()},
        {+2.0, Real::NegativeInfinity(), +0.0},
        {+2.0, std::numeric_limits<Real::ValueType>::min(), +0.0},
        {+2.0, -2.0, -1.0},
        {+2.0, -1.0, -2.0},
        {+2.0, +0.0, Real::Undefined()},
        {+2.0, +1.0, +2.0},
        {+2.0, +2.0, +1.0},
        {+2.0, std::numeric_limits<Real::ValueType>::max(), +0.0},
        {+2.0, Real::PositiveInfinity(), +0.0},

        {std::numeric_limits<Real::ValueType>::max(), Real::Undefined(), Real::Undefined()},
        {std::numeric_limits<Real::ValueType>::max(), Real::NegativeInfinity(), +0.0},
        {std::numeric_limits<Real::ValueType>::max(), std::numeric_limits<Real::ValueType>::min(), +0.0},
        {std::numeric_limits<Real::ValueType>::max(), -2.0, std::numeric_limits<Real::ValueType>::max() / -2.0},
        {std::numeric_limits<Real::ValueType>::max(), -1.0, std::numeric_limits<Real::ValueType>::max() / -1.0},
        {std::numeric_limits<Real::ValueType>::max(), +0.0, Real::Undefined()},
        {std::numeric_limits<Real::ValueType>::max(), +1.0, std::numeric_limits<Real::ValueType>::max()},
        {std::numeric_limits<Real::ValueType>::max(), +2.0, std::numeric_limits<Real::ValueType>::max() / 2},
        {std::numeric_limits<Real::ValueType>::max(), std::numeric_limits<Real::ValueType>::max(), +1.0},
        {std::numeric_limits<Real::ValueType>::max(), Real::PositiveInfinity(), +0.0},

        {Real::PositiveInfinity(), Real::Undefined(), Real::Undefined()},
        {Real::PositiveInfinity(), Real::NegativeInfinity(), Real::Undefined()},
        {Real::PositiveInfinity(), std::numeric_limits<Real::ValueType>::min(), Real::NegativeInfinity()},
        {Real::PositiveInfinity(), -2.0, Real::NegativeInfinity()},
        {Real::PositiveInfinity(), -1.0, Real::NegativeInfinity()},
        {Real::PositiveInfinity(), +0.0, Real::Undefined()},
        {Real::PositiveInfinity(), +1.0, Real::PositiveInfinity()},
        {Real::PositiveInfinity(), +2.0, Real::PositiveInfinity()},
        {Real::PositiveInfinity(), std::numeric_limits<Real::ValueType>::max(), Real::PositiveInfinity()},
        {Real::PositiveInfinity(), Real::PositiveInfinity(), Real::Undefined()}

    } ;

    for (auto& testCase : testCases)
    {

        Real& a = testCase.first ;
        const Real& b = testCase.second ;
        const Real& c = testCase.third ;

        a /= b ;

        if (c.isDefined())
        {

            if (c.isPositiveInfinity())
            {
                EXPECT_TRUE(a.isPositiveInfinity()) ;
            }
            else if (c.isNegativeInfinity())
            {
                EXPECT_TRUE(a.isNegativeInfinity()) ;
            }
            else
            {
                EXPECT_EQ(c, a) ;
            }

        }
        else
        {
            EXPECT_FALSE(a.isDefined()) ;
        }

    }

}

TEST(Spacer_Core_Types_Real, UnaryPlusOperator)
{

    using spacer::core::types::Real ;
    using spacer::core::ctnr::Pair ;
    using spacer::core::ctnr::Array ;

    Array<Pair<Real, Real>> testCases =
    {

        {Real::Undefined(), Real::Undefined()},
        {Real::NegativeInfinity(), Real::NegativeInfinity()},
        {std::numeric_limits<Real::ValueType>::min(), std::numeric_limits<Real::ValueType>::min()},
        {-2.0, -2.0},
        {-1.0, -1.0},
        {+0.0, +0.0},
        {+1.0, +1.0},
        {+2.0, +2.0},
        {std::numeric_limits<Real::ValueType>::max(), std::numeric_limits<Real::ValueType>::max()},
        {Real::PositiveInfinity(), Real::PositiveInfinity()}
        
    } ;

    for (const auto& testCase : testCases)
    {

        const Real& a = testCase.first ;
        const Real& b = testCase.second ;

        Real c = +a ;
        
        if (b.isDefined())
        {

            if (b.isPositiveInfinity())
            {
                EXPECT_TRUE(c.isPositiveInfinity()) ;
            }
            else if (b.isNegativeInfinity())
            {
                EXPECT_TRUE(c.isNegativeInfinity()) ;
            }
            else
            {
                EXPECT_EQ(b, c) ;
            }

        }
        else
        {
            EXPECT_FALSE(c.isDefined()) ;
        }

    }

}

TEST(Spacer_Core_Types_Real, UnaryMinusOperator)
{

    using spacer::core::types::Real ;
    using spacer::core::ctnr::Pair ;
    using spacer::core::ctnr::Array ;

    Array<Pair<Real, Real>> testCases =
    {

        {Real::Undefined(), Real::Undefined()},
        {Real::NegativeInfinity(), Real::PositiveInfinity()},
        {std::numeric_limits<Real::ValueType>::min(), Real::PositiveInfinity()},
        {-2.0, +2.0},
        {-1.0, +1.0},
        {+0.0, +0.0},
        {+1.0, -1.0},
        {+2.0, -2.0},
        {std::numeric_limits<Real::ValueType>::max(), -std::numeric_limits<Real::ValueType>::max()},
        {Real::PositiveInfinity(), Real::NegativeInfinity()}
        
    } ;

    for (const auto& testCase : testCases)
    {

        const Real& a = testCase.first ;
        const Real& b = testCase.second ;

        Real c = -a ;
        
        if (b.isDefined())
        {

            if (b.isPositiveInfinity())
            {
                EXPECT_TRUE(c.isPositiveInfinity()) ;
            }
            else if (b.isNegativeInfinity())
            {
                EXPECT_TRUE(c.isNegativeInfinity()) ;
            }
            else
            {
                EXPECT_EQ(b, c) ;
            }

        }
        else
        {
            EXPECT_FALSE(c.isDefined()) ;
        }

    }

}

TEST(Spacer_Core_Types_Real, ValueTypeOperator)
{

    using spacer::core::types::Real ;
    
    {

        EXPECT_ANY_THROW( Real::ValueType a = Real::Undefined() ; (void) a ; ) ;

    }

    {

        EXPECT_ANY_THROW( Real::ValueType a = Real::NegativeInfinity() ; (void) a ; ) ;

    }

    {

        Real::ValueType a = Real(std::numeric_limits<Real::ValueType>::min()) ;

        EXPECT_EQ(std::numeric_limits<Real::ValueType>::min(), a) ;

    }

    {

        Real::ValueType a = Real(-1.0) ;

        EXPECT_EQ(-1.0, a) ;

    }

    {

        Real::ValueType a = Real(+0.0) ;

        EXPECT_EQ(+0.0, a) ;

    }

    {

        Real::ValueType a = Real(+1.0) ;

        EXPECT_EQ(+1.0, a) ;

    }

    {

        EXPECT_ANY_THROW( Real::ValueType a = Real::PositiveInfinity() ; (void) a ; ) ;

    }

}

// TEST(Spacer_Core_Types_Real, StreamOperator)
// {

//     using spacer::core::types::Real ;

//     FAIL() ;

// }

TEST(Spacer_Core_Types_Real, IsDefined)
{

    using spacer::core::types::Real ;

    EXPECT_TRUE(Real(0.0).isDefined()) ;
    EXPECT_TRUE(Real(-1.0).isDefined()) ;
    EXPECT_TRUE(Real(+0.0).isDefined()) ;
    EXPECT_TRUE(Real(+1.0).isDefined()) ;
    EXPECT_TRUE(Real(std::numeric_limits<Real::ValueType>::min()).isDefined()) ;
    EXPECT_TRUE(Real(std::numeric_limits<Real::ValueType>::max()).isDefined()) ;
    EXPECT_TRUE(Real::NegativeInfinity().isDefined()) ;
    EXPECT_TRUE(Real::PositiveInfinity().isDefined()) ;

    EXPECT_FALSE(Real::Undefined().isDefined()) ;

}

TEST(Spacer_Core_Types_Real, IsZero)
{

    using spacer::core::types::Real ;

    EXPECT_TRUE(Real(0.0).isZero()) ;
    EXPECT_TRUE(Real(+0.0).isZero()) ;

    EXPECT_FALSE(Real(-1.0).isZero()) ;
    EXPECT_FALSE(Real(+1.0).isZero()) ;
    EXPECT_FALSE(Real(std::numeric_limits<Real::ValueType>::min()).isZero()) ;
    EXPECT_FALSE(Real(std::numeric_limits<Real::ValueType>::max()).isZero()) ;
    EXPECT_FALSE(Real::NegativeInfinity().isZero()) ;
    EXPECT_FALSE(Real::PositiveInfinity().isZero()) ;
    EXPECT_FALSE(Real::Undefined().isZero()) ;

}

TEST(Spacer_Core_Types_Real, IsPositive)
{

    using spacer::core::types::Real ;

    EXPECT_TRUE(Real(0.0).isPositive()) ;
    EXPECT_TRUE(Real(+0.0).isPositive()) ;
    EXPECT_TRUE(Real(+1.0).isPositive()) ;
    EXPECT_TRUE(Real(std::numeric_limits<Real::ValueType>::max()).isPositive()) ;
    EXPECT_TRUE(Real::PositiveInfinity().isPositive()) ;

    EXPECT_FALSE(Real::Undefined().isPositive()) ;
    EXPECT_FALSE(Real(-1.0).isPositive()) ;
    EXPECT_FALSE(Real(std::numeric_limits<Real::ValueType>::min()).isPositive()) ;
    EXPECT_FALSE(Real::NegativeInfinity().isPositive()) ;

}

TEST(Spacer_Core_Types_Real, IsNegative)
{

    using spacer::core::types::Real ;

    EXPECT_TRUE(Real(0.0).isNegative()) ;
    EXPECT_TRUE(Real(-1.0).isNegative()) ;
    EXPECT_TRUE(Real(+0.0).isNegative()) ;
    EXPECT_TRUE(Real(std::numeric_limits<Real::ValueType>::min()).isNegative()) ;
    EXPECT_TRUE(Real::NegativeInfinity().isNegative()) ;

    EXPECT_FALSE(Real::Undefined().isNegative()) ;
    EXPECT_FALSE(Real(+1.0).isNegative()) ;
    EXPECT_FALSE(Real(std::numeric_limits<Real::ValueType>::max()).isNegative()) ;
    EXPECT_FALSE(Real::PositiveInfinity().isNegative()) ;

}

TEST(Spacer_Core_Types_Real, IsStrictlyPositive)
{

    using spacer::core::types::Real ;

    EXPECT_TRUE(Real(+1.0).isStrictlyPositive()) ;
    EXPECT_TRUE(Real(std::numeric_limits<Real::ValueType>::max()).isStrictlyPositive()) ;
    EXPECT_TRUE(Real::PositiveInfinity().isStrictlyPositive()) ;

    EXPECT_FALSE(Real::Undefined().isStrictlyPositive()) ;
    EXPECT_FALSE(Real(0.0).isStrictlyPositive()) ;
    EXPECT_FALSE(Real(-1.0).isStrictlyPositive()) ;
    EXPECT_FALSE(Real(+0.0).isStrictlyPositive()) ;
    EXPECT_FALSE(Real(std::numeric_limits<Real::ValueType>::min()).isStrictlyPositive()) ;
    EXPECT_FALSE(Real::NegativeInfinity().isStrictlyPositive()) ;

}

TEST(Spacer_Core_Types_Real, IsStrictlyNegative)
{

    using spacer::core::types::Real ;

    EXPECT_TRUE(Real(-1.0).isStrictlyNegative()) ;
    EXPECT_TRUE(Real(std::numeric_limits<Real::ValueType>::min()).isStrictlyNegative()) ;
    EXPECT_TRUE(Real::NegativeInfinity().isStrictlyNegative()) ;

    EXPECT_FALSE(Real::Undefined().isStrictlyNegative()) ;
    EXPECT_FALSE(Real(0.0).isStrictlyNegative()) ;
    EXPECT_FALSE(Real(+1.0).isStrictlyNegative()) ;
    EXPECT_FALSE(Real(+0.0).isStrictlyNegative()) ;
    EXPECT_FALSE(Real(std::numeric_limits<Real::ValueType>::max()).isStrictlyNegative()) ;
    EXPECT_FALSE(Real::PositiveInfinity().isStrictlyNegative()) ;

}

TEST(Spacer_Core_Types_Real, IsInfinity)
{

    using spacer::core::types::Real ;

    EXPECT_TRUE(Real::NegativeInfinity().isInfinity()) ;
    EXPECT_TRUE(Real::PositiveInfinity().isInfinity()) ;

    EXPECT_FALSE(Real::Undefined().isInfinity()) ;
    EXPECT_FALSE(Real(0.0).isInfinity()) ;
    EXPECT_FALSE(Real(-1.0).isInfinity()) ;
    EXPECT_FALSE(Real(+0.0).isInfinity()) ;
    EXPECT_FALSE(Real(+1.0).isInfinity()) ;
    EXPECT_FALSE(Real(std::numeric_limits<Real::ValueType>::min()).isInfinity()) ;
    EXPECT_FALSE(Real(std::numeric_limits<Real::ValueType>::max()).isInfinity()) ;

}

TEST(Spacer_Core_Types_Real, IsPositiveInfinity)
{

    using spacer::core::types::Real ;

    EXPECT_TRUE(Real::PositiveInfinity().isPositiveInfinity()) ;

    EXPECT_FALSE(Real::Undefined().isPositiveInfinity()) ;
    EXPECT_FALSE(Real(0.0).isPositiveInfinity()) ;
    EXPECT_FALSE(Real(-1.0).isPositiveInfinity()) ;
    EXPECT_FALSE(Real(+0.0).isPositiveInfinity()) ;
    EXPECT_FALSE(Real(+1.0).isPositiveInfinity()) ;
    EXPECT_FALSE(Real(std::numeric_limits<Real::ValueType>::min()).isPositiveInfinity()) ;
    EXPECT_FALSE(Real(std::numeric_limits<Real::ValueType>::max()).isPositiveInfinity()) ;
    EXPECT_FALSE(Real::NegativeInfinity().isPositiveInfinity()) ;

}

TEST(Spacer_Core_Types_Real, IsNegativeInfinity)
{

    using spacer::core::types::Real ;

    EXPECT_TRUE(Real::NegativeInfinity().isNegativeInfinity()) ;

    EXPECT_FALSE(Real::Undefined().isNegativeInfinity()) ;
    EXPECT_FALSE(Real(0.0).isNegativeInfinity()) ;
    EXPECT_FALSE(Real(-1.0).isNegativeInfinity()) ;
    EXPECT_FALSE(Real(+0.0).isNegativeInfinity()) ;
    EXPECT_FALSE(Real(+1.0).isNegativeInfinity()) ;
    EXPECT_FALSE(Real(std::numeric_limits<Real::ValueType>::min()).isNegativeInfinity()) ;
    EXPECT_FALSE(Real(std::numeric_limits<Real::ValueType>::max()).isNegativeInfinity()) ;
    EXPECT_FALSE(Real::PositiveInfinity().isNegativeInfinity()) ;

}

TEST(Spacer_Core_Types_Real, GetSign)
{

    using spacer::core::types::Sign ;
    using spacer::core::types::Real ;

    EXPECT_EQ(Sign::Undefined, Real::Undefined().getSign()) ;
    EXPECT_EQ(Sign::None, Real(0.0).getSign()) ;
    EXPECT_EQ(Sign::Negative, Real(-1.0).getSign()) ;
    EXPECT_EQ(Sign::None, Real(+0.0).getSign()) ;
    EXPECT_EQ(Sign::Positive, Real(+1.0).getSign()) ;
    EXPECT_EQ(Sign::Negative, Real(std::numeric_limits<Real::ValueType>::min()).getSign()) ;
    EXPECT_EQ(Sign::Positive, Real(std::numeric_limits<Real::ValueType>::max()).getSign()) ;
    EXPECT_EQ(Sign::Negative, Real::NegativeInfinity().getSign()) ;
    EXPECT_EQ(Sign::Positive, Real::PositiveInfinity().getSign()) ;

}

TEST(Spacer_Core_Types_Real, GetString)
{

    using spacer::core::types::Real ;

    EXPECT_EQ("Undefined", Real::Undefined().getString()) ;
    EXPECT_EQ("0.0", Real(0.0).getString()) ;
    EXPECT_EQ("-1.0", Real(-1.0).getString()) ;
    EXPECT_EQ("0.0", Real(+0.0).getString()) ;
    EXPECT_EQ("1.0", Real(+1.0).getString()) ;
    EXPECT_EQ("-Inf", Real::NegativeInfinity().getString()) ;
    EXPECT_EQ("+Inf", Real::PositiveInfinity().getString()) ;

}

// TEST(Spacer_Core_Types_Real, GetObject)
// {

//     using spacer::core::types::Real ;

//     FAIL() ;

// }

TEST(Spacer_Core_Types_Real, Undefined)
{

    using spacer::core::types::Real ;

    EXPECT_NO_THROW(Real::Undefined()) ;
   
    EXPECT_FALSE(Real::Undefined().isDefined()) ;
    EXPECT_FALSE(Real::Undefined().isInfinity()) ;

}

TEST(Spacer_Core_Types_Real, PositiveInfinity)
{

    using spacer::core::types::Real ;

    EXPECT_NO_THROW(Real::PositiveInfinity()) ;

    EXPECT_TRUE(Real::PositiveInfinity().isDefined()) ;
    EXPECT_TRUE(Real::PositiveInfinity().isInfinity()) ;
    EXPECT_TRUE(Real::PositiveInfinity().isPositiveInfinity()) ;

}

TEST(Spacer_Core_Types_Real, NegativeInfinity)
{

    using spacer::core::types::Real ;

    EXPECT_NO_THROW(Real::NegativeInfinity()) ;
    
    EXPECT_TRUE(Real::NegativeInfinity().isDefined()) ;
    EXPECT_TRUE(Real::NegativeInfinity().isInfinity()) ;
    EXPECT_TRUE(Real::NegativeInfinity().isNegativeInfinity()) ;

}

TEST(Spacer_Core_Types_Real, String)
{

    using spacer::core::types::Real ;

    EXPECT_FALSE(Real::String("").isDefined()) ;
    EXPECT_FALSE(Real::String("Undefined").isDefined()) ;

    EXPECT_EQ(+0.0, Real::String("0")) ;
    EXPECT_EQ(-1.0, Real::String("-1")) ;
    EXPECT_EQ(+0.0, Real::String("+0")) ;
    EXPECT_EQ(+1.0, Real::String("+1")) ;
    
    EXPECT_EQ(+0.0, Real::String("0.0")) ;
    EXPECT_EQ(-1.0, Real::String("-1.0")) ;
    EXPECT_EQ(+0.0, Real::String("+0.0")) ;
    EXPECT_EQ(+1.0, Real::String("+1.0")) ;

    EXPECT_EQ(-2147483648.0, Real::String("-2147483648.0")) ;
    EXPECT_EQ(+2147483647.0, Real::String("+2147483647.0")) ;

    EXPECT_ANY_THROW(Real::String("-2147483649.0")) ;
    EXPECT_ANY_THROW(Real::String("2147483648.0")) ;
    EXPECT_ANY_THROW(Real::String("+2147483648.0")) ;

    EXPECT_TRUE(Real::String("-Inf").isNegativeInfinity()) ;
    EXPECT_TRUE(Real::String("Inf").isPositiveInfinity()) ;
    EXPECT_TRUE(Real::String("+Inf").isPositiveInfinity()) ;

}

// TEST(Spacer_Core_Types_Real, Object)
// {

//     using spacer::core::types::Real ;

//     FAIL() ;

// }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////