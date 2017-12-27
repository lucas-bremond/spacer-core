////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Copyright (C) 2017 by Lucas Brémond
///
/// This file is part of the Spacer project.
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @file                       Spacer/Core/Logger.test.cpp
/// @author                     Lucas Brémond <lucas.bremond@gmail.com>
/// @date                       20 Dec 2017

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Global.test.hpp>

#include <Spacer/Core/Logger.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class TestClass
{

    public:

                                TestClass                                   ( ) ;

        friend std::ostream&    operator <<                                 (           std::ostream&               anOutputStream,
                                                                                const   TestClass&                  aTestClass                          ) ;

    private:

        int integer_ ;
        double double_ ;

} ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                TestClass::TestClass                        ( )
                                :   integer_(123),
                                    double_(456.789)
{

}

std::ostream&                   operator <<                                 (           std::ostream&               anOutputStream,
                                                                                const   TestClass&                  aTestClass                          )
{

    anOutputStream << "Class :: " << aTestClass.integer_ << " " << aTestClass.double_ ;

    return anOutputStream ;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(Spacer_Core_Logger, Test)
{

    using spacer::core::Logger ;
    using spacer::core::logger::Severity ;

    Logger logger = Logger::Console(Severity::Info) ;

    // logger << 1 ;
    // logger << 123.456 ;
    // logger << 'a' ;
    // logger << "Hello World!" ;
    logger << "Hello" << " " << "World!" ;
    // logger << TestClass() ;
    // std::cout << TestClass() << std::endl ;

    // LOG_INFO(logger) << TestClass() ;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////