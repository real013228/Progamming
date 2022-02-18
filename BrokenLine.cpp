//
// Created by real0 on 18.02.2022.
//
#include "BrokenLine.h"


BrokenLine::BrokenLine() = default;

BrokenLine::BrokenLine(int size) {
    size_ = size;
    line_ = new Point[size];
    Point zero(0, 0);
    for (size_t i = 0; i < size; i++) {
        line_[i] = zero;
    }
}

BrokenLine::BrokenLine(const BrokenLine &other) {
    this->line_ = new Point[other.size_];
    this->size_ = other.size_;
    for (size_t i = 0; i < other.size_; i++) {
        this->line_[i] = other.line_[i];
    }
}

BrokenLine::~BrokenLine() {
    size_ = 0;
    delete[] line_;
};

BrokenLine &BrokenLine::operator=(const BrokenLine &other) {
    delete[] this->line_;
    this->size_ = other.size_;
    this->line_ = new Point[size_];
    for (size_t i = 0; i < size_; i++) {
        this->line_[i] = other.line_[i];
    }
    return *this;
}

double BrokenLine::getPerimeter() const {
    double ans = 0;
    for (size_t i = 0; i < size_ - 1; i++) {
        ans += findDist(line_[i], line_[i + 1]);
    }
    return ans;
}

int BrokenLine::getSize() const {
    return size_;
}

void BrokenLine::print() const {
    for (size_t i = 0; i < size_; i++) {
        std::cout << '(' << line_[i].xCor_ << ", " << line_[i].yCor_ << ')' << '\n';
    }
}

