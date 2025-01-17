cmake_minimum_required(VERSION 3.6)
SET(CMAKE_INSTALL_PREFIX  /usr/local/)
project(mac_vrpn) 
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11) 
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -std=c++11 -g -gdb")
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} support C++11 support")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

aux_source_directory(. ALL_SOURCES)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
message(STATUS "EXECUTABLE_OUTPUT_PATH:  ${EXECUTABLE_OUTPUT_PATH}")

add_library(mac_vrpn SHARED ${ALL_SOURCES})
 
 
 



