cmake_minimum_required(VERSION 2.8)
project(labor_swe_2)

#message(${CMAKE_CURRENT_BINARY_DIR})
#message(${CMAKE_CURRENT_SOURCE_DIR})
#message(${CMAKE_CURRENT_LIST_DIR})
set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}"/01_src")
message(${SOURCES})
set(CMAKE_BUILD_TYPE "Debug")

file(MAKE_DIRECTORY 02_include)
file(MAKE_DIRECTORY 03_libs)
file(MAKE_DIRECTORY 04_build)
file(MAKE_DIRECTORY 07_exec)

set(INCLUDE_DIRECTORIES "02_include")
set(LIBRARY_OUTPUT_DIRECTORY "03_libs")
set(CMAKE_INSTALL_PREFIX "04_build")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "07_exec")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "03_libs")

add_subdirectory("01_src")