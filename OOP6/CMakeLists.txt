cmake_minimum_required(VERSION 3.20)
project(OOP6)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(googletest)
include_directories(googletest/googletest/include)
include_directories(googletest/googlemock/include)

add_executable(OOP6 test.cpp Polynomial.h)
add_executable(main main.cpp)
target_link_libraries(OOP6 gtest gtest_main)