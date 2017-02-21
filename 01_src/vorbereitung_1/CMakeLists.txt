cmake_minimum_required(VERSION 2.8)
message(STATUS "HELLO")
set(MODULE_NAME "vrb")
set ("${MODULE_NAME}+_VERSION_MAJOR" 1)
set (Vorbereitung_VERSION_MINOR 0)
set (Vorbereitung_VERSION_PATCH 1)

# configure a header file to pass some of the CMake settings to the source code
configure_file (
"${PROJECT_SOURCE_DIR}/01_src/vorbereitung_1/fork_config.h"
"${PROJECT_BINARY_DIR}/fork_config.h"
)

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")

# add the executable
file(GLOB SRC *.cpp)
set(MAIN main.cpp mm_standard_usages.h runnable.h device.h fork_config.h)
#add_library(fork_common )
add_executable(fork_ ${MAIN} ${SRC} mm_standard_usages.h fork_config.h)
set(CMAKE_EXECUTABLE_SUFFIX exe)
#target_link_libraries (Tutorial MathFunctions)