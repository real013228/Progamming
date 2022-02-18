cmake_minimum_required(VERSION 3.20)
project(OOP)

set(CMAKE_CXX_STANDARD 17)

add_executable(OOP main.cpp
        Polynomial.cpp
        Point.cpp
        BrokenLine.cpp
        ClosedBrokenLine.cpp
        Polygon.cpp
        Triangle.cpp
        Trapezoid.cpp
        RegularPolygon.cpp
        )