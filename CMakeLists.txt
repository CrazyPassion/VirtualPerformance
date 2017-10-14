cmake_minimum_required(VERSION 3.8)
project(VirtualPerformance)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp VirtualPerformance.cpp VirtualPerformance.hpp)
add_executable(VirtualPerformance ${SOURCE_FILES})