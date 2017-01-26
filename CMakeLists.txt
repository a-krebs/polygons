include( VERSION.cmake )

if( "${PROJECT_VERSION_MAJOR}" STREQUAL "" )
    message( FATAL_ERROR "PROJECT_VERSION_MAJOR must be set." )
endif()

if( "${PROJECT_VERSION_MINOR}" STREQUAL "" )
    message( FATAL_ERROR "PROJECT_VERSION_MINOR must be set." )
endif()

if( "${PROJECT_VERSION_PATCH}" STREQUAL "" )
    message( FATAL_ERROR "PROJECT_VERSION_PATCH must be set." )
endif()

cmake_minimum_required( VERSION 3.3.0 )
project( "polygons" VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH} )

message( STATUS "Project Version: ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}${PROJECT_VERSION_SUFFIX}" )

# Generate version.h
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/version.h.in"
    "${CMAKE_CURRENT_BINARY_DIR}/include/polygons/version.h"
)


# compiler flags
################################################################################

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# targets
################################################################################

add_subdirectory("src")
include_directories("src")
get_directory_property(SOURCEFILES DIRECTORY "src" DEFINITION "SOURCEFILES")
add_executable(${CMAKE_PROJECT_NAME} "Main.cpp" ${SOURCEFILES})
