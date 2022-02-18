#include <iostream>
#include "Polynomial.h"

#pragma once

double max(double a, double b) {
    return a > b ? a : b;
}

Polynomial::Polynomial() = default;

Polynomial::Polynomial(int size) {
    degree_ = size;
    coeffs_ = new double[size];
    for (size_t i = 0; i < size; i++) {
        coeffs_[i] = 0;
    }
}

Polynomial::Polynomial(int degree, const double *coeffs) {
    degree_ = degree;
    coeffs_ = new double[degree_];
    for (size_t i = 0; i < degree_; i++) {
        coeffs_[i] = coeffs[i];
    }
}

Polynomial::Polynomial(const Polynomial &other) {
    delete[] coeffs_;
    coeffs_ = new double[other.degree_];
    degree_ = other.degree_;
    for (size_t i = 0; i < degree_; i++) {
        coeffs_[i] = other.coeffs_[i];
    }
}

Polynomial &Polynomial::operator=(const Polynomial &rightOther) {
    delete[] coeffs_;
    coeffs_ = new double[rightOther.degree_];
    degree_ = rightOther.degree_;
    for (size_t i = 0; i < degree_; i++) {
        coeffs_[i] = rightOther.coeffs_[i];
    }
    return *this;
}

bool Polynomial::operator==(const Polynomial &leftOther) {
    if (degree_ == leftOther.degree_) {
        for (size_t i = 0; i < degree_; i++) {
            if (coeffs_[i] != leftOther.coeffs_[i]) {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}

bool Polynomial::operator!=(const Polynomial &other) {
    if (degree_ == other.degree_) {
        for (size_t i = 0; i < degree_; i++) {
            if (coeffs_[i] != other.coeffs_[i]) {
                return true;
            }
        }
        return false;
    } else {
        return true;
    }
}

Polynomial &Polynomial::operator++() {
    for (size_t i = 0; i < degree_; i++) {
        coeffs_[i] = coeffs_[i] + 1;
    }
    return *this;
}

Polynomial &Polynomial::operator--() {
    for (size_t i = 0; i < degree_; i++) {
        coeffs_[i] = coeffs_[i] - 1;
    }
    return *this;
}

Polynomial &Polynomial::operator-() {
    for (size_t i = 0; i < degree_; i++) {
        coeffs_[i] = coeffs_[i] * (-1);
    }
    return *this;
}

Polynomial &Polynomial::operator+(const Polynomial &other) {
    auto *result = new Polynomial(max(degree_, other.degree_), degree_ > other.degree_ ? coeffs_ : other.coeffs_);
    result->degree_ = max(degree_, other.degree_);
    double diff = this->degree_ - other.degree_;
    for (size_t i = 0; i < result->degree_; i++) {
        result->coeffs_[i] = diff > 0 ?
                             diff > i ? this->coeffs_[i] : this->coeffs_[i] + other.coeffs_[i] :
                             diff + i < 0 ? other.coeffs_[i] : this->coeffs_[i] + other.coeffs_[i];
    }
    return *result;
}


Polynomial &Polynomial::operator+=(const Polynomial &other) {
    this->degree_ = max(degree_, other.degree_);
    double diff = this->degree_ - other.degree_;
    for (size_t i = 0; i < this->degree_; i++) {
        this->coeffs_[i] = diff > 0 ?
                           diff > i ? this->coeffs_[i] : this->coeffs_[i] + other.coeffs_[i] :
                           diff + i < 0 ? other.coeffs_[i] : this->coeffs_[i] + other.coeffs_[i];
    }
    return *this;
}

Polynomial &Polynomial::operator-(Polynomial &other) {
    return *this + (other * (-1));
}

Polynomial &Polynomial::operator-=(Polynomial &other) {
    *this = *this + (other * (-1));
    return *this;
}

Polynomial &Polynomial::operator*(double value) {
    Polynomial *result = new Polynomial();
    result->degree_ = degree_;
    if (value == 0) {
        result->coeffs_ = new double[degree_]{0};
    } else {
        result->coeffs_ = new double[this->degree_];
        for (size_t i = 0; i < this->degree_; i++)
            result->coeffs_[i] = this->coeffs_[i] * value;
    }
    return *result;
}

Polynomial &Polynomial::operator*=(double value) {
    if (value == 0) {
        this->coeffs_ = new double[degree_]{0};
    } else {
        for (size_t i = 0; i < this->degree_; i++)
            this->coeffs_[i] = this->coeffs_[i] * value;
    }
    return *this;
}

Polynomial &Polynomial::operator/(double value) {
    Polynomial *result = new Polynomial();
    result->degree_ = degree_;
    if (value == 0) {
        result->coeffs_ = new double[degree_]{0};
    } else {
        result->coeffs_ = new double[this->degree_];
        for (size_t i = 0; i < this->degree_; i++)
            result->coeffs_[i] = this->coeffs_[i] / value;
    }
    return *result;
}

Polynomial &Polynomial::operator/=(double value) {
    if (value == 0) {
        this->coeffs_ = new double[degree_]{0};
    } else {
        for (size_t i = 0; i < this->degree_; i++)
            this->coeffs_[i] = this->coeffs_[i] / value;
    }
    return *this;
}

Polynomial &Polynomial::operator<<(int ind) {
    Polynomial *result = new Polynomial();
    result->coeffs_ = new double[degree_ - ind];
    result->degree_ = degree_ - ind;

    for (int i = 0; i < degree_ - ind; i++) {
        result->coeffs_[i] = this->coeffs_[i + ind];
    }
    return *result;
}

Polynomial &Polynomial::operator>>(int ind) {
    Polynomial *result = new Polynomial();
    result->coeffs_ = new double[degree_ - ind];
    result->degree_ = degree_ - ind;

    for (int i = 0; i < degree_ - ind; i++) {
        result->coeffs_[i] = this->coeffs_[i];
    }
    return *result;
}

double &Polynomial::operator[](int index) {
    return coeffs_[index];
}

void Polynomial::printCoeffs() {
    for (size_t i = 0; i < degree_; i++) {
        std::cout << coeffs_[i] << ' ';
    }
    std::cout << '\n';
}

Polynomial::~Polynomial() {
    degree_ = 0;
    delete[] coeffs_;
}


std::ostream &operator<<(std::ostream &out, const Polynomial &poly) {
    for (size_t i = 0; i < poly.degree_; i++) {
        out << poly.coeffs_[i] << ' ';
    }
    return out;
}

std::istream &operator>>(std::istream &in, Polynomial &poly) {
    for (size_t i = 0; i < poly.degree_; i++) {
        in >> poly.coeffs_[i];
    }
    return in;
}

Polynomial &Polynomial::operator*(const Polynomial &other) const {
    Polynomial *result = new Polynomial;
    result->coeffs_ = new double [other.degree_ + degree_ - 1];
    result->degree_ = other.degree_ + degree_ - 1;
    for(size_t i = 0; i < degree_; i++){
        for(size_t j = 0; j < other.degree_; j++){
            result->coeffs_[i + j] += coeffs_[i] * other.coeffs_[j];
        }
    }
    return *result;
}

