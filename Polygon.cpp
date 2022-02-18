//
// Created by real0 on 19.02.2022.
//

#include "Polygon.h"

Polygon::Polygon() = default;

Polygon::Polygon(int size) : ClosedBrokenLine() {
    size_ = size;
    line_ = new Point[size];
    Point zero(0, 0);
    for (size_t i = 0; i < size; i++) {
        line_[i] = zero;
    }
}

Polygon::Polygon(const Polygon &other) : ClosedBrokenLine(other) {
    this->line_ = new Point[other.size_];
    this->size_ = other.size_;
    for (size_t i = 0; i < other.size_; i++) {
        this->line_[i] = other.line_[i];
    }
}

Polygon &Polygon::operator=(const Polygon &other) {
    delete[] this->line_;
    this->size_ = other.size_;
    this->line_ = new Point[size_];
    for (size_t i = 0; i < size_; i++) {
        this->line_[i] = other.line_[i];
    }
    return *this;
}

double Polygon::getArray() const {
    double ans = 0;
    for (size_t i = 0; i < size_ - 1; i++) {
        ans += line_[i].xCor_ * line_[i + 1].yCor_;
    }
    for (size_t i = 1; i < size_; i++) {
        ans -= line_[i].xCor_ * line_[i - 1].yCor_;
    }
    ans += line_[size_ - 1].xCor_ * line_[0].yCor_;
    ans -= line_[0].xCor_ * line_[size_ - 1].yCor_;
    return std::abs(ans) / 2;
}

Polygon::~Polygon() = default;
