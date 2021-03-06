########################################################################################################################################################
###
### Copyright (C) 2018 by Lucas Brémond
###
### This file is part of the Spacer project.
###
########################################################################################################################################################

### @file                       SpacerCorePy/CMakeLists.txt
### @author                     Lucas Brémond <lucas.bremond@gmail.com>
### @date                       18 Mar 2018

########################################################################################################################################################

## Project Properties

SET (PROJECT_NAME "SpacerCorePy")
SET (PROJECT_DESCRIPTION "Python bindings for Spacer / Core.")
SET (PROJECT_PACKAGE_NAME "SpacerCorePy")
SET (PROJECT_PATH "Spacer/Core")
SET (PROJECT_LICENSE "MIT License")
SET (PROJECT_VENDOR_ID "com.bremond.lucas")
SET (PROJECT_VENDOR_NAME "Lucas Brémond")
SET (PROJECT_VENDOR_CONTACT "lucas.bremond@gmail.com")
SET (PROJECT_VENDOR_URL "lucas.bremond.info")

########################################################################################################################################################

## Setup

### Compatibility Check

CMAKE_MINIMUM_REQUIRED (VERSION "2.8.12" FATAL_ERROR)

### Paths

SET (CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/tools/cmake")

### Policies

CMAKE_POLICY (SET "CMP0048" NEW)

########################################################################################################################################################

## Project Configuration

PROJECT (${PROJECT_NAME} VERSION ${PROJECT_VERSION_STRING} LANGUAGES "C" "CXX")

########################################################################################################################################################

## Dependencies

### Boost [1.66.0]

SET (Boost_USE_STATIC_LIBS ON)
SET (Boost_USE_MULTITHREADED ON)

UNSET (Boost_INCLUDE_DIR CACHE)
UNSET (Boost_LIBRARY_DIRS CACHE)

FIND_PACKAGE ("Boost" "1.66" COMPONENTS "python" REQUIRED)

INCLUDE_DIRECTORIES (${Boost_INCLUDE_DIRS})
LINK_DIRECTORIES (${Boost_LIBRARY_DIRS})

### Boost.NumPy

SET (BOOST_NUMPY_ROOT_DIR "${PROJECT_SOURCE_DIR}/thirdparty/boost.numpy")

FIND_PACKAGE ("BoostNumPy" REQUIRED)

IF (BOOST_NUMPY_FOUND)
    INCLUDE_DIRECTORIES (${BOOST_NUMPY_INCLUDE_DIR})
    LINK_DIRECTORIES (${BOOST_NUMPY_LIBRARY_DIRS})
ELSE ()
    MESSAGE (SEND_ERROR "[Boost.NumPy] not found.")
ENDIF ()

### Eigen 3

FIND_PACKAGE ("Eigen3" REQUIRED)

IF (EIGEN3_FOUND)
    INCLUDE_DIRECTORIES (${EIGEN3_INCLUDE_DIR})
ELSE ()
    MESSAGE (SEND_ERROR "[Eigen 3] not found.")
ENDIF ()

### Boost.NumPy Eigen

SET (EIGEN_NUMPY_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/thirdparty/boost_numpy_eigen")

### NumPy

EXECUTE_PROCESS (COMMAND python -c "import numpy; print numpy.get_include()" OUTPUT_VARIABLE NUMPY_INCLUDE_DIR OUTPUT_STRIP_TRAILING_WHITESPACE)

### Python

SET (PYTHON_INCLUDE_DIR "/usr/include/python2.7")
SET (PYTHON_LIBRARIES "/usr/lib64/libpython2.7.so")

########################################################################################################################################################

## Target

SET (SPACERCOREPY_NAME ${PROJECT_PACKAGE_NAME})
SET (SPACERCOREPY_TARGET "${SPACERCOREPY_NAME}.so")

FILE (GLOB_RECURSE PROJECT_SRCS "${PROJECT_SOURCE_DIR}/src/*.cxx")

LIST (APPEND PROJECT_SRCS "${PROJECT_SOURCE_DIR}/thirdparty/boost_numpy_eigen/eigen_numpy.cpp")

ADD_LIBRARY (${SPACERCOREPY_TARGET} SHARED ${PROJECT_SRCS})

ADD_DEPENDENCIES (${SPACERCOREPY_TARGET} ${SHARED_LIBRARY_TARGET})

TARGET_INCLUDE_DIRECTORIES (${SPACERCOREPY_TARGET} PUBLIC ${PYTHON_INCLUDE_DIR})
TARGET_INCLUDE_DIRECTORIES (${SPACERCOREPY_TARGET} PUBLIC ${NUMPY_INCLUDE_DIR})
TARGET_INCLUDE_DIRECTORIES (${SPACERCOREPY_TARGET} PUBLIC ${EIGEN_NUMPY_INCLUDE_DIR})
TARGET_INCLUDE_DIRECTORIES (${SPACERCOREPY_TARGET} PUBLIC "${CMAKE_SOURCE_DIR}/include")
TARGET_INCLUDE_DIRECTORIES (${SPACERCOREPY_TARGET} PUBLIC "${CMAKE_SOURCE_DIR}/src")
TARGET_INCLUDE_DIRECTORIES (${SPACERCOREPY_TARGET} PUBLIC "${PROJECT_SOURCE_DIR}/include")
TARGET_INCLUDE_DIRECTORIES (${SPACERCOREPY_TARGET} PUBLIC "${PROJECT_SOURCE_DIR}/src")

TARGET_LINK_LIBRARIES (${SPACERCOREPY_TARGET} ${PYTHON_LIBRARIES})
TARGET_LINK_LIBRARIES (${SPACERCOREPY_TARGET} ${Boost_LIBRARIES})
TARGET_LINK_LIBRARIES (${SPACERCOREPY_TARGET} ${BOOST_NUMPY_LIBRARIES})
TARGET_LINK_LIBRARIES (${SPACERCOREPY_TARGET} ${SHARED_LIBRARY_TARGET})

SET_TARGET_PROPERTIES (${SPACERCOREPY_TARGET} PROPERTIES VERSION ${PROJECT_VERSION_STRING} SOVERSION ${PROJECT_VERSION_MAJOR} OUTPUT_NAME ${PROJECT_PACKAGE_NAME} CLEAN_DIRECT_OUTPUT 1 PREFIX "")

INSTALL (TARGETS ${SPACERCOREPY_TARGET} DESTINATION "${INSTALL_LIB}/${PROJECT_PATH}" COMPONENT "python")
INSTALL (FILES "${PROJECT_SOURCE_DIR}/tools/python/__init__.py" DESTINATION "${INSTALL_LIB}/Spacer" COMPONENT "python")
INSTALL (FILES "${PROJECT_SOURCE_DIR}/tools/python/Core/__init__.py" DESTINATION "${INSTALL_LIB}/${PROJECT_PATH}" COMPONENT "python")

########################################################################################################################################################