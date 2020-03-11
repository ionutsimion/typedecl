cmake_minimum_required(VERSION 3.15)

# Set the project name and version
project(wrappers VERSION 0.0.1)
configure_file(wrappers_config.in wrappers_config.hxx)

# Add the executable
add_executable(wrappers tests/wrappers_tests.cxx)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add directories to search path for include files
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Add the binary tree to the search path for include files so that we will find the config file
target_include_directories(wrappers PUBLIC "${PROJECT_BINARY_DIR}")
