cmake_minimum_required(VERSION 2.6)

project(test)

# Locate GTest
 
# Link runTests with what we want to test and the GTest and pthread library
set(CMAKE_CXX_FLAGS "-Wno-deprecated-declarations")
add_subdirectory(Googletest)