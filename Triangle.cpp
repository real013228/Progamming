//
// Created by real0 on 19.02.2022.
//

#include "Triangle.h"

Triangle::Triangle() = default;

Triangle::Triangle(const Point &p1, const Point &p2, const Point &p3) {
    p1_ = p1;
    p2_ = p2;
    p3_ = p3;
}

Triangle::Triangle(const Triangle &other) {
    p1_ = other.p1_;
    p2_ = other.p2_;
    p3_ = other.p3_;
}

Triangle &Triangle::operator=(const Triangle &other) = default;

Triangle::~Triangle() = default;

double Triangle::getArray() const {
    double ans = 0;
    ans += p1_.xCor_ * p2_.yCor_;
    ans += p2_.xCor_ * p3_.yCor_;

    ans -= p2_.xCor_ * p1_.yCor_;
    ans -= p3_.xCor_ * p2_.yCor_;

    ans += p3_.xCor_ * p1_.yCor_;

    ans -= p1_.xCor_ * p3_.yCor_;
    return std::abs(ans) / 2;
}


