////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Copyright (C) 2017 by Lucas Brémond
///
/// This file is part of the Spacer project.
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @file                       Spacer/Core/Types/Integer.test.cpp
/// @author                     Lucas Brémond <lucas.bremond@gmail.com>
/// @date                       2 Dec 2017

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Global.test.hpp>

#include <Spacer/Core/Types/Integer.hpp>
#include <Spacer/Core/Containers/Pair.hpp>
#include <Spacer/Core/Containers/Triple.hpp>
#include <Spacer/Core/Containers/Array.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(Spacer_Core_Types_Integer, DefaultConstructor)
{

    using spacer::core::types::Integer ;

    EXPECT_NO_THROW(Integer(0)) ;
    EXPECT_NO_THROW(Integer(1)) ;
    EXPECT_NO_THROW(Integer(123)) ;
    EXPECT_NO_THROW(Integer(+123)) ;
    EXPECT_NO_THROW(Integer(-123)) ;

}

TEST(Spacer_Core_Types_Integer, AssignmentOperator)
{

    using spacer::core::types::Integer ;

    EXPECT_NO_THROW(Integer a = 0 ; (void) a ; ) ;
    EXPECT_NO_THROW(Integer a = 0 ; (void) a ; ) ;
    EXPECT_NO_THROW(Integer a = 1 ; (void) a ; ) ;
    EXPECT_NO_THROW(Integer a = 123 ; (void) a ; ) ;
    EXPECT_NO_THROW(Integer a = +123 ; (void) a ; ) ;
    EXPECT_NO_THROW(Integer a = -123 ; (void) a ; ) ;

}

TEST(Spacer_Core_Types_Integer, EqualToOperator)
{

    using spacer::core::types::Integer ;

    EXPECT_TRUE(Integer(0) == Integer(0)) ;
    EXPECT_TRUE(Integer(123) == Integer(123)) ;
    EXPECT_TRUE(Integer(+123) == Integer(+123)) ;
    EXPECT_TRUE(Integer(-123) == Integer(-123)) ;

    EXPECT_FALSE(Integer(0) == Integer(1)) ;
    EXPECT_FALSE(Integer(1) == Integer(0)) ;
    EXPECT_FALSE(Integer(-1) == Integer(+1)) ;

    EXPECT_FALSE(Integer::Undefined() == Integer::Undefined()) ;
    EXPECT_FALSE(Integer::PositiveInfinity() == Integer::PositiveInfinity()) ;
    EXPECT_FALSE(Integer::NegativeInfinity() == Integer::NegativeInfinity()) ;
    EXPECT_FALSE(Integer::PositiveInfinity() == Integer::NegativeInfinity()) ;
    EXPECT_FALSE(Integer::NegativeInfinity() == Integer::PositiveInfinity()) ;

}

TEST(Spacer_Core_Types_Integer, NotEqualToOperator)
{

    using spacer::core::types::Integer ;    

    EXPECT_TRUE(Integer(0) != Integer(1)) ;
    EXPECT_TRUE(Integer(1) != Integer(0)) ;
    EXPECT_TRUE(Integer(-1) != Integer(+1)) ;

    EXPECT_FALSE(Integer(0) != Integer(0)) ;
    EXPECT_FALSE(Integer(123) != Integer(123)) ;
    EXPECT_FALSE(Integer(+123) != Integer(+123)) ;
    EXPECT_FALSE(Integer(-123) != Integer(-123)) ;

    EXPECT_FALSE(Integer::Undefined() != Integer::Undefined()) ;
    EXPECT_FALSE(Integer::PositiveInfinity() != Integer::PositiveInfinity()) ;
    EXPECT_FALSE(Integer::NegativeInfinity() != Integer::NegativeInfinity()) ;
    EXPECT_FALSE(Integer::PositiveInfinity() != Integer::NegativeInfinity()) ;
    EXPECT_FALSE(Integer::NegativeInfinity() != Integer::PositiveInfinity()) ;

}

TEST(Spacer_Core_Types_Integer, LessThanOperator)
{

    using spacer::core::types::Integer ;

    EXPECT_TRUE(Integer(0) < Integer(1)) ;
    EXPECT_TRUE(Integer(1) < Integer(2)) ;
    EXPECT_TRUE(Integer(-1) < Integer(0)) ;
    EXPECT_TRUE(Integer(-1) < Integer(+1)) ;
    EXPECT_TRUE(Integer(-123) < Integer(+123)) ;

    EXPECT_FALSE(Integer(0) < Integer(0)) ;
    EXPECT_FALSE(Integer(1) < Integer(0)) ;
    EXPECT_FALSE(Integer(+1) < Integer(-1)) ;
    EXPECT_FALSE(Integer(+123) < Integer(-123)) ;
    EXPECT_FALSE(Integer(+123) < Integer(+123)) ;
    EXPECT_FALSE(Integer(-123) < Integer(-123)) ;
    
    EXPECT_FALSE(Integer::Undefined() < Integer::Undefined()) ;
    EXPECT_FALSE(Integer::PositiveInfinity() < Integer::PositiveInfinity()) ;
    EXPECT_FALSE(Integer::NegativeInfinity() < Integer::NegativeInfinity()) ;
    EXPECT_FALSE(Integer::PositiveInfinity() < Integer::NegativeInfinity()) ;
    EXPECT_FALSE(Integer::NegativeInfinity() < Integer::PositiveInfinity()) ;

}

TEST(Spacer_Core_Types_Integer, LessThanOrEqualToOperator)
{

    using spacer::core::types::Integer ;

    EXPECT_TRUE(Integer(0) <= Integer(1)) ;
    EXPECT_TRUE(Integer(1) <= Integer(2)) ;
    EXPECT_TRUE(Integer(-1) <= Integer(0)) ;
    EXPECT_TRUE(Integer(-1) <= Integer(+1)) ;
    EXPECT_TRUE(Integer(-123) <= Integer(+123)) ;
    EXPECT_TRUE(Integer(0) <= Integer(0)) ;
    EXPECT_TRUE(Integer(+123) <= Integer(+123)) ;
    EXPECT_TRUE(Integer(-123) <= Integer(-123)) ;

    EXPECT_FALSE(Integer(1) <= Integer(0)) ;
    EXPECT_FALSE(Integer(+1) <= Integer(-1)) ;
    EXPECT_FALSE(Integer(+123) <= Integer(-123)) ;
    
    EXPECT_FALSE(Integer::Undefined() <= Integer::Undefined()) ;
    EXPECT_FALSE(Integer::PositiveInfinity() <= Integer::PositiveInfinity()) ;
    EXPECT_FALSE(Integer::NegativeInfinity() <= Integer::NegativeInfinity()) ;
    EXPECT_FALSE(Integer::PositiveInfinity() <= Integer::NegativeInfinity()) ;
    EXPECT_FALSE(Integer::NegativeInfinity() <= Integer::PositiveInfinity()) ;

}

TEST(Spacer_Core_Types_Integer, GreaterThanOperator)
{

    using spacer::core::types::Integer ;

    EXPECT_TRUE(Integer(1) > Integer(0)) ;
    EXPECT_TRUE(Integer(2) > Integer(1)) ;
    EXPECT_TRUE(Integer(+1) > Integer(0)) ;
    EXPECT_TRUE(Integer(+1) > Integer(-1)) ;
    EXPECT_TRUE(Integer(+123) > Integer(-123)) ;

    EXPECT_FALSE(Integer(0) > Integer(0)) ;
    EXPECT_FALSE(Integer(0) > Integer(1)) ;
    EXPECT_FALSE(Integer(-1) > Integer(+1)) ;
    EXPECT_FALSE(Integer(-123) > Integer(+123)) ;
    EXPECT_FALSE(Integer(+123) > Integer(+123)) ;
    EXPECT_FALSE(Integer(-123) > Integer(-123)) ;
    
    EXPECT_FALSE(Integer::Undefined() > Integer::Undefined()) ;
    EXPECT_FALSE(Integer::PositiveInfinity() > Integer::PositiveInfinity()) ;
    EXPECT_FALSE(Integer::NegativeInfinity() > Integer::NegativeInfinity()) ;
    EXPECT_FALSE(Integer::PositiveInfinity() > Integer::NegativeInfinity()) ;
    EXPECT_FALSE(Integer::NegativeInfinity() > Integer::PositiveInfinity()) ;

}

TEST(Spacer_Core_Types_Integer, GreaterThanOrEqualToOperator)
{

    using spacer::core::types::Integer ;

    EXPECT_TRUE(Integer(1) >= Integer(0)) ;
    EXPECT_TRUE(Integer(2) >= Integer(1)) ;
    EXPECT_TRUE(Integer(+1) >= Integer(0)) ;
    EXPECT_TRUE(Integer(+1) >= Integer(-1)) ;
    EXPECT_TRUE(Integer(+123) >= Integer(-123)) ;
    EXPECT_TRUE(Integer(0) >= Integer(0)) ;
    EXPECT_TRUE(Integer(+123) >= Integer(+123)) ;
    EXPECT_TRUE(Integer(-123) >= Integer(-123)) ;

    EXPECT_FALSE(Integer(0) >= Integer(1)) ;
    EXPECT_FALSE(Integer(-1) >= Integer(+1)) ;
    EXPECT_FALSE(Integer(-123) >= Integer(+123)) ;
    
    EXPECT_FALSE(Integer::Undefined() >= Integer::Undefined()) ;
    EXPECT_FALSE(Integer::PositiveInfinity() >= Integer::PositiveInfinity()) ;
    EXPECT_FALSE(Integer::NegativeInfinity() >= Integer::NegativeInfinity()) ;
    EXPECT_FALSE(Integer::PositiveInfinity() >= Integer::NegativeInfinity()) ;
    EXPECT_FALSE(Integer::NegativeInfinity() >= Integer::PositiveInfinity()) ;

}

TEST(Spacer_Core_Types_Integer, AdditionOperator)
{

    using spacer::core::types::Integer ;
    using spacer::core::ctnr::Triple ;
    using spacer::core::ctnr::Array ;

    Array<Triple<Integer, Integer, Integer>> testCases =
    {

        {Integer::Undefined(), Integer::Undefined(), Integer::Undefined()},
        {Integer::Undefined(), Integer::NegativeInfinity(), Integer::Undefined()},
        {Integer::Undefined(), std::numeric_limits<Integer::ValueType>::min(), Integer::Undefined()},
        {Integer::Undefined(), -2, Integer::Undefined()},
        {Integer::Undefined(), -1, Integer::Undefined()},
        {Integer::Undefined(), +0, Integer::Undefined()},
        {Integer::Undefined(), +1, Integer::Undefined()},
        {Integer::Undefined(), +2, Integer::Undefined()},
        {Integer::Undefined(), std::numeric_limits<Integer::ValueType>::max(), Integer::Undefined()},
        {Integer::Undefined(), Integer::PositiveInfinity(), Integer::Undefined()},

        {Integer::NegativeInfinity(), Integer::Undefined(), Integer::Undefined()},
        {Integer::NegativeInfinity(), Integer::NegativeInfinity(), Integer::NegativeInfinity()},
        {Integer::NegativeInfinity(), std::numeric_limits<Integer::ValueType>::min(), Integer::NegativeInfinity()},
        {Integer::NegativeInfinity(), -2, Integer::NegativeInfinity()},
        {Integer::NegativeInfinity(), -1, Integer::NegativeInfinity()},
        {Integer::NegativeInfinity(), +0, Integer::NegativeInfinity()},
        {Integer::NegativeInfinity(), +1, Integer::NegativeInfinity()},
        {Integer::NegativeInfinity(), +2, Integer::NegativeInfinity()},
        {Integer::NegativeInfinity(), std::numeric_limits<Integer::ValueType>::max(), Integer::NegativeInfinity()},
        {Integer::NegativeInfinity(), Integer::PositiveInfinity(), Integer::Undefined()},

        {std::numeric_limits<Integer::ValueType>::min(), Integer::Undefined(), Integer::Undefined()},
        {std::numeric_limits<Integer::ValueType>::min(), Integer::NegativeInfinity(), Integer::NegativeInfinity()},
        {std::numeric_limits<Integer::ValueType>::min(), std::numeric_limits<Integer::ValueType>::min(), Integer::NegativeInfinity()},
        {std::numeric_limits<Integer::ValueType>::min(), -2, Integer::NegativeInfinity()},
        {std::numeric_limits<Integer::ValueType>::min(), -1, Integer::NegativeInfinity()},
        {std::numeric_limits<Integer::ValueType>::min(), +0, std::numeric_limits<Integer::ValueType>::min()},
        {std::numeric_limits<Integer::ValueType>::min(), +1, std::numeric_limits<Integer::ValueType>::min() + 1},
        {std::numeric_limits<Integer::ValueType>::min(), +2, std::numeric_limits<Integer::ValueType>::min() + 2},
        {std::numeric_limits<Integer::ValueType>::min(), std::numeric_limits<Integer::ValueType>::max(), std::numeric_limits<Integer::ValueType>::min() + std::numeric_limits<Integer::ValueType>::max()},
        {std::numeric_limits<Integer::ValueType>::min(), Integer::PositiveInfinity(), Integer::PositiveInfinity()},

        {-2, Integer::Undefined(), Integer::Undefined()},
        {-2, Integer::NegativeInfinity(), Integer::NegativeInfinity()},
        {-2, std::numeric_limits<Integer::ValueType>::min(), Integer::NegativeInfinity()},
        {-2, -2, -4},
        {-2, -1, -3},
        {-2, +0, -2},
        {-2, +1, -1},
        {-2, +2, +0},
        {-2, std::numeric_limits<Integer::ValueType>::max(), std::numeric_limits<Integer::ValueType>::max() - 2},
        {-2, Integer::PositiveInfinity(), Integer::PositiveInfinity()},

        {-1, Integer::Undefined(), Integer::Undefined()},
        {-1, Integer::NegativeInfinity(), Integer::NegativeInfinity()},
        {-1, std::numeric_limits<Integer::ValueType>::min(), Integer::NegativeInfinity()},
        {-1, -2, -3},
        {-1, -1, -2},
        {-1, +0, -1},
        {-1, +1, +0},
        {-1, +2, +1},
        {-1, std::numeric_limits<Integer::ValueType>::max(), std::numeric_limits<Integer::ValueType>::max() - 1},
        {-1, Integer::PositiveInfinity(), Integer::PositiveInfinity()},

        {+0, Integer::Undefined(), Integer::Undefined()},
        {+0, Integer::NegativeInfinity(), Integer::NegativeInfinity()},
        {+0, std::numeric_limits<Integer::ValueType>::min(), std::numeric_limits<Integer::ValueType>::min()},
        {+0, -2, -2},
        {+0, -1, -1},
        {+0, +0, +0},
        {+0, +1, +1},
        {+0, +2, +2},
        {+0, std::numeric_limits<Integer::ValueType>::max(), std::numeric_limits<Integer::ValueType>::max()},
        {+0, Integer::PositiveInfinity(), Integer::PositiveInfinity()},

        {+1, Integer::Undefined(), Integer::Undefined()},
        {+1, Integer::NegativeInfinity(), Integer::NegativeInfinity()},
        {+1, std::numeric_limits<Integer::ValueType>::min(), std::numeric_limits<Integer::ValueType>::min() + 1},
        {+1, -2, -1},
        {+1, -1, +0},
        {+1, +0, +1},
        {+1, +1, +2},
        {+1, +2, +3},
        {+1, std::numeric_limits<Integer::ValueType>::max(), Integer::PositiveInfinity()},
        {+1, Integer::PositiveInfinity(), Integer::PositiveInfinity()},
        
        {+2, Integer::Undefined(), Integer::Undefined()},
        {+2, Integer::NegativeInfinity(), Integer::NegativeInfinity()},
        {+2, std::numeric_limits<Integer::ValueType>::min(), std::numeric_limits<Integer::ValueType>::min() + 2},
        {+2, -2, +0},
        {+2, -1, +1},
        {+2, +0, +2},
        {+2, +1, +3},
        {+2, +2, +4},
        {+2, std::numeric_limits<Integer::ValueType>::max(), Integer::PositiveInfinity()},
        {+2, Integer::PositiveInfinity(), Integer::PositiveInfinity()},

        {std::numeric_limits<Integer::ValueType>::max(), Integer::Undefined(), Integer::Undefined()},
        {std::numeric_limits<Integer::ValueType>::max(), Integer::NegativeInfinity(), Integer::NegativeInfinity()},
        {std::numeric_limits<Integer::ValueType>::max(), std::numeric_limits<Integer::ValueType>::min(), std::numeric_limits<Integer::ValueType>::max() + std::numeric_limits<Integer::ValueType>::min()},
        {std::numeric_limits<Integer::ValueType>::max(), -2, std::numeric_limits<Integer::ValueType>::max() - 2},
        {std::numeric_limits<Integer::ValueType>::max(), -1, std::numeric_limits<Integer::ValueType>::max() - 1},
        {std::numeric_limits<Integer::ValueType>::max(), +0, std::numeric_limits<Integer::ValueType>::max()},
        {std::numeric_limits<Integer::ValueType>::max(), +1, Integer::PositiveInfinity()},
        {std::numeric_limits<Integer::ValueType>::max(), +2, Integer::PositiveInfinity()},
        {std::numeric_limits<Integer::ValueType>::max(), std::numeric_limits<Integer::ValueType>::max(), Integer::PositiveInfinity()},
        {std::numeric_limits<Integer::ValueType>::max(), Integer::PositiveInfinity(), Integer::PositiveInfinity()},

        {Integer::PositiveInfinity(), Integer::Undefined(), Integer::Undefined()},
        {Integer::PositiveInfinity(), Integer::NegativeInfinity(), Integer::Undefined()},
        {Integer::PositiveInfinity(), std::numeric_limits<Integer::ValueType>::min(), Integer::PositiveInfinity()},
        {Integer::PositiveInfinity(), -2, Integer::PositiveInfinity()},
        {Integer::PositiveInfinity(), -1, Integer::PositiveInfinity()},
        {Integer::PositiveInfinity(), +0, Integer::PositiveInfinity()},
        {Integer::PositiveInfinity(), +1, Integer::PositiveInfinity()},
        {Integer::PositiveInfinity(), +2, Integer::PositiveInfinity()},
        {Integer::PositiveInfinity(), std::numeric_limits<Integer::ValueType>::max(), Integer::PositiveInfinity()},
        {Integer::PositiveInfinity(), Integer::PositiveInfinity(), Integer::PositiveInfinity()}

    } ;

    for (const auto& testCase : testCases)
    {

        const Integer& a = testCase.first ;
        const Integer& b = testCase.second ;
        const Integer& c = testCase.third ;

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

TEST(Spacer_Core_Types_Integer, SubtractionOperator)
{

    using spacer::core::types::Integer ;
    using spacer::core::ctnr::Triple ;
    using spacer::core::ctnr::Array ;

    Array<Triple<Integer, Integer, Integer>> testCases =
    {

        {Integer::Undefined(), Integer::Undefined(), Integer::Undefined()},
        {Integer::Undefined(), Integer::NegativeInfinity(), Integer::Undefined()},
        {Integer::Undefined(), std::numeric_limits<Integer::ValueType>::min(), Integer::Undefined()},
        {Integer::Undefined(), -2, Integer::Undefined()},
        {Integer::Undefined(), -1, Integer::Undefined()},
        {Integer::Undefined(), +0, Integer::Undefined()},
        {Integer::Undefined(), +1, Integer::Undefined()},
        {Integer::Undefined(), +2, Integer::Undefined()},
        {Integer::Undefined(), std::numeric_limits<Integer::ValueType>::max(), Integer::Undefined()},
        {Integer::Undefined(), Integer::PositiveInfinity(), Integer::Undefined()},

        {Integer::NegativeInfinity(), Integer::Undefined(), Integer::Undefined()},
        {Integer::NegativeInfinity(), Integer::NegativeInfinity(), Integer::Undefined()},
        {Integer::NegativeInfinity(), std::numeric_limits<Integer::ValueType>::min(), Integer::NegativeInfinity()},
        {Integer::NegativeInfinity(), -2, Integer::NegativeInfinity()},
        {Integer::NegativeInfinity(), -1, Integer::NegativeInfinity()},
        {Integer::NegativeInfinity(), +0, Integer::NegativeInfinity()},
        {Integer::NegativeInfinity(), +1, Integer::NegativeInfinity()},
        {Integer::NegativeInfinity(), +2, Integer::NegativeInfinity()},
        {Integer::NegativeInfinity(), std::numeric_limits<Integer::ValueType>::max(), Integer::NegativeInfinity()},
        {Integer::NegativeInfinity(), Integer::PositiveInfinity(), Integer::NegativeInfinity()},

        {std::numeric_limits<Integer::ValueType>::min(), Integer::Undefined(), Integer::Undefined()},
        {std::numeric_limits<Integer::ValueType>::min(), Integer::NegativeInfinity(), Integer::PositiveInfinity()},
        {std::numeric_limits<Integer::ValueType>::min(), std::numeric_limits<Integer::ValueType>::min(), +0},
        {std::numeric_limits<Integer::ValueType>::min(), -2, std::numeric_limits<Integer::ValueType>::min() + 2},
        {std::numeric_limits<Integer::ValueType>::min(), -1, std::numeric_limits<Integer::ValueType>::min() + 1},
        {std::numeric_limits<Integer::ValueType>::min(), +0, std::numeric_limits<Integer::ValueType>::min()},
        {std::numeric_limits<Integer::ValueType>::min(), +1, Integer::NegativeInfinity()},
        {std::numeric_limits<Integer::ValueType>::min(), +2, Integer::NegativeInfinity()},
        {std::numeric_limits<Integer::ValueType>::min(), std::numeric_limits<Integer::ValueType>::max(), Integer::NegativeInfinity()},
        {std::numeric_limits<Integer::ValueType>::min(), Integer::PositiveInfinity(), Integer::NegativeInfinity()},

        {-2, Integer::Undefined(), Integer::Undefined()},
        {-2, Integer::NegativeInfinity(), Integer::PositiveInfinity()},
        {-2, std::numeric_limits<Integer::ValueType>::min(), -2 - std::numeric_limits<Integer::ValueType>::min()},
        {-2, -2, +0},
        {-2, -1, -1},
        {-2, +0, -2},
        {-2, +1, -3},
        {-2, +2, -4},
        {-2, std::numeric_limits<Integer::ValueType>::max(), Integer::NegativeInfinity()},
        {-2, Integer::PositiveInfinity(), Integer::NegativeInfinity()},

        {-1, Integer::Undefined(), Integer::Undefined()},
        {-1, Integer::NegativeInfinity(), Integer::PositiveInfinity()},
        {-1, std::numeric_limits<Integer::ValueType>::min(), std::numeric_limits<Integer::ValueType>::max()},
        {-1, -2, +1},
        {-1, -1, +0},
        {-1, +0, -1},
        {-1, +1, -2},
        {-1, +2, -3},
        {-1, std::numeric_limits<Integer::ValueType>::max(), std::numeric_limits<Integer::ValueType>::min()},
        {-1, Integer::PositiveInfinity(), Integer::NegativeInfinity()},

        {+0, Integer::Undefined(), Integer::Undefined()},
        {+0, Integer::NegativeInfinity(), Integer::PositiveInfinity()},
        {+0, std::numeric_limits<Integer::ValueType>::min(), Integer::PositiveInfinity()},
        {+0, -2, +2},
        {+0, -1, +1},
        {+0, +0, +0},
        {+0, +1, -1},
        {+0, +2, -2},
        {+0, std::numeric_limits<Integer::ValueType>::max(), std::numeric_limits<Integer::ValueType>::min() + 1},
        {+0, Integer::PositiveInfinity(), Integer::NegativeInfinity()},

        {+1, Integer::Undefined(), Integer::Undefined()},
        {+1, Integer::NegativeInfinity(), Integer::PositiveInfinity()},
        {+1, std::numeric_limits<Integer::ValueType>::min(), Integer::PositiveInfinity()},
        {+1, -2, +3},
        {+1, -1, +2},
        {+1, +0, +1},
        {+1, +1, +0},
        {+1, +2, -1},
        {+1, std::numeric_limits<Integer::ValueType>::max(), std::numeric_limits<Integer::ValueType>::min() + 2},
        {+1, Integer::PositiveInfinity(), Integer::NegativeInfinity()},
        
        {+2, Integer::Undefined(), Integer::Undefined()},
        {+2, Integer::NegativeInfinity(), Integer::PositiveInfinity()},
        {+2, std::numeric_limits<Integer::ValueType>::min(), Integer::PositiveInfinity()},
        {+2, -2, +4},
        {+2, -1, +3},
        {+2, +0, +2},
        {+2, +1, +1},
        {+2, +2, +0},
        {+2, std::numeric_limits<Integer::ValueType>::max(), std::numeric_limits<Integer::ValueType>::min() + 3},
        {+2, Integer::PositiveInfinity(), Integer::NegativeInfinity()},

        {std::numeric_limits<Integer::ValueType>::max(), Integer::Undefined(), Integer::Undefined()},
        {std::numeric_limits<Integer::ValueType>::max(), Integer::NegativeInfinity(), Integer::PositiveInfinity()},
        {std::numeric_limits<Integer::ValueType>::max(), std::numeric_limits<Integer::ValueType>::min(), Integer::PositiveInfinity()},
        {std::numeric_limits<Integer::ValueType>::max(), -2, Integer::PositiveInfinity()},
        {std::numeric_limits<Integer::ValueType>::max(), -1, Integer::PositiveInfinity()},
        {std::numeric_limits<Integer::ValueType>::max(), +0, std::numeric_limits<Integer::ValueType>::max()},
        {std::numeric_limits<Integer::ValueType>::max(), +1, std::numeric_limits<Integer::ValueType>::max() - 1},
        {std::numeric_limits<Integer::ValueType>::max(), +2, std::numeric_limits<Integer::ValueType>::max() - 2},
        {std::numeric_limits<Integer::ValueType>::max(), std::numeric_limits<Integer::ValueType>::max(), +0},
        {std::numeric_limits<Integer::ValueType>::max(), Integer::PositiveInfinity(), Integer::NegativeInfinity()},

        {Integer::PositiveInfinity(), Integer::Undefined(), Integer::Undefined()},
        {Integer::PositiveInfinity(), Integer::NegativeInfinity(), Integer::PositiveInfinity()},
        {Integer::PositiveInfinity(), std::numeric_limits<Integer::ValueType>::min(), Integer::PositiveInfinity()},
        {Integer::PositiveInfinity(), -2, Integer::PositiveInfinity()},
        {Integer::PositiveInfinity(), -1, Integer::PositiveInfinity()},
        {Integer::PositiveInfinity(), +0, Integer::PositiveInfinity()},
        {Integer::PositiveInfinity(), +1, Integer::PositiveInfinity()},
        {Integer::PositiveInfinity(), +2, Integer::PositiveInfinity()},
        {Integer::PositiveInfinity(), std::numeric_limits<Integer::ValueType>::max(), Integer::PositiveInfinity()},
        {Integer::PositiveInfinity(), Integer::PositiveInfinity(), Integer::Undefined()}

    } ;

    for (const auto& testCase : testCases)
    {

        const Integer& a = testCase.first ;
        const Integer& b = testCase.second ;
        const Integer& c = testCase.third ;
        
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

TEST(Spacer_Core_Types_Integer, MultiplicationOperator)
{

    using spacer::core::types::Integer ;
    using spacer::core::ctnr::Triple ;
    using spacer::core::ctnr::Array ;

    Array<Triple<Integer, Integer, Integer>> testCases =
    {

        {Integer::Undefined(), Integer::Undefined(), Integer::Undefined()},
        {Integer::Undefined(), Integer::NegativeInfinity(), Integer::Undefined()},
        {Integer::Undefined(), std::numeric_limits<Integer::ValueType>::min(), Integer::Undefined()},
        {Integer::Undefined(), -2, Integer::Undefined()},
        {Integer::Undefined(), -1, Integer::Undefined()},
        {Integer::Undefined(), +0, Integer::Undefined()},
        {Integer::Undefined(), +1, Integer::Undefined()},
        {Integer::Undefined(), +2, Integer::Undefined()},
        {Integer::Undefined(), std::numeric_limits<Integer::ValueType>::max(), Integer::Undefined()},
        {Integer::Undefined(), Integer::PositiveInfinity(), Integer::Undefined()},

        {Integer::NegativeInfinity(), Integer::Undefined(), Integer::Undefined()},
        {Integer::NegativeInfinity(), Integer::NegativeInfinity(), Integer::PositiveInfinity()},
        {Integer::NegativeInfinity(), std::numeric_limits<Integer::ValueType>::min(), Integer::PositiveInfinity()},
        {Integer::NegativeInfinity(), -2, Integer::PositiveInfinity()},
        {Integer::NegativeInfinity(), -1, Integer::PositiveInfinity()},
        {Integer::NegativeInfinity(), +0, Integer::Undefined()},
        {Integer::NegativeInfinity(), +1, Integer::NegativeInfinity()},
        {Integer::NegativeInfinity(), +2, Integer::NegativeInfinity()},
        {Integer::NegativeInfinity(), std::numeric_limits<Integer::ValueType>::max(), Integer::NegativeInfinity()},
        {Integer::NegativeInfinity(), Integer::PositiveInfinity(), Integer::NegativeInfinity()},

        {std::numeric_limits<Integer::ValueType>::min(), Integer::Undefined(), Integer::Undefined()},
        {std::numeric_limits<Integer::ValueType>::min(), Integer::NegativeInfinity(), Integer::PositiveInfinity()},
        {std::numeric_limits<Integer::ValueType>::min(), std::numeric_limits<Integer::ValueType>::min(), Integer::PositiveInfinity()},
        {std::numeric_limits<Integer::ValueType>::min(), -2, Integer::PositiveInfinity()},
        {std::numeric_limits<Integer::ValueType>::min(), -1, Integer::PositiveInfinity()},
        {std::numeric_limits<Integer::ValueType>::min(), +0, +0},
        {std::numeric_limits<Integer::ValueType>::min(), +1, std::numeric_limits<Integer::ValueType>::min()},
        {std::numeric_limits<Integer::ValueType>::min(), +2, Integer::NegativeInfinity()},
        {std::numeric_limits<Integer::ValueType>::min(), std::numeric_limits<Integer::ValueType>::max(), Integer::NegativeInfinity()},
        {std::numeric_limits<Integer::ValueType>::min(), Integer::PositiveInfinity(), Integer::NegativeInfinity()},

        {-1073741823, Integer::Undefined(), Integer::Undefined()},
        {-1073741823, Integer::NegativeInfinity(), Integer::PositiveInfinity()},
        {-1073741823, std::numeric_limits<Integer::ValueType>::min(), Integer::PositiveInfinity()},
        {-1073741823, -3, Integer::PositiveInfinity()},
        {-1073741823, -2, +2147483646},
        {-1073741823, -1, +1073741823},
        {-1073741823, +0, +0},
        {-1073741823, +1, -1073741823},
        {-1073741823, +2, -2147483646},
        {-1073741823, +3, Integer::NegativeInfinity()},
        {-1073741823, std::numeric_limits<Integer::ValueType>::max(), Integer::NegativeInfinity()},
        {-1073741823, Integer::PositiveInfinity(), Integer::NegativeInfinity()},

        {-2, Integer::Undefined(), Integer::Undefined()},
        {-2, Integer::NegativeInfinity(), Integer::PositiveInfinity()},
        {-2, std::numeric_limits<Integer::ValueType>::min(), Integer::PositiveInfinity()},
        {-2, -2, +4},
        {-2, -1, +2},
        {-2, +0, +0},
        {-2, +1, -2},
        {-2, +2, -4},
        {-2, std::numeric_limits<Integer::ValueType>::max(), Integer::NegativeInfinity()},
        {-2, Integer::PositiveInfinity(), Integer::NegativeInfinity()},
        
        {-1, Integer::Undefined(), Integer::Undefined()},
        {-1, Integer::NegativeInfinity(), Integer::PositiveInfinity()},
        {-1, std::numeric_limits<Integer::ValueType>::min(), Integer::PositiveInfinity()},
        {-1, -2, +2},
        {-1, -1, +1},
        {-1, +0, +0},
        {-1, +1, -1},
        {-1, +2, -2},
        {-1, std::numeric_limits<Integer::ValueType>::max(), -std::numeric_limits<Integer::ValueType>::max()},
        {-1, Integer::PositiveInfinity(), Integer::NegativeInfinity()},

        {+0, Integer::Undefined(), Integer::Undefined()},
        {+0, Integer::NegativeInfinity(), Integer::Undefined()},
        {+0, std::numeric_limits<Integer::ValueType>::min(), +0},
        {+0, -2, +0},
        {+0, -1, +0},
        {+0, +0, +0},
        {+0, +1, +0},
        {+0, +2, +0},
        {+0, std::numeric_limits<Integer::ValueType>::max(), +0},
        {+0, Integer::PositiveInfinity(), Integer::Undefined()},

        {+1, Integer::Undefined(), Integer::Undefined()},
        {+1, Integer::NegativeInfinity(), Integer::NegativeInfinity()},
        {+1, std::numeric_limits<Integer::ValueType>::min(), std::numeric_limits<Integer::ValueType>::min()},
        {+1, -2, -2},
        {+1, -1, -1},
        {+1, +0, +0},
        {+1, +1, +1},
        {+1, +2, +2},
        {+1, std::numeric_limits<Integer::ValueType>::max(), std::numeric_limits<Integer::ValueType>::max()},
        {+1, Integer::PositiveInfinity(), Integer::PositiveInfinity()},

        {+2, Integer::Undefined(), Integer::Undefined()},
        {+2, Integer::NegativeInfinity(), Integer::NegativeInfinity()},
        {+2, std::numeric_limits<Integer::ValueType>::min(), Integer::NegativeInfinity()},
        {+2, -2, -4},
        {+2, -1, -2},
        {+2, +0, +0},
        {+2, +1, +2},
        {+2, +2, +4},
        {+2, std::numeric_limits<Integer::ValueType>::max(), Integer::PositiveInfinity()},
        {+2, Integer::PositiveInfinity(), Integer::PositiveInfinity()},

        {+1073741823, Integer::Undefined(), Integer::Undefined()},
        {+1073741823, Integer::NegativeInfinity(), Integer::NegativeInfinity()},
        {+1073741823, std::numeric_limits<Integer::ValueType>::min(), Integer::NegativeInfinity()},
        {+1073741823, -3, Integer::NegativeInfinity()},
        {+1073741823, -2, -2147483646},
        {+1073741823, -1, -1073741823},
        {+1073741823, +0, +0},
        {+1073741823, +1, +1073741823},
        {+1073741823, +2, +2147483646},
        {+1073741823, +3, Integer::PositiveInfinity()},
        {+1073741823, std::numeric_limits<Integer::ValueType>::max(), Integer::PositiveInfinity()},
        {+1073741823, Integer::PositiveInfinity(), Integer::PositiveInfinity()},

        {std::numeric_limits<Integer::ValueType>::max(), Integer::Undefined(), Integer::Undefined()},
        {std::numeric_limits<Integer::ValueType>::max(), Integer::NegativeInfinity(), Integer::NegativeInfinity()},
        {std::numeric_limits<Integer::ValueType>::max(), std::numeric_limits<Integer::ValueType>::min(), Integer::NegativeInfinity()},
        {std::numeric_limits<Integer::ValueType>::max(), -2, Integer::NegativeInfinity()},
        {std::numeric_limits<Integer::ValueType>::max(), -1, -std::numeric_limits<Integer::ValueType>::max()},
        {std::numeric_limits<Integer::ValueType>::max(), +0, +0},
        {std::numeric_limits<Integer::ValueType>::max(), +1, std::numeric_limits<Integer::ValueType>::max()},
        {std::numeric_limits<Integer::ValueType>::max(), +2, Integer::PositiveInfinity()},
        {std::numeric_limits<Integer::ValueType>::max(), std::numeric_limits<Integer::ValueType>::max(), Integer::PositiveInfinity()},
        {std::numeric_limits<Integer::ValueType>::max(), Integer::PositiveInfinity(), Integer::PositiveInfinity()},

        {Integer::PositiveInfinity(), Integer::Undefined(), Integer::Undefined()},
        {Integer::PositiveInfinity(), Integer::NegativeInfinity(), Integer::NegativeInfinity()},
        {Integer::PositiveInfinity(), std::numeric_limits<Integer::ValueType>::min(), Integer::NegativeInfinity()},
        {Integer::PositiveInfinity(), -2, Integer::NegativeInfinity()},
        {Integer::PositiveInfinity(), -1, Integer::NegativeInfinity()},
        {Integer::PositiveInfinity(), +0, Integer::Undefined()},
        {Integer::PositiveInfinity(), +1, Integer::PositiveInfinity()},
        {Integer::PositiveInfinity(), +2, Integer::PositiveInfinity()},
        {Integer::PositiveInfinity(), std::numeric_limits<Integer::ValueType>::max(), Integer::PositiveInfinity()},
        {Integer::PositiveInfinity(), Integer::PositiveInfinity(), Integer::PositiveInfinity()}

    } ;

    for (const auto& testCase : testCases)
    {

        const Integer& a = testCase.first ;
        const Integer& b = testCase.second ;
        const Integer& c = testCase.third ;
        
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

TEST(Spacer_Core_Types_Integer, DivisionOperator)
{

    using spacer::core::types::Integer ;
    using spacer::core::ctnr::Triple ;
    using spacer::core::ctnr::Array ;

    Array<Triple<Integer, Integer, Integer>> testCases =
    {

        {Integer::Undefined(), Integer::Undefined(), Integer::Undefined()},
        {Integer::Undefined(), Integer::NegativeInfinity(), Integer::Undefined()},
        {Integer::Undefined(), std::numeric_limits<Integer::ValueType>::min(), Integer::Undefined()},
        {Integer::Undefined(), -2, Integer::Undefined()},
        {Integer::Undefined(), -1, Integer::Undefined()},
        {Integer::Undefined(), +0, Integer::Undefined()},
        {Integer::Undefined(), +1, Integer::Undefined()},
        {Integer::Undefined(), +2, Integer::Undefined()},
        {Integer::Undefined(), std::numeric_limits<Integer::ValueType>::max(), Integer::Undefined()},
        {Integer::Undefined(), Integer::PositiveInfinity(), Integer::Undefined()},

        {Integer::NegativeInfinity(), Integer::Undefined(), Integer::Undefined()},
        {Integer::NegativeInfinity(), Integer::NegativeInfinity(), Integer::Undefined()},
        {Integer::NegativeInfinity(), std::numeric_limits<Integer::ValueType>::min(), Integer::PositiveInfinity()},
        {Integer::NegativeInfinity(), -2, Integer::PositiveInfinity()},
        {Integer::NegativeInfinity(), -1, Integer::PositiveInfinity()},
        {Integer::NegativeInfinity(), +0, Integer::Undefined()},
        {Integer::NegativeInfinity(), +1, Integer::NegativeInfinity()},
        {Integer::NegativeInfinity(), +2, Integer::NegativeInfinity()},
        {Integer::NegativeInfinity(), std::numeric_limits<Integer::ValueType>::max(), Integer::NegativeInfinity()},
        {Integer::NegativeInfinity(), Integer::PositiveInfinity(), Integer::Undefined()},

        {std::numeric_limits<Integer::ValueType>::min(), Integer::Undefined(), Integer::Undefined()},
        {std::numeric_limits<Integer::ValueType>::min(), Integer::NegativeInfinity(), +0},
        {std::numeric_limits<Integer::ValueType>::min(), std::numeric_limits<Integer::ValueType>::min(), 1},
        {std::numeric_limits<Integer::ValueType>::min(), -2, std::numeric_limits<Integer::ValueType>::min() / -2},
        {std::numeric_limits<Integer::ValueType>::min(), -1, Integer::PositiveInfinity()},
        {std::numeric_limits<Integer::ValueType>::min(), +0, Integer::Undefined()},
        {std::numeric_limits<Integer::ValueType>::min(), +1, std::numeric_limits<Integer::ValueType>::min()},
        {std::numeric_limits<Integer::ValueType>::min(), +2, std::numeric_limits<Integer::ValueType>::min() / 2},
        {std::numeric_limits<Integer::ValueType>::min(), std::numeric_limits<Integer::ValueType>::max(), -1},
        {std::numeric_limits<Integer::ValueType>::min(), Integer::PositiveInfinity(), +0},

        {-2, Integer::Undefined(), Integer::Undefined()},
        {-2, Integer::NegativeInfinity(), +0},
        {-2, std::numeric_limits<Integer::ValueType>::min(), +0},
        {-2, -2, +1},
        {-2, -1, +2},
        {-2, +0, Integer::Undefined()},
        {-2, +1, -2},
        {-2, +2, -1},
        {-2, std::numeric_limits<Integer::ValueType>::max(), +0},
        {-2, Integer::PositiveInfinity(), +0},
        
        {-1, Integer::Undefined(), Integer::Undefined()},
        {-1, Integer::NegativeInfinity(), +0},
        {-1, std::numeric_limits<Integer::ValueType>::min(), +0},
        {-1, -2, +0},
        {-1, -1, +1},
        {-1, +0, Integer::Undefined()},
        {-1, +1, -1},
        {-1, +2, +0},
        {-1, std::numeric_limits<Integer::ValueType>::max(), +0},
        {-1, Integer::PositiveInfinity(), +0},

        {+0, Integer::Undefined(), Integer::Undefined()},
        {+0, Integer::NegativeInfinity(), +0},
        {+0, std::numeric_limits<Integer::ValueType>::min(), +0},
        {+0, -2, +0},
        {+0, -1, +0},
        {+0, +0, Integer::Undefined()},
        {+0, +1, +0},
        {+0, +2, +0},
        {+0, std::numeric_limits<Integer::ValueType>::max(), +0},
        {+0, Integer::PositiveInfinity(), +0},

        {+1, Integer::Undefined(), Integer::Undefined()},
        {+1, Integer::NegativeInfinity(), +0},
        {+1, std::numeric_limits<Integer::ValueType>::min(), +0},
        {+1, -2, +0},
        {+1, -1, -1},
        {+1, +0, Integer::Undefined()},
        {+1, +1, +1},
        {+1, +2, +0},
        {+1, std::numeric_limits<Integer::ValueType>::max(), +0},
        {+1, Integer::PositiveInfinity(), +0},

        {+2, Integer::Undefined(), Integer::Undefined()},
        {+2, Integer::NegativeInfinity(), +0},
        {+2, std::numeric_limits<Integer::ValueType>::min(), +0},
        {+2, -2, -1},
        {+2, -1, -2},
        {+2, +0, Integer::Undefined()},
        {+2, +1, +2},
        {+2, +2, +1},
        {+2, std::numeric_limits<Integer::ValueType>::max(), +0},
        {+2, Integer::PositiveInfinity(), +0},

        {std::numeric_limits<Integer::ValueType>::max(), Integer::Undefined(), Integer::Undefined()},
        {std::numeric_limits<Integer::ValueType>::max(), Integer::NegativeInfinity(), +0},
        {std::numeric_limits<Integer::ValueType>::max(), std::numeric_limits<Integer::ValueType>::min(), +0},
        {std::numeric_limits<Integer::ValueType>::max(), -2, std::numeric_limits<Integer::ValueType>::max() / -2},
        {std::numeric_limits<Integer::ValueType>::max(), -1, std::numeric_limits<Integer::ValueType>::max() / -1},
        {std::numeric_limits<Integer::ValueType>::max(), +0, Integer::Undefined()},
        {std::numeric_limits<Integer::ValueType>::max(), +1, std::numeric_limits<Integer::ValueType>::max()},
        {std::numeric_limits<Integer::ValueType>::max(), +2, std::numeric_limits<Integer::ValueType>::max() / 2},
        {std::numeric_limits<Integer::ValueType>::max(), std::numeric_limits<Integer::ValueType>::max(), +1},
        {std::numeric_limits<Integer::ValueType>::max(), Integer::PositiveInfinity(), +0},

        {Integer::PositiveInfinity(), Integer::Undefined(), Integer::Undefined()},
        {Integer::PositiveInfinity(), Integer::NegativeInfinity(), Integer::Undefined()},
        {Integer::PositiveInfinity(), std::numeric_limits<Integer::ValueType>::min(), Integer::NegativeInfinity()},
        {Integer::PositiveInfinity(), -2, Integer::NegativeInfinity()},
        {Integer::PositiveInfinity(), -1, Integer::NegativeInfinity()},
        {Integer::PositiveInfinity(), +0, Integer::Undefined()},
        {Integer::PositiveInfinity(), +1, Integer::PositiveInfinity()},
        {Integer::PositiveInfinity(), +2, Integer::PositiveInfinity()},
        {Integer::PositiveInfinity(), std::numeric_limits<Integer::ValueType>::max(), Integer::PositiveInfinity()},
        {Integer::PositiveInfinity(), Integer::PositiveInfinity(), Integer::Undefined()}

    } ;

    for (const auto& testCase : testCases)
    {

        const Integer& a = testCase.first ;
        const Integer& b = testCase.second ;
        const Integer& c = testCase.third ;
        
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

TEST(Spacer_Core_Types_Integer, ModuloOperator)
{

    using spacer::core::types::Integer ;
    using spacer::core::ctnr::Triple ;
    using spacer::core::ctnr::Array ;

    Array<Triple<Integer, Integer, Integer>> testCases =
    {

        {Integer::Undefined(), Integer::Undefined(), Integer::Undefined()},
        {Integer::Undefined(), Integer::NegativeInfinity(), Integer::Undefined()},
        {Integer::Undefined(), std::numeric_limits<Integer::ValueType>::min(), Integer::Undefined()},
        {Integer::Undefined(), -2, Integer::Undefined()},
        {Integer::Undefined(), -1, Integer::Undefined()},
        {Integer::Undefined(), +0, Integer::Undefined()},
        {Integer::Undefined(), +1, Integer::Undefined()},
        {Integer::Undefined(), +2, Integer::Undefined()},
        {Integer::Undefined(), std::numeric_limits<Integer::ValueType>::max(), Integer::Undefined()},
        {Integer::Undefined(), Integer::PositiveInfinity(), Integer::Undefined()},

        {Integer::NegativeInfinity(), Integer::Undefined(), Integer::Undefined()},
        {Integer::NegativeInfinity(), Integer::NegativeInfinity(), Integer::Undefined()},
        {Integer::NegativeInfinity(), std::numeric_limits<Integer::ValueType>::min(), Integer::Undefined()},
        {Integer::NegativeInfinity(), -2, Integer::Undefined()},
        {Integer::NegativeInfinity(), -1, +0},
        {Integer::NegativeInfinity(), +0, Integer::Undefined()},
        {Integer::NegativeInfinity(), +1, +0},
        {Integer::NegativeInfinity(), +2, Integer::Undefined()},
        {Integer::NegativeInfinity(), std::numeric_limits<Integer::ValueType>::max(), Integer::Undefined()},
        {Integer::NegativeInfinity(), Integer::PositiveInfinity(), Integer::Undefined()},

        {std::numeric_limits<Integer::ValueType>::min(), Integer::Undefined(), Integer::Undefined()},
        {std::numeric_limits<Integer::ValueType>::min(), Integer::NegativeInfinity(), std::numeric_limits<Integer::ValueType>::min()},
        {std::numeric_limits<Integer::ValueType>::min(), std::numeric_limits<Integer::ValueType>::min(), +0},
        {std::numeric_limits<Integer::ValueType>::min(), -3, -2},
        {std::numeric_limits<Integer::ValueType>::min(), -2, +0},
        {std::numeric_limits<Integer::ValueType>::min(), -1, +0},
        {std::numeric_limits<Integer::ValueType>::min(), +0, Integer::Undefined()},
        {std::numeric_limits<Integer::ValueType>::min(), +1, +0},
        {std::numeric_limits<Integer::ValueType>::min(), +2, +0},
        {std::numeric_limits<Integer::ValueType>::min(), +3, -2},
        {std::numeric_limits<Integer::ValueType>::min(), std::numeric_limits<Integer::ValueType>::max(), -1},
        {std::numeric_limits<Integer::ValueType>::min(), Integer::PositiveInfinity(), std::numeric_limits<Integer::ValueType>::min()},

        {-2, Integer::Undefined(), Integer::Undefined()},
        {-2, Integer::NegativeInfinity(), -2},
        {-2, std::numeric_limits<Integer::ValueType>::min(), -2},
        {-2, -3, -2},
        {-2, -2, +0},
        {-2, -1, +0},
        {-2, +0, Integer::Undefined()},
        {-2, +1, +0},
        {-2, +2, +0},
        {-2, +3, -2},
        {-2, std::numeric_limits<Integer::ValueType>::max(), -2},
        {-2, Integer::PositiveInfinity(), -2},
        
        {-1, Integer::Undefined(), Integer::Undefined()},
        {-1, Integer::NegativeInfinity(), -1},
        {-1, std::numeric_limits<Integer::ValueType>::min(), -1},
        {-1, -3, -1},
        {-1, -2, -1},
        {-1, -1, +0},
        {-1, +0, Integer::Undefined()},
        {-1, +1, +0},
        {-1, +2, -1},
        {-1, +3, -1},
        {-1, std::numeric_limits<Integer::ValueType>::max(), -1},
        {-1, Integer::PositiveInfinity(), -1},

        {+0, Integer::Undefined(), Integer::Undefined()},
        {+0, Integer::NegativeInfinity(), +0},
        {+0, std::numeric_limits<Integer::ValueType>::min(), +0},
        {+0, -3, +0},
        {+0, -2, +0},
        {+0, -1, +0},
        {+0, +0, Integer::Undefined()},
        {+0, +1, +0},
        {+0, +2, +0},
        {+0, +3, +0},
        {+0, std::numeric_limits<Integer::ValueType>::max(), +0},
        {+0, Integer::PositiveInfinity(), +0},

        {+1, Integer::Undefined(), Integer::Undefined()},
        {+1, Integer::NegativeInfinity(), +1},
        {+1, std::numeric_limits<Integer::ValueType>::min(), +1},
        {+1, -3, +1},
        {+1, -2, +1},
        {+1, -1, +0},
        {+1, +0, Integer::Undefined()},
        {+1, +1, +0},
        {+1, +2, +1},
        {+1, +3, +1},
        {+1, std::numeric_limits<Integer::ValueType>::max(), +1},
        {+1, Integer::PositiveInfinity(), +1},

        {+2, Integer::Undefined(), Integer::Undefined()},
        {+2, Integer::NegativeInfinity(), +2},
        {+2, std::numeric_limits<Integer::ValueType>::min(), +2},
        {+2, -3, +2},
        {+2, -2, +0},
        {+2, -1, +0},
        {+2, +0, Integer::Undefined()},
        {+2, +1, +0},
        {+2, +2, +0},
        {+2, +3, +2},
        {+2, std::numeric_limits<Integer::ValueType>::max(), +2},
        {+2, Integer::PositiveInfinity(), +2},

        {std::numeric_limits<Integer::ValueType>::max(), Integer::Undefined(), Integer::Undefined()},
        {std::numeric_limits<Integer::ValueType>::max(), Integer::NegativeInfinity(), std::numeric_limits<Integer::ValueType>::max()},
        {std::numeric_limits<Integer::ValueType>::max(), std::numeric_limits<Integer::ValueType>::min(), std::numeric_limits<Integer::ValueType>::max()},
        {std::numeric_limits<Integer::ValueType>::max(), -2, +1},
        {std::numeric_limits<Integer::ValueType>::max(), -1, +0},
        {std::numeric_limits<Integer::ValueType>::max(), +0, Integer::Undefined()},
        {std::numeric_limits<Integer::ValueType>::max(), +1, +0},
        {std::numeric_limits<Integer::ValueType>::max(), +2, +1},
        {std::numeric_limits<Integer::ValueType>::max(), std::numeric_limits<Integer::ValueType>::max(), +0},
        {std::numeric_limits<Integer::ValueType>::max(), Integer::PositiveInfinity(), std::numeric_limits<Integer::ValueType>::max()},

        {Integer::PositiveInfinity(), Integer::Undefined(), Integer::Undefined()},
        {Integer::PositiveInfinity(), Integer::NegativeInfinity(), Integer::Undefined()},
        {Integer::PositiveInfinity(), std::numeric_limits<Integer::ValueType>::min(), Integer::Undefined()},
        {Integer::PositiveInfinity(), -2, Integer::Undefined()},
        {Integer::PositiveInfinity(), -1, +0},
        {Integer::PositiveInfinity(), +0, Integer::Undefined()},
        {Integer::PositiveInfinity(), +1, +0},
        {Integer::PositiveInfinity(), +2, Integer::Undefined()},
        {Integer::PositiveInfinity(), std::numeric_limits<Integer::ValueType>::max(), Integer::Undefined()},
        {Integer::PositiveInfinity(), Integer::PositiveInfinity(), Integer::Undefined()}

    } ;

    for (const auto& testCase : testCases)
    {

        const Integer& a = testCase.first ;
        const Integer& b = testCase.second ;
        const Integer& c = testCase.third ;
        
        if (c.isDefined())
        {

            if (c.isPositiveInfinity())
            {
                EXPECT_TRUE((a % b).isPositiveInfinity()) ;
            }
            else if (c.isNegativeInfinity())
            {
                EXPECT_TRUE((a % b).isNegativeInfinity()) ;
            }
            else
            {
                EXPECT_EQ(c, a % b) ;
            }

        }
        else
        {
            EXPECT_FALSE((a % b).isDefined()) ;
        }

    }

}

TEST(Spacer_Core_Types_Integer, AdditionAssignmentOperator)
{

    using spacer::core::types::Integer ;
    using spacer::core::ctnr::Triple ;
    using spacer::core::ctnr::Array ;

    Array<Triple<Integer, Integer, Integer>> testCases =
    {

        {Integer::Undefined(), Integer::Undefined(), Integer::Undefined()},
        {Integer::Undefined(), Integer::NegativeInfinity(), Integer::Undefined()},
        {Integer::Undefined(), std::numeric_limits<Integer::ValueType>::min(), Integer::Undefined()},
        {Integer::Undefined(), -2, Integer::Undefined()},
        {Integer::Undefined(), -1, Integer::Undefined()},
        {Integer::Undefined(), +0, Integer::Undefined()},
        {Integer::Undefined(), +1, Integer::Undefined()},
        {Integer::Undefined(), +2, Integer::Undefined()},
        {Integer::Undefined(), std::numeric_limits<Integer::ValueType>::max(), Integer::Undefined()},
        {Integer::Undefined(), Integer::PositiveInfinity(), Integer::Undefined()},

        {Integer::NegativeInfinity(), Integer::Undefined(), Integer::Undefined()},
        {Integer::NegativeInfinity(), Integer::NegativeInfinity(), Integer::NegativeInfinity()},
        {Integer::NegativeInfinity(), std::numeric_limits<Integer::ValueType>::min(), Integer::NegativeInfinity()},
        {Integer::NegativeInfinity(), -2, Integer::NegativeInfinity()},
        {Integer::NegativeInfinity(), -1, Integer::NegativeInfinity()},
        {Integer::NegativeInfinity(), +0, Integer::NegativeInfinity()},
        {Integer::NegativeInfinity(), +1, Integer::NegativeInfinity()},
        {Integer::NegativeInfinity(), +2, Integer::NegativeInfinity()},
        {Integer::NegativeInfinity(), std::numeric_limits<Integer::ValueType>::max(), Integer::NegativeInfinity()},
        {Integer::NegativeInfinity(), Integer::PositiveInfinity(), Integer::Undefined()},

        {std::numeric_limits<Integer::ValueType>::min(), Integer::Undefined(), Integer::Undefined()},
        {std::numeric_limits<Integer::ValueType>::min(), Integer::NegativeInfinity(), Integer::NegativeInfinity()},
        {std::numeric_limits<Integer::ValueType>::min(), std::numeric_limits<Integer::ValueType>::min(), Integer::NegativeInfinity()},
        {std::numeric_limits<Integer::ValueType>::min(), -2, Integer::NegativeInfinity()},
        {std::numeric_limits<Integer::ValueType>::min(), -1, Integer::NegativeInfinity()},
        {std::numeric_limits<Integer::ValueType>::min(), +0, std::numeric_limits<Integer::ValueType>::min()},
        {std::numeric_limits<Integer::ValueType>::min(), +1, std::numeric_limits<Integer::ValueType>::min() + 1},
        {std::numeric_limits<Integer::ValueType>::min(), +2, std::numeric_limits<Integer::ValueType>::min() + 2},
        {std::numeric_limits<Integer::ValueType>::min(), std::numeric_limits<Integer::ValueType>::max(), std::numeric_limits<Integer::ValueType>::min() + std::numeric_limits<Integer::ValueType>::max()},
        {std::numeric_limits<Integer::ValueType>::min(), Integer::PositiveInfinity(), Integer::PositiveInfinity()},

        {-2, Integer::Undefined(), Integer::Undefined()},
        {-2, Integer::NegativeInfinity(), Integer::NegativeInfinity()},
        {-2, std::numeric_limits<Integer::ValueType>::min(), Integer::NegativeInfinity()},
        {-2, -2, -4},
        {-2, -1, -3},
        {-2, +0, -2},
        {-2, +1, -1},
        {-2, +2, +0},
        {-2, std::numeric_limits<Integer::ValueType>::max(), std::numeric_limits<Integer::ValueType>::max() - 2},
        {-2, Integer::PositiveInfinity(), Integer::PositiveInfinity()},

        {-1, Integer::Undefined(), Integer::Undefined()},
        {-1, Integer::NegativeInfinity(), Integer::NegativeInfinity()},
        {-1, std::numeric_limits<Integer::ValueType>::min(), Integer::NegativeInfinity()},
        {-1, -2, -3},
        {-1, -1, -2},
        {-1, +0, -1},
        {-1, +1, +0},
        {-1, +2, +1},
        {-1, std::numeric_limits<Integer::ValueType>::max(), std::numeric_limits<Integer::ValueType>::max() - 1},
        {-1, Integer::PositiveInfinity(), Integer::PositiveInfinity()},

        {+0, Integer::Undefined(), Integer::Undefined()},
        {+0, Integer::NegativeInfinity(), Integer::NegativeInfinity()},
        {+0, std::numeric_limits<Integer::ValueType>::min(), std::numeric_limits<Integer::ValueType>::min()},
        {+0, -2, -2},
        {+0, -1, -1},
        {+0, +0, +0},
        {+0, +1, +1},
        {+0, +2, +2},
        {+0, std::numeric_limits<Integer::ValueType>::max(), std::numeric_limits<Integer::ValueType>::max()},
        {+0, Integer::PositiveInfinity(), Integer::PositiveInfinity()},

        {+1, Integer::Undefined(), Integer::Undefined()},
        {+1, Integer::NegativeInfinity(), Integer::NegativeInfinity()},
        {+1, std::numeric_limits<Integer::ValueType>::min(), std::numeric_limits<Integer::ValueType>::min() + 1},
        {+1, -2, -1},
        {+1, -1, +0},
        {+1, +0, +1},
        {+1, +1, +2},
        {+1, +2, +3},
        {+1, std::numeric_limits<Integer::ValueType>::max(), Integer::PositiveInfinity()},
        {+1, Integer::PositiveInfinity(), Integer::PositiveInfinity()},
        
        {+2, Integer::Undefined(), Integer::Undefined()},
        {+2, Integer::NegativeInfinity(), Integer::NegativeInfinity()},
        {+2, std::numeric_limits<Integer::ValueType>::min(), std::numeric_limits<Integer::ValueType>::min() + 2},
        {+2, -2, +0},
        {+2, -1, +1},
        {+2, +0, +2},
        {+2, +1, +3},
        {+2, +2, +4},
        {+2, std::numeric_limits<Integer::ValueType>::max(), Integer::PositiveInfinity()},
        {+2, Integer::PositiveInfinity(), Integer::PositiveInfinity()},

        {std::numeric_limits<Integer::ValueType>::max(), Integer::Undefined(), Integer::Undefined()},
        {std::numeric_limits<Integer::ValueType>::max(), Integer::NegativeInfinity(), Integer::NegativeInfinity()},
        {std::numeric_limits<Integer::ValueType>::max(), std::numeric_limits<Integer::ValueType>::min(), std::numeric_limits<Integer::ValueType>::max() + std::numeric_limits<Integer::ValueType>::min()},
        {std::numeric_limits<Integer::ValueType>::max(), -2, std::numeric_limits<Integer::ValueType>::max() - 2},
        {std::numeric_limits<Integer::ValueType>::max(), -1, std::numeric_limits<Integer::ValueType>::max() - 1},
        {std::numeric_limits<Integer::ValueType>::max(), +0, std::numeric_limits<Integer::ValueType>::max()},
        {std::numeric_limits<Integer::ValueType>::max(), +1, Integer::PositiveInfinity()},
        {std::numeric_limits<Integer::ValueType>::max(), +2, Integer::PositiveInfinity()},
        {std::numeric_limits<Integer::ValueType>::max(), std::numeric_limits<Integer::ValueType>::max(), Integer::PositiveInfinity()},
        {std::numeric_limits<Integer::ValueType>::max(), Integer::PositiveInfinity(), Integer::PositiveInfinity()},

        {Integer::PositiveInfinity(), Integer::Undefined(), Integer::Undefined()},
        {Integer::PositiveInfinity(), Integer::NegativeInfinity(), Integer::Undefined()},
        {Integer::PositiveInfinity(), std::numeric_limits<Integer::ValueType>::min(), Integer::PositiveInfinity()},
        {Integer::PositiveInfinity(), -2, Integer::PositiveInfinity()},
        {Integer::PositiveInfinity(), -1, Integer::PositiveInfinity()},
        {Integer::PositiveInfinity(), +0, Integer::PositiveInfinity()},
        {Integer::PositiveInfinity(), +1, Integer::PositiveInfinity()},
        {Integer::PositiveInfinity(), +2, Integer::PositiveInfinity()},
        {Integer::PositiveInfinity(), std::numeric_limits<Integer::ValueType>::max(), Integer::PositiveInfinity()},
        {Integer::PositiveInfinity(), Integer::PositiveInfinity(), Integer::PositiveInfinity()}

    } ;

    for (auto& testCase : testCases)
    {

        Integer& a = testCase.first ;
        const Integer& b = testCase.second ;
        const Integer& c = testCase.third ;

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

TEST(Spacer_Core_Types_Integer, SubtractionAssignmentOperator)
{

    using spacer::core::types::Integer ;
    using spacer::core::ctnr::Triple ;
    using spacer::core::ctnr::Array ;

    Array<Triple<Integer, Integer, Integer>> testCases =
    {

        {Integer::Undefined(), Integer::Undefined(), Integer::Undefined()},
        {Integer::Undefined(), Integer::NegativeInfinity(), Integer::Undefined()},
        {Integer::Undefined(), std::numeric_limits<Integer::ValueType>::min(), Integer::Undefined()},
        {Integer::Undefined(), -2, Integer::Undefined()},
        {Integer::Undefined(), -1, Integer::Undefined()},
        {Integer::Undefined(), +0, Integer::Undefined()},
        {Integer::Undefined(), +1, Integer::Undefined()},
        {Integer::Undefined(), +2, Integer::Undefined()},
        {Integer::Undefined(), std::numeric_limits<Integer::ValueType>::max(), Integer::Undefined()},
        {Integer::Undefined(), Integer::PositiveInfinity(), Integer::Undefined()},

        {Integer::NegativeInfinity(), Integer::Undefined(), Integer::Undefined()},
        {Integer::NegativeInfinity(), Integer::NegativeInfinity(), Integer::Undefined()},
        {Integer::NegativeInfinity(), std::numeric_limits<Integer::ValueType>::min(), Integer::NegativeInfinity()},
        {Integer::NegativeInfinity(), -2, Integer::NegativeInfinity()},
        {Integer::NegativeInfinity(), -1, Integer::NegativeInfinity()},
        {Integer::NegativeInfinity(), +0, Integer::NegativeInfinity()},
        {Integer::NegativeInfinity(), +1, Integer::NegativeInfinity()},
        {Integer::NegativeInfinity(), +2, Integer::NegativeInfinity()},
        {Integer::NegativeInfinity(), std::numeric_limits<Integer::ValueType>::max(), Integer::NegativeInfinity()},
        {Integer::NegativeInfinity(), Integer::PositiveInfinity(), Integer::NegativeInfinity()},

        {std::numeric_limits<Integer::ValueType>::min(), Integer::Undefined(), Integer::Undefined()},
        {std::numeric_limits<Integer::ValueType>::min(), Integer::NegativeInfinity(), Integer::PositiveInfinity()},
        {std::numeric_limits<Integer::ValueType>::min(), std::numeric_limits<Integer::ValueType>::min(), +0},
        {std::numeric_limits<Integer::ValueType>::min(), -2, std::numeric_limits<Integer::ValueType>::min() + 2},
        {std::numeric_limits<Integer::ValueType>::min(), -1, std::numeric_limits<Integer::ValueType>::min() + 1},
        {std::numeric_limits<Integer::ValueType>::min(), +0, std::numeric_limits<Integer::ValueType>::min()},
        {std::numeric_limits<Integer::ValueType>::min(), +1, Integer::NegativeInfinity()},
        {std::numeric_limits<Integer::ValueType>::min(), +2, Integer::NegativeInfinity()},
        {std::numeric_limits<Integer::ValueType>::min(), std::numeric_limits<Integer::ValueType>::max(), Integer::NegativeInfinity()},
        {std::numeric_limits<Integer::ValueType>::min(), Integer::PositiveInfinity(), Integer::NegativeInfinity()},

        {-2, Integer::Undefined(), Integer::Undefined()},
        {-2, Integer::NegativeInfinity(), Integer::PositiveInfinity()},
        {-2, std::numeric_limits<Integer::ValueType>::min(), -2 - std::numeric_limits<Integer::ValueType>::min()},
        {-2, -2, +0},
        {-2, -1, -1},
        {-2, +0, -2},
        {-2, +1, -3},
        {-2, +2, -4},
        {-2, std::numeric_limits<Integer::ValueType>::max(), Integer::NegativeInfinity()},
        {-2, Integer::PositiveInfinity(), Integer::NegativeInfinity()},

        {-1, Integer::Undefined(), Integer::Undefined()},
        {-1, Integer::NegativeInfinity(), Integer::PositiveInfinity()},
        {-1, std::numeric_limits<Integer::ValueType>::min(), std::numeric_limits<Integer::ValueType>::max()},
        {-1, -2, +1},
        {-1, -1, +0},
        {-1, +0, -1},
        {-1, +1, -2},
        {-1, +2, -3},
        {-1, std::numeric_limits<Integer::ValueType>::max(), std::numeric_limits<Integer::ValueType>::min()},
        {-1, Integer::PositiveInfinity(), Integer::NegativeInfinity()},

        {+0, Integer::Undefined(), Integer::Undefined()},
        {+0, Integer::NegativeInfinity(), Integer::PositiveInfinity()},
        {+0, std::numeric_limits<Integer::ValueType>::min(), Integer::PositiveInfinity()},
        {+0, -2, +2},
        {+0, -1, +1},
        {+0, +0, +0},
        {+0, +1, -1},
        {+0, +2, -2},
        {+0, std::numeric_limits<Integer::ValueType>::max(), std::numeric_limits<Integer::ValueType>::min() + 1},
        {+0, Integer::PositiveInfinity(), Integer::NegativeInfinity()},

        {+1, Integer::Undefined(), Integer::Undefined()},
        {+1, Integer::NegativeInfinity(), Integer::PositiveInfinity()},
        {+1, std::numeric_limits<Integer::ValueType>::min(), Integer::PositiveInfinity()},
        {+1, -2, +3},
        {+1, -1, +2},
        {+1, +0, +1},
        {+1, +1, +0},
        {+1, +2, -1},
        {+1, std::numeric_limits<Integer::ValueType>::max(), std::numeric_limits<Integer::ValueType>::min() + 2},
        {+1, Integer::PositiveInfinity(), Integer::NegativeInfinity()},
        
        {+2, Integer::Undefined(), Integer::Undefined()},
        {+2, Integer::NegativeInfinity(), Integer::PositiveInfinity()},
        {+2, std::numeric_limits<Integer::ValueType>::min(), Integer::PositiveInfinity()},
        {+2, -2, +4},
        {+2, -1, +3},
        {+2, +0, +2},
        {+2, +1, +1},
        {+2, +2, +0},
        {+2, std::numeric_limits<Integer::ValueType>::max(), std::numeric_limits<Integer::ValueType>::min() + 3},
        {+2, Integer::PositiveInfinity(), Integer::NegativeInfinity()},

        {std::numeric_limits<Integer::ValueType>::max(), Integer::Undefined(), Integer::Undefined()},
        {std::numeric_limits<Integer::ValueType>::max(), Integer::NegativeInfinity(), Integer::PositiveInfinity()},
        {std::numeric_limits<Integer::ValueType>::max(), std::numeric_limits<Integer::ValueType>::min(), Integer::PositiveInfinity()},
        {std::numeric_limits<Integer::ValueType>::max(), -2, Integer::PositiveInfinity()},
        {std::numeric_limits<Integer::ValueType>::max(), -1, Integer::PositiveInfinity()},
        {std::numeric_limits<Integer::ValueType>::max(), +0, std::numeric_limits<Integer::ValueType>::max()},
        {std::numeric_limits<Integer::ValueType>::max(), +1, std::numeric_limits<Integer::ValueType>::max() - 1},
        {std::numeric_limits<Integer::ValueType>::max(), +2, std::numeric_limits<Integer::ValueType>::max() - 2},
        {std::numeric_limits<Integer::ValueType>::max(), std::numeric_limits<Integer::ValueType>::max(), +0},
        {std::numeric_limits<Integer::ValueType>::max(), Integer::PositiveInfinity(), Integer::NegativeInfinity()},

        {Integer::PositiveInfinity(), Integer::Undefined(), Integer::Undefined()},
        {Integer::PositiveInfinity(), Integer::NegativeInfinity(), Integer::PositiveInfinity()},
        {Integer::PositiveInfinity(), std::numeric_limits<Integer::ValueType>::min(), Integer::PositiveInfinity()},
        {Integer::PositiveInfinity(), -2, Integer::PositiveInfinity()},
        {Integer::PositiveInfinity(), -1, Integer::PositiveInfinity()},
        {Integer::PositiveInfinity(), +0, Integer::PositiveInfinity()},
        {Integer::PositiveInfinity(), +1, Integer::PositiveInfinity()},
        {Integer::PositiveInfinity(), +2, Integer::PositiveInfinity()},
        {Integer::PositiveInfinity(), std::numeric_limits<Integer::ValueType>::max(), Integer::PositiveInfinity()},
        {Integer::PositiveInfinity(), Integer::PositiveInfinity(), Integer::Undefined()}

    } ;

    for (auto& testCase : testCases)
    {

        Integer& a = testCase.first ;
        const Integer& b = testCase.second ;
        const Integer& c = testCase.third ;

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

TEST(Spacer_Core_Types_Integer, MultiplicationAssignmentOperator)
{

    using spacer::core::types::Integer ;
    using spacer::core::ctnr::Triple ;
    using spacer::core::ctnr::Array ;

    Array<Triple<Integer, Integer, Integer>> testCases =
    {

        {Integer::Undefined(), Integer::Undefined(), Integer::Undefined()},
        {Integer::Undefined(), Integer::NegativeInfinity(), Integer::Undefined()},
        {Integer::Undefined(), std::numeric_limits<Integer::ValueType>::min(), Integer::Undefined()},
        {Integer::Undefined(), -2, Integer::Undefined()},
        {Integer::Undefined(), -1, Integer::Undefined()},
        {Integer::Undefined(), +0, Integer::Undefined()},
        {Integer::Undefined(), +1, Integer::Undefined()},
        {Integer::Undefined(), +2, Integer::Undefined()},
        {Integer::Undefined(), std::numeric_limits<Integer::ValueType>::max(), Integer::Undefined()},
        {Integer::Undefined(), Integer::PositiveInfinity(), Integer::Undefined()},

        {Integer::NegativeInfinity(), Integer::Undefined(), Integer::Undefined()},
        {Integer::NegativeInfinity(), Integer::NegativeInfinity(), Integer::PositiveInfinity()},
        {Integer::NegativeInfinity(), std::numeric_limits<Integer::ValueType>::min(), Integer::PositiveInfinity()},
        {Integer::NegativeInfinity(), -2, Integer::PositiveInfinity()},
        {Integer::NegativeInfinity(), -1, Integer::PositiveInfinity()},
        {Integer::NegativeInfinity(), +0, Integer::Undefined()},
        {Integer::NegativeInfinity(), +1, Integer::NegativeInfinity()},
        {Integer::NegativeInfinity(), +2, Integer::NegativeInfinity()},
        {Integer::NegativeInfinity(), std::numeric_limits<Integer::ValueType>::max(), Integer::NegativeInfinity()},
        {Integer::NegativeInfinity(), Integer::PositiveInfinity(), Integer::NegativeInfinity()},

        {std::numeric_limits<Integer::ValueType>::min(), Integer::Undefined(), Integer::Undefined()},
        {std::numeric_limits<Integer::ValueType>::min(), Integer::NegativeInfinity(), Integer::PositiveInfinity()},
        {std::numeric_limits<Integer::ValueType>::min(), std::numeric_limits<Integer::ValueType>::min(), Integer::PositiveInfinity()},
        {std::numeric_limits<Integer::ValueType>::min(), -2, Integer::PositiveInfinity()},
        {std::numeric_limits<Integer::ValueType>::min(), -1, Integer::PositiveInfinity()},
        {std::numeric_limits<Integer::ValueType>::min(), +0, +0},
        {std::numeric_limits<Integer::ValueType>::min(), +1, std::numeric_limits<Integer::ValueType>::min()},
        {std::numeric_limits<Integer::ValueType>::min(), +2, Integer::NegativeInfinity()},
        {std::numeric_limits<Integer::ValueType>::min(), std::numeric_limits<Integer::ValueType>::max(), Integer::NegativeInfinity()},
        {std::numeric_limits<Integer::ValueType>::min(), Integer::PositiveInfinity(), Integer::NegativeInfinity()},

        {-1073741823, Integer::Undefined(), Integer::Undefined()},
        {-1073741823, Integer::NegativeInfinity(), Integer::PositiveInfinity()},
        {-1073741823, std::numeric_limits<Integer::ValueType>::min(), Integer::PositiveInfinity()},
        {-1073741823, -3, Integer::PositiveInfinity()},
        {-1073741823, -2, +2147483646},
        {-1073741823, -1, +1073741823},
        {-1073741823, +0, +0},
        {-1073741823, +1, -1073741823},
        {-1073741823, +2, -2147483646},
        {-1073741823, +3, Integer::NegativeInfinity()},
        {-1073741823, std::numeric_limits<Integer::ValueType>::max(), Integer::NegativeInfinity()},
        {-1073741823, Integer::PositiveInfinity(), Integer::NegativeInfinity()},

        {-2, Integer::Undefined(), Integer::Undefined()},
        {-2, Integer::NegativeInfinity(), Integer::PositiveInfinity()},
        {-2, std::numeric_limits<Integer::ValueType>::min(), Integer::PositiveInfinity()},
        {-2, -2, +4},
        {-2, -1, +2},
        {-2, +0, +0},
        {-2, +1, -2},
        {-2, +2, -4},
        {-2, std::numeric_limits<Integer::ValueType>::max(), Integer::NegativeInfinity()},
        {-2, Integer::PositiveInfinity(), Integer::NegativeInfinity()},
        
        {-1, Integer::Undefined(), Integer::Undefined()},
        {-1, Integer::NegativeInfinity(), Integer::PositiveInfinity()},
        {-1, std::numeric_limits<Integer::ValueType>::min(), Integer::PositiveInfinity()},
        {-1, -2, +2},
        {-1, -1, +1},
        {-1, +0, +0},
        {-1, +1, -1},
        {-1, +2, -2},
        {-1, std::numeric_limits<Integer::ValueType>::max(), -std::numeric_limits<Integer::ValueType>::max()},
        {-1, Integer::PositiveInfinity(), Integer::NegativeInfinity()},

        {+0, Integer::Undefined(), Integer::Undefined()},
        {+0, Integer::NegativeInfinity(), Integer::Undefined()},
        {+0, std::numeric_limits<Integer::ValueType>::min(), +0},
        {+0, -2, +0},
        {+0, -1, +0},
        {+0, +0, +0},
        {+0, +1, +0},
        {+0, +2, +0},
        {+0, std::numeric_limits<Integer::ValueType>::max(), +0},
        {+0, Integer::PositiveInfinity(), Integer::Undefined()},

        {+1, Integer::Undefined(), Integer::Undefined()},
        {+1, Integer::NegativeInfinity(), Integer::NegativeInfinity()},
        {+1, std::numeric_limits<Integer::ValueType>::min(), std::numeric_limits<Integer::ValueType>::min()},
        {+1, -2, -2},
        {+1, -1, -1},
        {+1, +0, +0},
        {+1, +1, +1},
        {+1, +2, +2},
        {+1, std::numeric_limits<Integer::ValueType>::max(), std::numeric_limits<Integer::ValueType>::max()},
        {+1, Integer::PositiveInfinity(), Integer::PositiveInfinity()},

        {+2, Integer::Undefined(), Integer::Undefined()},
        {+2, Integer::NegativeInfinity(), Integer::NegativeInfinity()},
        {+2, std::numeric_limits<Integer::ValueType>::min(), Integer::NegativeInfinity()},
        {+2, -2, -4},
        {+2, -1, -2},
        {+2, +0, +0},
        {+2, +1, +2},
        {+2, +2, +4},
        {+2, std::numeric_limits<Integer::ValueType>::max(), Integer::PositiveInfinity()},
        {+2, Integer::PositiveInfinity(), Integer::PositiveInfinity()},

        {+1073741823, Integer::Undefined(), Integer::Undefined()},
        {+1073741823, Integer::NegativeInfinity(), Integer::NegativeInfinity()},
        {+1073741823, std::numeric_limits<Integer::ValueType>::min(), Integer::NegativeInfinity()},
        {+1073741823, -3, Integer::NegativeInfinity()},
        {+1073741823, -2, -2147483646},
        {+1073741823, -1, -1073741823},
        {+1073741823, +0, +0},
        {+1073741823, +1, +1073741823},
        {+1073741823, +2, +2147483646},
        {+1073741823, +3, Integer::PositiveInfinity()},
        {+1073741823, std::numeric_limits<Integer::ValueType>::max(), Integer::PositiveInfinity()},
        {+1073741823, Integer::PositiveInfinity(), Integer::PositiveInfinity()},

        {std::numeric_limits<Integer::ValueType>::max(), Integer::Undefined(), Integer::Undefined()},
        {std::numeric_limits<Integer::ValueType>::max(), Integer::NegativeInfinity(), Integer::NegativeInfinity()},
        {std::numeric_limits<Integer::ValueType>::max(), std::numeric_limits<Integer::ValueType>::min(), Integer::NegativeInfinity()},
        {std::numeric_limits<Integer::ValueType>::max(), -2, Integer::NegativeInfinity()},
        {std::numeric_limits<Integer::ValueType>::max(), -1, -std::numeric_limits<Integer::ValueType>::max()},
        {std::numeric_limits<Integer::ValueType>::max(), +0, +0},
        {std::numeric_limits<Integer::ValueType>::max(), +1, std::numeric_limits<Integer::ValueType>::max()},
        {std::numeric_limits<Integer::ValueType>::max(), +2, Integer::PositiveInfinity()},
        {std::numeric_limits<Integer::ValueType>::max(), std::numeric_limits<Integer::ValueType>::max(), Integer::PositiveInfinity()},
        {std::numeric_limits<Integer::ValueType>::max(), Integer::PositiveInfinity(), Integer::PositiveInfinity()},

        {Integer::PositiveInfinity(), Integer::Undefined(), Integer::Undefined()},
        {Integer::PositiveInfinity(), Integer::NegativeInfinity(), Integer::NegativeInfinity()},
        {Integer::PositiveInfinity(), std::numeric_limits<Integer::ValueType>::min(), Integer::NegativeInfinity()},
        {Integer::PositiveInfinity(), -2, Integer::NegativeInfinity()},
        {Integer::PositiveInfinity(), -1, Integer::NegativeInfinity()},
        {Integer::PositiveInfinity(), +0, Integer::Undefined()},
        {Integer::PositiveInfinity(), +1, Integer::PositiveInfinity()},
        {Integer::PositiveInfinity(), +2, Integer::PositiveInfinity()},
        {Integer::PositiveInfinity(), std::numeric_limits<Integer::ValueType>::max(), Integer::PositiveInfinity()},
        {Integer::PositiveInfinity(), Integer::PositiveInfinity(), Integer::PositiveInfinity()}

    } ;

    for (auto& testCase : testCases)
    {

        Integer& a = testCase.first ;
        const Integer& b = testCase.second ;
        const Integer& c = testCase.third ;

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

TEST(Spacer_Core_Types_Integer, DivisionAssignmentOperator)
{

    using spacer::core::types::Integer ;
    using spacer::core::ctnr::Triple ;
    using spacer::core::ctnr::Array ;

    Array<Triple<Integer, Integer, Integer>> testCases =
    {

        {Integer::Undefined(), Integer::Undefined(), Integer::Undefined()},
        {Integer::Undefined(), Integer::NegativeInfinity(), Integer::Undefined()},
        {Integer::Undefined(), std::numeric_limits<Integer::ValueType>::min(), Integer::Undefined()},
        {Integer::Undefined(), -2, Integer::Undefined()},
        {Integer::Undefined(), -1, Integer::Undefined()},
        {Integer::Undefined(), +0, Integer::Undefined()},
        {Integer::Undefined(), +1, Integer::Undefined()},
        {Integer::Undefined(), +2, Integer::Undefined()},
        {Integer::Undefined(), std::numeric_limits<Integer::ValueType>::max(), Integer::Undefined()},
        {Integer::Undefined(), Integer::PositiveInfinity(), Integer::Undefined()},

        {Integer::NegativeInfinity(), Integer::Undefined(), Integer::Undefined()},
        {Integer::NegativeInfinity(), Integer::NegativeInfinity(), Integer::Undefined()},
        {Integer::NegativeInfinity(), std::numeric_limits<Integer::ValueType>::min(), Integer::PositiveInfinity()},
        {Integer::NegativeInfinity(), -2, Integer::PositiveInfinity()},
        {Integer::NegativeInfinity(), -1, Integer::PositiveInfinity()},
        {Integer::NegativeInfinity(), +0, Integer::Undefined()},
        {Integer::NegativeInfinity(), +1, Integer::NegativeInfinity()},
        {Integer::NegativeInfinity(), +2, Integer::NegativeInfinity()},
        {Integer::NegativeInfinity(), std::numeric_limits<Integer::ValueType>::max(), Integer::NegativeInfinity()},
        {Integer::NegativeInfinity(), Integer::PositiveInfinity(), Integer::Undefined()},

        {std::numeric_limits<Integer::ValueType>::min(), Integer::Undefined(), Integer::Undefined()},
        {std::numeric_limits<Integer::ValueType>::min(), Integer::NegativeInfinity(), +0},
        {std::numeric_limits<Integer::ValueType>::min(), std::numeric_limits<Integer::ValueType>::min(), 1},
        {std::numeric_limits<Integer::ValueType>::min(), -2, std::numeric_limits<Integer::ValueType>::min() / -2},
        {std::numeric_limits<Integer::ValueType>::min(), -1, Integer::PositiveInfinity()},
        {std::numeric_limits<Integer::ValueType>::min(), +0, Integer::Undefined()},
        {std::numeric_limits<Integer::ValueType>::min(), +1, std::numeric_limits<Integer::ValueType>::min()},
        {std::numeric_limits<Integer::ValueType>::min(), +2, std::numeric_limits<Integer::ValueType>::min() / 2},
        {std::numeric_limits<Integer::ValueType>::min(), std::numeric_limits<Integer::ValueType>::max(), -1},
        {std::numeric_limits<Integer::ValueType>::min(), Integer::PositiveInfinity(), +0},

        {-2, Integer::Undefined(), Integer::Undefined()},
        {-2, Integer::NegativeInfinity(), +0},
        {-2, std::numeric_limits<Integer::ValueType>::min(), +0},
        {-2, -2, +1},
        {-2, -1, +2},
        {-2, +0, Integer::Undefined()},
        {-2, +1, -2},
        {-2, +2, -1},
        {-2, std::numeric_limits<Integer::ValueType>::max(), +0},
        {-2, Integer::PositiveInfinity(), +0},
        
        {-1, Integer::Undefined(), Integer::Undefined()},
        {-1, Integer::NegativeInfinity(), +0},
        {-1, std::numeric_limits<Integer::ValueType>::min(), +0},
        {-1, -2, +0},
        {-1, -1, +1},
        {-1, +0, Integer::Undefined()},
        {-1, +1, -1},
        {-1, +2, +0},
        {-1, std::numeric_limits<Integer::ValueType>::max(), +0},
        {-1, Integer::PositiveInfinity(), +0},

        {+0, Integer::Undefined(), Integer::Undefined()},
        {+0, Integer::NegativeInfinity(), +0},
        {+0, std::numeric_limits<Integer::ValueType>::min(), +0},
        {+0, -2, +0},
        {+0, -1, +0},
        {+0, +0, Integer::Undefined()},
        {+0, +1, +0},
        {+0, +2, +0},
        {+0, std::numeric_limits<Integer::ValueType>::max(), +0},
        {+0, Integer::PositiveInfinity(), +0},

        {+1, Integer::Undefined(), Integer::Undefined()},
        {+1, Integer::NegativeInfinity(), +0},
        {+1, std::numeric_limits<Integer::ValueType>::min(), +0},
        {+1, -2, +0},
        {+1, -1, -1},
        {+1, +0, Integer::Undefined()},
        {+1, +1, +1},
        {+1, +2, +0},
        {+1, std::numeric_limits<Integer::ValueType>::max(), +0},
        {+1, Integer::PositiveInfinity(), +0},

        {+2, Integer::Undefined(), Integer::Undefined()},
        {+2, Integer::NegativeInfinity(), +0},
        {+2, std::numeric_limits<Integer::ValueType>::min(), +0},
        {+2, -2, -1},
        {+2, -1, -2},
        {+2, +0, Integer::Undefined()},
        {+2, +1, +2},
        {+2, +2, +1},
        {+2, std::numeric_limits<Integer::ValueType>::max(), +0},
        {+2, Integer::PositiveInfinity(), +0},

        {std::numeric_limits<Integer::ValueType>::max(), Integer::Undefined(), Integer::Undefined()},
        {std::numeric_limits<Integer::ValueType>::max(), Integer::NegativeInfinity(), +0},
        {std::numeric_limits<Integer::ValueType>::max(), std::numeric_limits<Integer::ValueType>::min(), +0},
        {std::numeric_limits<Integer::ValueType>::max(), -2, std::numeric_limits<Integer::ValueType>::max() / -2},
        {std::numeric_limits<Integer::ValueType>::max(), -1, std::numeric_limits<Integer::ValueType>::max() / -1},
        {std::numeric_limits<Integer::ValueType>::max(), +0, Integer::Undefined()},
        {std::numeric_limits<Integer::ValueType>::max(), +1, std::numeric_limits<Integer::ValueType>::max()},
        {std::numeric_limits<Integer::ValueType>::max(), +2, std::numeric_limits<Integer::ValueType>::max() / 2},
        {std::numeric_limits<Integer::ValueType>::max(), std::numeric_limits<Integer::ValueType>::max(), +1},
        {std::numeric_limits<Integer::ValueType>::max(), Integer::PositiveInfinity(), +0},

        {Integer::PositiveInfinity(), Integer::Undefined(), Integer::Undefined()},
        {Integer::PositiveInfinity(), Integer::NegativeInfinity(), Integer::Undefined()},
        {Integer::PositiveInfinity(), std::numeric_limits<Integer::ValueType>::min(), Integer::NegativeInfinity()},
        {Integer::PositiveInfinity(), -2, Integer::NegativeInfinity()},
        {Integer::PositiveInfinity(), -1, Integer::NegativeInfinity()},
        {Integer::PositiveInfinity(), +0, Integer::Undefined()},
        {Integer::PositiveInfinity(), +1, Integer::PositiveInfinity()},
        {Integer::PositiveInfinity(), +2, Integer::PositiveInfinity()},
        {Integer::PositiveInfinity(), std::numeric_limits<Integer::ValueType>::max(), Integer::PositiveInfinity()},
        {Integer::PositiveInfinity(), Integer::PositiveInfinity(), Integer::Undefined()}

    } ;

    for (auto& testCase : testCases)
    {

        Integer& a = testCase.first ;
        const Integer& b = testCase.second ;
        const Integer& c = testCase.third ;

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

TEST(Spacer_Core_Types_Integer, ModuloAssignmentOperator)
{

    using spacer::core::types::Integer ;
    using spacer::core::ctnr::Triple ;
    using spacer::core::ctnr::Array ;

    Array<Triple<Integer, Integer, Integer>> testCases =
    {

        {Integer::Undefined(), Integer::Undefined(), Integer::Undefined()},
        {Integer::Undefined(), Integer::NegativeInfinity(), Integer::Undefined()},
        {Integer::Undefined(), std::numeric_limits<Integer::ValueType>::min(), Integer::Undefined()},
        {Integer::Undefined(), -2, Integer::Undefined()},
        {Integer::Undefined(), -1, Integer::Undefined()},
        {Integer::Undefined(), +0, Integer::Undefined()},
        {Integer::Undefined(), +1, Integer::Undefined()},
        {Integer::Undefined(), +2, Integer::Undefined()},
        {Integer::Undefined(), std::numeric_limits<Integer::ValueType>::max(), Integer::Undefined()},
        {Integer::Undefined(), Integer::PositiveInfinity(), Integer::Undefined()},

        {Integer::NegativeInfinity(), Integer::Undefined(), Integer::Undefined()},
        {Integer::NegativeInfinity(), Integer::NegativeInfinity(), Integer::Undefined()},
        {Integer::NegativeInfinity(), std::numeric_limits<Integer::ValueType>::min(), Integer::Undefined()},
        {Integer::NegativeInfinity(), -2, Integer::Undefined()},
        {Integer::NegativeInfinity(), -1, +0},
        {Integer::NegativeInfinity(), +0, Integer::Undefined()},
        {Integer::NegativeInfinity(), +1, +0},
        {Integer::NegativeInfinity(), +2, Integer::Undefined()},
        {Integer::NegativeInfinity(), std::numeric_limits<Integer::ValueType>::max(), Integer::Undefined()},
        {Integer::NegativeInfinity(), Integer::PositiveInfinity(), Integer::Undefined()},

        {std::numeric_limits<Integer::ValueType>::min(), Integer::Undefined(), Integer::Undefined()},
        {std::numeric_limits<Integer::ValueType>::min(), Integer::NegativeInfinity(), std::numeric_limits<Integer::ValueType>::min()},
        {std::numeric_limits<Integer::ValueType>::min(), std::numeric_limits<Integer::ValueType>::min(), +0},
        {std::numeric_limits<Integer::ValueType>::min(), -3, -2},
        {std::numeric_limits<Integer::ValueType>::min(), -2, +0},
        {std::numeric_limits<Integer::ValueType>::min(), -1, +0},
        {std::numeric_limits<Integer::ValueType>::min(), +0, Integer::Undefined()},
        {std::numeric_limits<Integer::ValueType>::min(), +1, +0},
        {std::numeric_limits<Integer::ValueType>::min(), +2, +0},
        {std::numeric_limits<Integer::ValueType>::min(), +3, -2},
        {std::numeric_limits<Integer::ValueType>::min(), std::numeric_limits<Integer::ValueType>::max(), -1},
        {std::numeric_limits<Integer::ValueType>::min(), Integer::PositiveInfinity(), std::numeric_limits<Integer::ValueType>::min()},

        {-2, Integer::Undefined(), Integer::Undefined()},
        {-2, Integer::NegativeInfinity(), -2},
        {-2, std::numeric_limits<Integer::ValueType>::min(), -2},
        {-2, -3, -2},
        {-2, -2, +0},
        {-2, -1, +0},
        {-2, +0, Integer::Undefined()},
        {-2, +1, +0},
        {-2, +2, +0},
        {-2, +3, -2},
        {-2, std::numeric_limits<Integer::ValueType>::max(), -2},
        {-2, Integer::PositiveInfinity(), -2},
        
        {-1, Integer::Undefined(), Integer::Undefined()},
        {-1, Integer::NegativeInfinity(), -1},
        {-1, std::numeric_limits<Integer::ValueType>::min(), -1},
        {-1, -3, -1},
        {-1, -2, -1},
        {-1, -1, +0},
        {-1, +0, Integer::Undefined()},
        {-1, +1, +0},
        {-1, +2, -1},
        {-1, +3, -1},
        {-1, std::numeric_limits<Integer::ValueType>::max(), -1},
        {-1, Integer::PositiveInfinity(), -1},

        {+0, Integer::Undefined(), Integer::Undefined()},
        {+0, Integer::NegativeInfinity(), +0},
        {+0, std::numeric_limits<Integer::ValueType>::min(), +0},
        {+0, -3, +0},
        {+0, -2, +0},
        {+0, -1, +0},
        {+0, +0, Integer::Undefined()},
        {+0, +1, +0},
        {+0, +2, +0},
        {+0, +3, +0},
        {+0, std::numeric_limits<Integer::ValueType>::max(), +0},
        {+0, Integer::PositiveInfinity(), +0},

        {+1, Integer::Undefined(), Integer::Undefined()},
        {+1, Integer::NegativeInfinity(), +1},
        {+1, std::numeric_limits<Integer::ValueType>::min(), +1},
        {+1, -3, +1},
        {+1, -2, +1},
        {+1, -1, +0},
        {+1, +0, Integer::Undefined()},
        {+1, +1, +0},
        {+1, +2, +1},
        {+1, +3, +1},
        {+1, std::numeric_limits<Integer::ValueType>::max(), +1},
        {+1, Integer::PositiveInfinity(), +1},

        {+2, Integer::Undefined(), Integer::Undefined()},
        {+2, Integer::NegativeInfinity(), +2},
        {+2, std::numeric_limits<Integer::ValueType>::min(), +2},
        {+2, -3, +2},
        {+2, -2, +0},
        {+2, -1, +0},
        {+2, +0, Integer::Undefined()},
        {+2, +1, +0},
        {+2, +2, +0},
        {+2, +3, +2},
        {+2, std::numeric_limits<Integer::ValueType>::max(), +2},
        {+2, Integer::PositiveInfinity(), +2},

        {std::numeric_limits<Integer::ValueType>::max(), Integer::Undefined(), Integer::Undefined()},
        {std::numeric_limits<Integer::ValueType>::max(), Integer::NegativeInfinity(), std::numeric_limits<Integer::ValueType>::max()},
        {std::numeric_limits<Integer::ValueType>::max(), std::numeric_limits<Integer::ValueType>::min(), std::numeric_limits<Integer::ValueType>::max()},
        {std::numeric_limits<Integer::ValueType>::max(), -2, +1},
        {std::numeric_limits<Integer::ValueType>::max(), -1, +0},
        {std::numeric_limits<Integer::ValueType>::max(), +0, Integer::Undefined()},
        {std::numeric_limits<Integer::ValueType>::max(), +1, +0},
        {std::numeric_limits<Integer::ValueType>::max(), +2, +1},
        {std::numeric_limits<Integer::ValueType>::max(), std::numeric_limits<Integer::ValueType>::max(), +0},
        {std::numeric_limits<Integer::ValueType>::max(), Integer::PositiveInfinity(), std::numeric_limits<Integer::ValueType>::max()},

        {Integer::PositiveInfinity(), Integer::Undefined(), Integer::Undefined()},
        {Integer::PositiveInfinity(), Integer::NegativeInfinity(), Integer::Undefined()},
        {Integer::PositiveInfinity(), std::numeric_limits<Integer::ValueType>::min(), Integer::Undefined()},
        {Integer::PositiveInfinity(), -2, Integer::Undefined()},
        {Integer::PositiveInfinity(), -1, +0},
        {Integer::PositiveInfinity(), +0, Integer::Undefined()},
        {Integer::PositiveInfinity(), +1, +0},
        {Integer::PositiveInfinity(), +2, Integer::Undefined()},
        {Integer::PositiveInfinity(), std::numeric_limits<Integer::ValueType>::max(), Integer::Undefined()},
        {Integer::PositiveInfinity(), Integer::PositiveInfinity(), Integer::Undefined()}

    } ;

    for (auto& testCase : testCases)
    {

        Integer& a = testCase.first ;
        const Integer& b = testCase.second ;
        const Integer& c = testCase.third ;

        a %= b ;

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

TEST(Spacer_Core_Types_Integer, UnaryPlusOperator)
{

    using spacer::core::types::Integer ;
    using spacer::core::ctnr::Pair ;
    using spacer::core::ctnr::Array ;

    Array<Pair<Integer, Integer>> testCases =
    {

        {Integer::Undefined(), Integer::Undefined()},
        {Integer::NegativeInfinity(), Integer::NegativeInfinity()},
        {std::numeric_limits<Integer::ValueType>::min(), std::numeric_limits<Integer::ValueType>::min()},
        {-2, -2},
        {-1, -1},
        {+0, +0},
        {+1, +1},
        {+2, +2},
        {std::numeric_limits<Integer::ValueType>::max(), std::numeric_limits<Integer::ValueType>::max()},
        {Integer::PositiveInfinity(), Integer::PositiveInfinity()}
        
    } ;

    for (const auto& testCase : testCases)
    {

        const Integer& a = testCase.first ;
        const Integer& b = testCase.second ;

        Integer c = +a ;
        
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

TEST(Spacer_Core_Types_Integer, UnaryMinusOperator)
{

    using spacer::core::types::Integer ;
    using spacer::core::ctnr::Pair ;
    using spacer::core::ctnr::Array ;

    Array<Pair<Integer, Integer>> testCases =
    {

        {Integer::Undefined(), Integer::Undefined()},
        {Integer::NegativeInfinity(), Integer::PositiveInfinity()},
        {std::numeric_limits<Integer::ValueType>::min(), Integer::PositiveInfinity()},
        {-2, +2},
        {-1, +1},
        {+0, +0},
        {+1, -1},
        {+2, -2},
        {std::numeric_limits<Integer::ValueType>::max(), -std::numeric_limits<Integer::ValueType>::max()},
        {Integer::PositiveInfinity(), Integer::NegativeInfinity()}
        
    } ;

    for (const auto& testCase : testCases)
    {

        const Integer& a = testCase.first ;
        const Integer& b = testCase.second ;

        Integer c = -a ;
        
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

TEST(Spacer_Core_Types_Integer, PrefixIncrementOperator)
{

    using spacer::core::types::Integer ;
    using spacer::core::ctnr::Pair ;
    using spacer::core::ctnr::Array ;

    Array<Pair<Integer, Integer>> testCases =
    {

        {Integer::Undefined(), Integer::Undefined()},
        {Integer::NegativeInfinity(), Integer::NegativeInfinity()},
        {std::numeric_limits<Integer::ValueType>::min(), std::numeric_limits<Integer::ValueType>::min() + 1},
        {-2, -1},
        {-1, +0},
        {+0, +1},
        {+1, +2},
        {+2, +3},
        {std::numeric_limits<Integer::ValueType>::max(), Integer::PositiveInfinity()},
        {Integer::PositiveInfinity(), Integer::PositiveInfinity()}
        
    } ;

    for (auto& testCase : testCases)
    {

        Integer& a = testCase.first ;
        const Integer& b = testCase.second ;
        
        if (b.isDefined())
        {

            Integer c = ++a ;

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

            if (b.isPositiveInfinity())
            {
                EXPECT_TRUE(a.isPositiveInfinity()) ;
            }
            else if (b.isNegativeInfinity())
            {
                EXPECT_TRUE(a.isNegativeInfinity()) ;
            }
            else
            {
                EXPECT_EQ(b, a) ;
            }

        }
        else
        {

            Integer c = ++a ;

            EXPECT_FALSE(c.isDefined()) ;

            EXPECT_FALSE(a.isDefined()) ;

        }

    }

}

TEST(Spacer_Core_Types_Integer, PrefixDecrementOperator)
{

    using spacer::core::types::Integer ;
    using spacer::core::ctnr::Pair ;
    using spacer::core::ctnr::Array ;

    Array<Pair<Integer, Integer>> testCases =
    {

        {Integer::Undefined(), Integer::Undefined()},
        {Integer::NegativeInfinity(), Integer::NegativeInfinity()},
        {std::numeric_limits<Integer::ValueType>::min(), Integer::NegativeInfinity()},
        {-2, -3},
        {-1, -2},
        {+0, -1},
        {+1, +0},
        {+2, +1},
        {std::numeric_limits<Integer::ValueType>::max(), std::numeric_limits<Integer::ValueType>::max() - 1},
        {Integer::PositiveInfinity(), Integer::PositiveInfinity()}
        
    } ;

    for (auto& testCase : testCases)
    {

        Integer& a = testCase.first ;
        const Integer& b = testCase.second ;
        
        if (b.isDefined())
        {

            Integer c = --a ;

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

            if (b.isPositiveInfinity())
            {
                EXPECT_TRUE(a.isPositiveInfinity()) ;
            }
            else if (b.isNegativeInfinity())
            {
                EXPECT_TRUE(a.isNegativeInfinity()) ;
            }
            else
            {
                EXPECT_EQ(b, a) ;
            }

        }
        else
        {

            Integer c = --a ;

            EXPECT_FALSE(c.isDefined()) ;

            EXPECT_FALSE(a.isDefined()) ;

        }

    }

}

TEST(Spacer_Core_Types_Integer, PostfixIncrementOperator)
{

    using spacer::core::types::Integer ;
    using spacer::core::ctnr::Pair ;
    using spacer::core::ctnr::Array ;

    Array<Pair<Integer, Integer>> testCases =
    {

        {Integer::Undefined(), Integer::Undefined()},
        {Integer::NegativeInfinity(), Integer::NegativeInfinity()},
        {std::numeric_limits<Integer::ValueType>::min(), std::numeric_limits<Integer::ValueType>::min() + 1},
        {-2, -1},
        {-1, +0},
        {+0, +1},
        {+1, +2},
        {+2, +3},
        {std::numeric_limits<Integer::ValueType>::max(), Integer::PositiveInfinity()},
        {Integer::PositiveInfinity(), Integer::PositiveInfinity()}
        
    } ;

    for (auto& testCase : testCases)
    {

        Integer& a = testCase.first ;
        const Integer aCopy = a ;
        const Integer& b = testCase.second ;
        
        if (b.isDefined())
        {

            Integer c = a++ ;

            if (!aCopy.isDefined())
            {
                EXPECT_FALSE(c.isDefined()) ;
            }
            else if (aCopy.isPositiveInfinity())
            {
                EXPECT_TRUE(c.isPositiveInfinity()) ;
            }
            else if (aCopy.isNegativeInfinity())
            {
                EXPECT_TRUE(c.isNegativeInfinity()) ;
            }
            else
            {
                EXPECT_EQ(aCopy, c) ;
            }

            if (b.isPositiveInfinity())
            {
                EXPECT_TRUE(a.isPositiveInfinity()) ;
            }
            else if (b.isNegativeInfinity())
            {
                EXPECT_TRUE(a.isNegativeInfinity()) ;
            }
            else
            {
                EXPECT_EQ(b, a) ;
            }

        }
        else
        {

            Integer c = a++ ;

            if (!aCopy.isDefined())
            {
                EXPECT_FALSE(c.isDefined()) ;
            }
            else if (aCopy.isPositiveInfinity())
            {
                EXPECT_TRUE(c.isPositiveInfinity()) ;
            }
            else if (aCopy.isNegativeInfinity())
            {
                EXPECT_TRUE(c.isNegativeInfinity()) ;
            }
            else
            {
                EXPECT_EQ(aCopy, c) ;
            }

            EXPECT_FALSE(a.isDefined()) ;

        }

    }

}

TEST(Spacer_Core_Types_Integer, PostfixDecrementOperator)
{

    using spacer::core::types::Integer ;
    using spacer::core::ctnr::Pair ;
    using spacer::core::ctnr::Array ;

    Array<Pair<Integer, Integer>> testCases =
    {

        {Integer::Undefined(), Integer::Undefined()},
        {Integer::NegativeInfinity(), Integer::NegativeInfinity()},
        {std::numeric_limits<Integer::ValueType>::min(), Integer::NegativeInfinity()},
        {-2, -3},
        {-1, -2},
        {+0, -1},
        {+1, +0},
        {+2, +1},
        {std::numeric_limits<Integer::ValueType>::max(), std::numeric_limits<Integer::ValueType>::max() - 1},
        {Integer::PositiveInfinity(), Integer::PositiveInfinity()}
        
    } ;

    for (auto& testCase : testCases)
    {

        Integer& a = testCase.first ;
        const Integer aCopy = a ;
        const Integer& b = testCase.second ;
        
        if (b.isDefined())
        {

            Integer c = a-- ;

            if (!aCopy.isDefined())
            {
                EXPECT_FALSE(c.isDefined()) ;
            }
            else if (aCopy.isPositiveInfinity())
            {
                EXPECT_TRUE(c.isPositiveInfinity()) ;
            }
            else if (aCopy.isNegativeInfinity())
            {
                EXPECT_TRUE(c.isNegativeInfinity()) ;
            }
            else
            {
                EXPECT_EQ(aCopy, c) ;
            }

            if (b.isPositiveInfinity())
            {
                EXPECT_TRUE(a.isPositiveInfinity()) ;
            }
            else if (b.isNegativeInfinity())
            {
                EXPECT_TRUE(a.isNegativeInfinity()) ;
            }
            else
            {
                EXPECT_EQ(b, a) ;
            }

        }
        else
        {

            Integer c = a-- ;

            if (!aCopy.isDefined())
            {
                EXPECT_FALSE(c.isDefined()) ;
            }
            else if (aCopy.isPositiveInfinity())
            {
                EXPECT_TRUE(c.isPositiveInfinity()) ;
            }
            else if (aCopy.isNegativeInfinity())
            {
                EXPECT_TRUE(c.isNegativeInfinity()) ;
            }
            else
            {
                EXPECT_EQ(aCopy, c) ;
            }

            EXPECT_FALSE(a.isDefined()) ;

        }

    }

}

TEST(Spacer_Core_Types_Integer, ValueTypeOperator)
{

    using spacer::core::types::Integer ;
    
    {

        EXPECT_ANY_THROW( Integer::ValueType a = Integer::Undefined() ; (void) a ; ) ;

    }

    {

        EXPECT_ANY_THROW( Integer::ValueType a = Integer::NegativeInfinity() ; (void) a ; ) ;

    }

    {

        Integer::ValueType a = Integer(std::numeric_limits<Integer::ValueType>::min()) ;

        EXPECT_EQ(std::numeric_limits<Integer::ValueType>::min(), a) ;

    }

    {

        Integer::ValueType a = Integer(-1) ;

        EXPECT_EQ(-1, a) ;

    }

    {

        Integer::ValueType a = Integer(+0) ;

        EXPECT_EQ(+0, a) ;

    }

    {

        Integer::ValueType a = Integer(+1) ;

        EXPECT_EQ(+1, a) ;

    }

    {

        EXPECT_ANY_THROW( Integer::ValueType a = Integer::PositiveInfinity() ; (void) a ; ) ;

    }

}

// TEST(Spacer_Core_Types_Integer, StreamOperator)
// {

//     using spacer::core::types::Integer ;

//     FAIL() ;

// }

TEST(Spacer_Core_Types_Integer, IsDefined)
{

    using spacer::core::types::Integer ;

    EXPECT_TRUE(Integer(0).isDefined()) ;
    EXPECT_TRUE(Integer(-1).isDefined()) ;
    EXPECT_TRUE(Integer(+0).isDefined()) ;
    EXPECT_TRUE(Integer(+1).isDefined()) ;
    EXPECT_TRUE(Integer(std::numeric_limits<Integer::ValueType>::min()).isDefined()) ;
    EXPECT_TRUE(Integer(std::numeric_limits<Integer::ValueType>::max()).isDefined()) ;
    EXPECT_TRUE(Integer::NegativeInfinity().isDefined()) ;
    EXPECT_TRUE(Integer::PositiveInfinity().isDefined()) ;

    EXPECT_FALSE(Integer::Undefined().isDefined()) ;

}

TEST(Spacer_Core_Types_Integer, IsZero)
{

    using spacer::core::types::Integer ;

    EXPECT_TRUE(Integer(0).isZero()) ;
    EXPECT_TRUE(Integer(+0).isZero()) ;

    EXPECT_FALSE(Integer(-1).isZero()) ;
    EXPECT_FALSE(Integer(+1).isZero()) ;
    EXPECT_FALSE(Integer(std::numeric_limits<Integer::ValueType>::min()).isZero()) ;
    EXPECT_FALSE(Integer(std::numeric_limits<Integer::ValueType>::max()).isZero()) ;
    EXPECT_FALSE(Integer::NegativeInfinity().isZero()) ;
    EXPECT_FALSE(Integer::PositiveInfinity().isZero()) ;
    EXPECT_FALSE(Integer::Undefined().isZero()) ;

}

TEST(Spacer_Core_Types_Integer, IsPositive)
{

    using spacer::core::types::Integer ;

    EXPECT_TRUE(Integer(0).isPositive()) ;
    EXPECT_TRUE(Integer(+0).isPositive()) ;
    EXPECT_TRUE(Integer(+1).isPositive()) ;
    EXPECT_TRUE(Integer(std::numeric_limits<Integer::ValueType>::max()).isPositive()) ;
    EXPECT_TRUE(Integer::PositiveInfinity().isPositive()) ;

    EXPECT_FALSE(Integer::Undefined().isPositive()) ;
    EXPECT_FALSE(Integer(-1).isPositive()) ;
    EXPECT_FALSE(Integer(std::numeric_limits<Integer::ValueType>::min()).isPositive()) ;
    EXPECT_FALSE(Integer::NegativeInfinity().isPositive()) ;

}

TEST(Spacer_Core_Types_Integer, IsNegative)
{

    using spacer::core::types::Integer ;

    EXPECT_TRUE(Integer(0).isNegative()) ;
    EXPECT_TRUE(Integer(-1).isNegative()) ;
    EXPECT_TRUE(Integer(+0).isNegative()) ;
    EXPECT_TRUE(Integer(std::numeric_limits<Integer::ValueType>::min()).isNegative()) ;
    EXPECT_TRUE(Integer::NegativeInfinity().isNegative()) ;

    EXPECT_FALSE(Integer::Undefined().isNegative()) ;
    EXPECT_FALSE(Integer(+1).isNegative()) ;
    EXPECT_FALSE(Integer(std::numeric_limits<Integer::ValueType>::max()).isNegative()) ;
    EXPECT_FALSE(Integer::PositiveInfinity().isNegative()) ;

}

TEST(Spacer_Core_Types_Integer, IsStrictlyPositive)
{

    using spacer::core::types::Integer ;

    EXPECT_TRUE(Integer(+1).isStrictlyPositive()) ;
    EXPECT_TRUE(Integer(std::numeric_limits<Integer::ValueType>::max()).isStrictlyPositive()) ;
    EXPECT_TRUE(Integer::PositiveInfinity().isStrictlyPositive()) ;

    EXPECT_FALSE(Integer::Undefined().isStrictlyPositive()) ;
    EXPECT_FALSE(Integer(0).isStrictlyPositive()) ;
    EXPECT_FALSE(Integer(-1).isStrictlyPositive()) ;
    EXPECT_FALSE(Integer(+0).isStrictlyPositive()) ;
    EXPECT_FALSE(Integer(std::numeric_limits<Integer::ValueType>::min()).isStrictlyPositive()) ;
    EXPECT_FALSE(Integer::NegativeInfinity().isStrictlyPositive()) ;

}

TEST(Spacer_Core_Types_Integer, IsStrictlyNegative)
{

    using spacer::core::types::Integer ;

    EXPECT_TRUE(Integer(-1).isStrictlyNegative()) ;
    EXPECT_TRUE(Integer(std::numeric_limits<Integer::ValueType>::min()).isStrictlyNegative()) ;
    EXPECT_TRUE(Integer::NegativeInfinity().isStrictlyNegative()) ;

    EXPECT_FALSE(Integer::Undefined().isStrictlyNegative()) ;
    EXPECT_FALSE(Integer(0).isStrictlyNegative()) ;
    EXPECT_FALSE(Integer(+1).isStrictlyNegative()) ;
    EXPECT_FALSE(Integer(+0).isStrictlyNegative()) ;
    EXPECT_FALSE(Integer(std::numeric_limits<Integer::ValueType>::max()).isStrictlyNegative()) ;
    EXPECT_FALSE(Integer::PositiveInfinity().isStrictlyNegative()) ;

}

TEST(Spacer_Core_Types_Integer, IsInfinity)
{

    using spacer::core::types::Integer ;

    EXPECT_TRUE(Integer::NegativeInfinity().isInfinity()) ;
    EXPECT_TRUE(Integer::PositiveInfinity().isInfinity()) ;

    EXPECT_FALSE(Integer::Undefined().isInfinity()) ;
    EXPECT_FALSE(Integer(0).isInfinity()) ;
    EXPECT_FALSE(Integer(-1).isInfinity()) ;
    EXPECT_FALSE(Integer(+0).isInfinity()) ;
    EXPECT_FALSE(Integer(+1).isInfinity()) ;
    EXPECT_FALSE(Integer(std::numeric_limits<Integer::ValueType>::min()).isInfinity()) ;
    EXPECT_FALSE(Integer(std::numeric_limits<Integer::ValueType>::max()).isInfinity()) ;

}

TEST(Spacer_Core_Types_Integer, IsPositiveInfinity)
{

    using spacer::core::types::Integer ;

    EXPECT_TRUE(Integer::PositiveInfinity().isPositiveInfinity()) ;

    EXPECT_FALSE(Integer::Undefined().isPositiveInfinity()) ;
    EXPECT_FALSE(Integer(0).isPositiveInfinity()) ;
    EXPECT_FALSE(Integer(-1).isPositiveInfinity()) ;
    EXPECT_FALSE(Integer(+0).isPositiveInfinity()) ;
    EXPECT_FALSE(Integer(+1).isPositiveInfinity()) ;
    EXPECT_FALSE(Integer(std::numeric_limits<Integer::ValueType>::min()).isPositiveInfinity()) ;
    EXPECT_FALSE(Integer(std::numeric_limits<Integer::ValueType>::max()).isPositiveInfinity()) ;
    EXPECT_FALSE(Integer::NegativeInfinity().isPositiveInfinity()) ;

}

TEST(Spacer_Core_Types_Integer, IsNegativeInfinity)
{

    using spacer::core::types::Integer ;

    EXPECT_TRUE(Integer::NegativeInfinity().isNegativeInfinity()) ;

    EXPECT_FALSE(Integer::Undefined().isNegativeInfinity()) ;
    EXPECT_FALSE(Integer(0).isNegativeInfinity()) ;
    EXPECT_FALSE(Integer(-1).isNegativeInfinity()) ;
    EXPECT_FALSE(Integer(+0).isNegativeInfinity()) ;
    EXPECT_FALSE(Integer(+1).isNegativeInfinity()) ;
    EXPECT_FALSE(Integer(std::numeric_limits<Integer::ValueType>::min()).isNegativeInfinity()) ;
    EXPECT_FALSE(Integer(std::numeric_limits<Integer::ValueType>::max()).isNegativeInfinity()) ;
    EXPECT_FALSE(Integer::PositiveInfinity().isNegativeInfinity()) ;

}

TEST(Spacer_Core_Types_Integer, GetSign)
{

    using spacer::core::types::Sign ;
    using spacer::core::types::Integer ;

    EXPECT_EQ(Sign::Undefined, Integer::Undefined().getSign()) ;
    EXPECT_EQ(Sign::None, Integer(0).getSign()) ;
    EXPECT_EQ(Sign::Negative, Integer(-1).getSign()) ;
    EXPECT_EQ(Sign::None, Integer(+0).getSign()) ;
    EXPECT_EQ(Sign::Positive, Integer(+1).getSign()) ;
    EXPECT_EQ(Sign::Negative, Integer(std::numeric_limits<Integer::ValueType>::min()).getSign()) ;
    EXPECT_EQ(Sign::Positive, Integer(std::numeric_limits<Integer::ValueType>::max()).getSign()) ;
    EXPECT_EQ(Sign::Negative, Integer::NegativeInfinity().getSign()) ;
    EXPECT_EQ(Sign::Positive, Integer::PositiveInfinity().getSign()) ;

}

TEST(Spacer_Core_Types_Integer, GetString)
{

    using spacer::core::types::Integer ;

    EXPECT_EQ("Undefined", Integer::Undefined().getString()) ;
    EXPECT_EQ("0", Integer(0).getString()) ;
    EXPECT_EQ("-1", Integer(-1).getString()) ;
    EXPECT_EQ("0", Integer(+0).getString()) ;
    EXPECT_EQ("1", Integer(+1).getString()) ;
    EXPECT_EQ("-Inf", Integer::NegativeInfinity().getString()) ;
    EXPECT_EQ("+Inf", Integer::PositiveInfinity().getString()) ;

}

// TEST(Spacer_Core_Types_Integer, GetObject)
// {

//     using spacer::core::types::Integer ;

//     FAIL() ;

// }

TEST(Spacer_Core_Types_Integer, Undefined)
{

    using spacer::core::types::Integer ;

    EXPECT_NO_THROW(Integer::Undefined()) ;
   
    EXPECT_FALSE(Integer::Undefined().isDefined()) ;
    EXPECT_FALSE(Integer::Undefined().isInfinity()) ;

}

TEST(Spacer_Core_Types_Integer, PositiveInfinity)
{

    using spacer::core::types::Integer ;

    EXPECT_NO_THROW(Integer::PositiveInfinity()) ;

    EXPECT_TRUE(Integer::PositiveInfinity().isDefined()) ;
    EXPECT_TRUE(Integer::PositiveInfinity().isInfinity()) ;
    EXPECT_TRUE(Integer::PositiveInfinity().isPositiveInfinity()) ;

}

TEST(Spacer_Core_Types_Integer, NegativeInfinity)
{

    using spacer::core::types::Integer ;

    EXPECT_NO_THROW(Integer::NegativeInfinity()) ;
    
    EXPECT_TRUE(Integer::NegativeInfinity().isDefined()) ;
    EXPECT_TRUE(Integer::NegativeInfinity().isInfinity()) ;
    EXPECT_TRUE(Integer::NegativeInfinity().isNegativeInfinity()) ;

}

TEST(Spacer_Core_Types_Integer, String)
{

    using spacer::core::types::Integer ;

    EXPECT_FALSE(Integer::String("").isDefined()) ;
    EXPECT_FALSE(Integer::String("Undefined").isDefined()) ;

    EXPECT_EQ(+0, Integer::String("0")) ;
    EXPECT_EQ(-1, Integer::String("-1")) ;
    EXPECT_EQ(+0, Integer::String("+0")) ;
    EXPECT_EQ(+1, Integer::String("+1")) ;

    EXPECT_EQ(-2147483648, Integer::String("-2147483648")) ;
    EXPECT_EQ(+2147483647, Integer::String("+2147483647")) ;

    EXPECT_ANY_THROW(Integer::String("-2147483649")) ;
    EXPECT_ANY_THROW(Integer::String("2147483648")) ;
    EXPECT_ANY_THROW(Integer::String("+2147483648")) ;

    EXPECT_TRUE(Integer::String("-Inf").isNegativeInfinity()) ;
    EXPECT_TRUE(Integer::String("Inf").isPositiveInfinity()) ;
    EXPECT_TRUE(Integer::String("+Inf").isPositiveInfinity()) ;

}

// TEST(Spacer_Core_Types_Integer, Object)
// {

//     using spacer::core::types::Integer ;

//     FAIL() ;

// }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////