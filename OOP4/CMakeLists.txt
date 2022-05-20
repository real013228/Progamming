cmake_minimum_required(VERSION 3.20)
project(OOP4)

add_executable(OOP4 main.cpp Cube.h)
target_link_libraries(OOP4 -lopengl32 -lfreeglut -lglu32)

