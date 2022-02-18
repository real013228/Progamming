//
// Created by real0 on 18.02.2022.
//

#ifndef OOP_POINT_H
#define OOP_POINT_H
#include <iostream>
class Point{
public:
    double xCor_{};
    double yCor_{};
    Point();
    Point(double xCor, double yCor);
    Point(const Point& other);
    Point& operator = (const Point& point);
    Point& operator = (std::pair<double, double> x);
    void print() const;
};
double findDist(const Point& p1, const Point& p2);
#endif //OOP_POINT_H
