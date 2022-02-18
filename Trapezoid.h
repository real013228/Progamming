//
// Created by real0 on 19.02.2022.
//

#ifndef OOP_TRAPEZOID_H
#define OOP_TRAPEZOID_H
#include "Point.h"


class Trapezoid {
public:
    Point p1_;
    Point p2_;
    Point p3_;
    Point p4_;

    static bool checkTrapezoid(const Point &p1, const Point &p2, const Point &p3, const Point &p4);

    Trapezoid();

    Trapezoid(const Point &p1, const Point &p2, const Point &p3, const Point &p4);

    Trapezoid(const Trapezoid &other);

    Trapezoid &operator=(const Trapezoid &other);
};

#endif //OOP_TRAPEZOID_H
