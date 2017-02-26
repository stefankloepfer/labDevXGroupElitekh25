cmake_minimum_required(VERSION 2.8)
project(labor_swe_2)

set(CMAKE_BUILD_TYPE "Debug")

file(MAKE_DIRECTORY 02_include)
file(MAKE_DIRECTORY 03_libs)
file( MAKE_DIRECTORY 10_build )
file(MAKE_DIRECTORY 07_exec)
file(MAKE_DIRECTORY 04_static)

set(INCLUDE_DIRECTORIES "02_include")
set(LIBRARY_OUTPUT_DIRECTORY "03_libs")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "04_static")
set( CMAKE_INSTALL_PREFIX "10_build" )
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "07_exec")
include_directories(${INCLUDE_DIRECTORIES})

# Include Boost as an imported target
find_package(Boost REQUIRED)
add_library(boost INTERFACE IMPORTED)
set_property(TARGET boost PROPERTY
    INTERFACE_INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR})
add_subdirectory("01_src")
