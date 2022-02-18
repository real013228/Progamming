//
// Created by real0 on 19.02.2022.
//
#include "Trapezoid.h"


bool Trapezoid::checkTrapezoid(const Point &p1, const Point &p2, const Point &p3, const Point &p4) {
    if (std::abs(p1.yCor_ - p2.yCor_) * std::abs(p3.xCor_ - p4.xCor_) ==
        std::abs(p3.yCor_ - p4.yCor_) * std::abs(p1.xCor_ - p2.xCor_) ||
        std::abs(p3.yCor_ - p2.yCor_) * std::abs(p1.xCor_ - p4.xCor_) ==
        std::abs(p1.yCor_ - p4.yCor_) * std::abs(p3.xCor_ - p2.xCor_)) {
        return true;
    } else {
        return false;
    }
}

Trapezoid::Trapezoid() = default;

Trapezoid::Trapezoid(const Point &p1, const Point &p2, const Point &p3, const Point &p4) {
    this->p1_ = p1;
    this->p2_ = p2;
    this->p3_ = p3;
    this->p4_ = p4;
}

Trapezoid::Trapezoid(const Trapezoid &other) {
    if (checkTrapezoid(other.p1_, other.p2_, other.p3_, other.p4_)) {
        p1_ = other.p1_;
        p2_ = other.p2_;
        p3_ = other.p3_;
        p4_ = other.p4_;
    } else {
        std::cout << "incorrect points it will be nullified\n";
        p1_.xCor_ = 0;
        p1_.yCor_ = 0;

        p2_.xCor_ = 0;
        p2_.yCor_ = 0;

        p3_.xCor_ = 0;
        p3_.yCor_ = 0;

        p4_.xCor_ = 0;
        p4_.yCor_ = 0;
    }
}

Trapezoid &Trapezoid::operator=(const Trapezoid &other) {
    if (checkTrapezoid(other.p1_, other.p2_, other.p3_, other.p4_)) {
        p1_ = other.p1_;
        p2_ = other.p2_;
        p3_ = other.p3_;
        p4_ = other.p4_;
    } else {
        std::cout << "incorrect points it will be nullified\n";
        p1_.xCor_ = 0;
        p1_.yCor_ = 0;

        p2_.xCor_ = 0;
        p2_.yCor_ = 0;

        p3_.xCor_ = 0;
        p3_.yCor_ = 0;

        p4_.xCor_ = 0;
        p4_.yCor_ = 0;
    }
}

