cmake_minimum_required(VERSION 2.8)
message(STATUS "HELLO")
set(MODULE_NAME "SW1")

file(GLOB SRC *.cpp)
set(MAIN main.cpp mm_standard_usages.h runnable.h device.h)

add_executable(depp.exe ${MAIN} ${SRC} mm_standard_usages.h)
