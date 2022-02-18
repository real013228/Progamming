#ifndef OOP_POLYNOMIAL_H
#define OOP_POLYNOMIAL_H

double max(double a, double b);

class Polynomial {
private:
    int degree_{};
    double *coeffs_{};
public:
    Polynomial();

    Polynomial(int size);

    Polynomial(int degree, const double *coeffs);

    Polynomial(const Polynomial &other);

    Polynomial &operator=(const Polynomial &rightOther);

    bool operator==(const Polynomial &other);

    bool operator!=(const Polynomial &other);

    Polynomial &operator++();

    Polynomial &operator--();

    Polynomial &operator-();

    Polynomial &operator+(const Polynomial &other);

    Polynomial &operator+=(const Polynomial &other);

    Polynomial &operator-(Polynomial &other);

    Polynomial &operator-=(Polynomial &other);

    Polynomial &operator*(double value);

    Polynomial &operator*(const Polynomial &other) const;

    Polynomial &operator*=(double value);

    Polynomial &operator/(double value);

    Polynomial &operator/=(double value);

    Polynomial &operator<<(int ind);

    Polynomial &operator>>(int ind);

    double &operator[](int index);

    void printCoeffs();

    ~Polynomial();

    friend std::ostream &operator<<(std::ostream &out, const Polynomial &poly);

    friend std::istream &operator>>(std::istream &in, Polynomial &poly);
};

#endif
