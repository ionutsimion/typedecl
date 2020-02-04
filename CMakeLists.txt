cmake_minimum_required(VERSION 3.15)
project(wrappers)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(include)

add_executable(wrappers
    tests/wrapper_tests.cxx)
