//
// Created by real0 on 19.02.2022.
//
#ifndef OOP_TRIANGLE_H
#define OOP_TRIANGLE_H

#include "Point.h"

class Triangle {
private:
    Point p1_{};
    Point p2_{};
    Point p3_{};
public:
    Triangle();

    Triangle(const Point &p1, const Point &p2, const Point &p3);

    Triangle(const Triangle &other);

    Triangle &operator=(const Triangle &other);

    ~Triangle();

    double getArray() const;
};

#endif //OOP_TRIANGLE_H
