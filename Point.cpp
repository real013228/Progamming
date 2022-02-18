#include "Point.h"
#include <iostream>
#include <cmath>

using namespace std;
double xCor_;
double yCor_;

Point::Point() = default;

Point::Point(double xCor, double yCor)
        : xCor_(xCor), yCor_(yCor) {
    std::cout << "called constructor\n";
}

Point::Point(const Point &other) {
    this->xCor_ = other.xCor_;
    this->yCor_ = other.yCor_;
    std::cout << "called copy constructor\n";
}

Point &Point::operator=(const Point &point) {
    this->xCor_ = point.xCor_;
    this->yCor_ = point.yCor_;
    std::cout << "called operator =\n";
    return *this;
}

Point &Point::operator=(std::pair<double, double> x) {
    this->xCor_ = x.first;
    this->yCor_ = x.second;
    std::cout << "called operator =\n";
    return *this;
}

void Point::print() const {
    std::cout << '(' << this->xCor_ << " " << this->yCor_ << ')' << '\n';
}

double findDist(const Point &p1, const Point &p2) {
    double dx = std::abs(p1.xCor_ - p2.xCor_);
    double dy = std::abs(p1.yCor_ - p2.yCor_);
    return sqrt(dx * dx + dy * dy);
}

