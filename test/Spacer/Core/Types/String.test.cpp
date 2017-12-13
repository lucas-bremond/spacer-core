////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Copyright (C) 2017 by Lucas Brémond
///
/// This file is part of the Spacer project.
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @file                       Spacer/Core/Types/String.test.cpp
/// @author                     Lucas Brémond <lucas.bremond@gmail.com>
/// @date                       2 Dec 2017

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Global.test.hpp>

#include <Spacer/Core/Types/String.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(Spacer_Core_Types_String, DefaultConstructor)
{

    using spacer::core::types::String ;

    EXPECT_NO_THROW(String()) ;
    EXPECT_NO_THROW(String("abc")) ;

}

TEST(Spacer_Core_Types_String, StringConstructor)
{

    using spacer::core::types::String ;

    EXPECT_NO_THROW(String(std::string(""))) ;
    EXPECT_NO_THROW(String(std::string("abc"))) ;

}

TEST(Spacer_Core_Types_String, StringOperator)
{

    using spacer::core::types::String ;

    {

        String A = "abc" ;

        std::string B = A ;

        EXPECT_EQ("abc", B) ;

    }

}

TEST(Spacer_Core_Types_String, IsEmpty)
{

    using spacer::core::types::String ;

    EXPECT_TRUE(String().isEmpty()) ;
    EXPECT_TRUE(String("").isEmpty()) ;

    EXPECT_FALSE(String("abc").isEmpty()) ;
    EXPECT_FALSE(String("\n").isEmpty()) ;

}

TEST(Spacer_Core_Types_String, IsUppercase)
{

    using spacer::core::types::String ;

    EXPECT_TRUE(String("ABC").isUppercase()) ;
    EXPECT_TRUE(String("A_B_C").isUppercase()) ;
    EXPECT_TRUE(String("A/B/C").isUppercase()) ;
    EXPECT_TRUE(String("A?B?C").isUppercase()) ;

    EXPECT_FALSE(String().isUppercase()) ;
    EXPECT_FALSE(String("").isUppercase()) ;
    EXPECT_FALSE(String("abc").isUppercase()) ;
    EXPECT_FALSE(String("ABCabc").isUppercase()) ;
    EXPECT_FALSE(String("abcABC").isUppercase()) ;

}

TEST(Spacer_Core_Types_String, IsLowercase)
{

    using spacer::core::types::String ;

    EXPECT_TRUE(String("abc").isLowercase()) ;
    EXPECT_TRUE(String("a_b_c").isLowercase()) ;
    EXPECT_TRUE(String("a/b/c").isLowercase()) ;
    EXPECT_TRUE(String("a?b?c").isLowercase()) ;

    EXPECT_FALSE(String().isLowercase()) ;
    EXPECT_FALSE(String("").isLowercase()) ;
    EXPECT_FALSE(String("ABC").isLowercase()) ;
    EXPECT_FALSE(String("ABCabc").isLowercase()) ;
    EXPECT_FALSE(String("abcABC").isLowercase()) ;

}

TEST(Spacer_Core_Types_String, GetLength)
{

    using spacer::core::types::String ;

    EXPECT_EQ(size_t(0), String().getLength()) ;
    EXPECT_EQ(size_t(0), String("").getLength()) ;

    EXPECT_EQ(size_t(3), String("abc").getLength()) ;
    EXPECT_EQ(size_t(1), String("\n").getLength()) ;

}

TEST(Spacer_Core_Types_String, Empty)
{

    using spacer::core::types::String ;

    EXPECT_TRUE(String::Empty().isEmpty()) ;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////