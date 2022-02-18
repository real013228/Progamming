//
// Created by real0 on 18.02.2022.
//

#include "ClosedBrokenLine.h"


ClosedBrokenLine::ClosedBrokenLine() = default;

ClosedBrokenLine::ClosedBrokenLine(int size) {
    size_ = size;
    line_ = new Point[size];
    Point zero(0, 0);
    for (size_t i = 0; i < size; i++) {
        line_[i] = zero;
    }
}

ClosedBrokenLine::ClosedBrokenLine(const ClosedBrokenLine &other)  : BrokenLine(other) {
    this->line_ = new Point[other.size_];
    this->size_ = other.size_;
    for (size_t i = 0; i < other.size_; i++) {
        this->line_[i] = other.line_[i];
    }
}

ClosedBrokenLine &ClosedBrokenLine::operator=(const ClosedBrokenLine &other) {
    delete[] this->line_;
    this->size_ = other.size_;
    this->line_ = new Point[size_];
    for (size_t i = 0; i < size_; i++) {
        this->line_[i] = other.line_[i];
    }
    return *this;
}

double ClosedBrokenLine::getPerimeterClosed() {
    double ans = 0;
    ans += this->getPerimeter();
    ans += findDist(this->line_[0], this->line_[size_ - 1]);
    return ans;
}

ClosedBrokenLine::~ClosedBrokenLine() = default;

