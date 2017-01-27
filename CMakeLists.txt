cmake_minimum_required( VERSION 3.3.0 )
project( "polygons" VERSION 0.0.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory("src")
include_directories("src")
get_directory_property(SOURCEFILES DIRECTORY "src" DEFINITION "SOURCEFILES")
add_executable(${CMAKE_PROJECT_NAME} "Main.cpp" ${SOURCEFILES})
