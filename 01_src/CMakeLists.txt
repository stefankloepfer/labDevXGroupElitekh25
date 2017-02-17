cmake_minimum_required(VERSION 2.8)
message(STATUS "HELLO")
set(MODULE_NAME "SW1")

file(GLOB SRC *.cpp)
set(MAIN main.cpp)

add_executable(depp ${MAIN} ${SRC})
