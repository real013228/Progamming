cmake_minimum_required(VERSION 3.20)
project(OOP2)

set(CMAKE_CXX_STANDARD 23)
set(libcurl_INCLUDE_DIR "C:/Users/real0/CLionProjects/OOP2/curl-win64-latest/curl-7.82.0-win64-mingw/include")
set(nlohmann_INCLUDE_DIR "C:/Users/real0/CLionProjects/OOP2/include")

include_directories(${libcurl_INCLUDE_DIR})
include_directories(${nlohmann_INCLUDE_DIR})

add_executable(OOP2 main.cpp Currencies.cpp)

target_link_libraries(OOP2 C:/Users/real0/CLionProjects/OOP2/curl-win64-latest/curl-7.82.0-win64-mingw/lib/libcurl.dll.a)