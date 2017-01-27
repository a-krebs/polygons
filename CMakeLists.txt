cmake_minimum_required( VERSION 3.3.0 )
project( "polygons" VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# needs threads for gtest
find_package(Threads REQUIRED)


# External Projects
################################################################################

include(ExternalProject)

ExternalProject_Add(
    "gtest"
    URL "https://github.com/google/googletest/archive/release-1.8.0.tar.gz"
    URL_HASH "SHA256=58a6f4277ca2bc8565222b3bbd58a177609e9c488e8a72649359ba51450db7d8"
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
    # disable install
    INSTALL_COMMAND ""
)

ExternalProject_Get_Property(gtest source_dir binary_dir)
set(GTEST_SOURCE_DIR ${source_dir})
set(GTEST_BINARY_DIR ${binary_dir})

# imported library because ExternalProject will build it
add_library("libgtest" IMPORTED STATIC GLOBAL)
add_library("libgtest_main" IMPORTED STATIC GLOBAL)
add_dependencies("libgtest" gtest)
add_dependencies("libgtest_main" gtest)

set_target_properties("libgtest" PROPERTIES
    "IMPORTED_LOCATION" "${GTEST_BINARY_DIR}/googlemock/gtest/libgtest.a"
    "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
)
set_target_properties("libgtest_main" PROPERTIES
    "IMPORTED_LOCATION" "${GTEST_BINARY_DIR}/googlemock/gtest/libgtest_main.a"
    "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
)

include_directories("${GTEST_SOURCE_DIR}/googletest/include")


# Source Files and Targets
################################################################################

add_subdirectory("src")
include_directories("src")

get_directory_property(SOURCEFILES DIRECTORY "src" DEFINITION "SOURCEFILES")
get_directory_property(TESTSOURCEFILES DIRECTORY "src" DEFINITION "TESTSOURCEFILES")

add_executable(${CMAKE_PROJECT_NAME} "Main.cpp" ${SOURCEFILES})

add_executable("tests" ${TESTSOURCEFILES} ${SOURCEFILES})
target_link_libraries("tests" libgtest)
target_link_libraries("tests" libgtest_main)
