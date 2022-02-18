#include <iostream>
#include <cmath>
#include <vector>
#include "Polynomial.h"
#include "Point.h"
#include "BrokenLine.h"
#include "ClosedBrokenLine.h"
#include "Polygon.h"
#include "Triangle.h"
#include "Trapezoid.h"
#include "RegularPolygon.h"

#define DELTA 0.001


int main() {

    Point a(1, 1);
    Point b(1, 2);
    Point c(2, 2);
    BrokenLine l1(4);
    BrokenLine l2(2);
    BrokenLine l3{};

    ClosedBrokenLine l4(4);
    ClosedBrokenLine l5(1);
    for (int i = 0; i < l4.getSize(); i++) {
        l4.line_[i].xCor_ = i;
        l4.line_[i].yCor_ = i;
    }
    std::cout << l4.getPerimeterClosed() << '\n';
//    std::cout << l1.getPerimeter() << '\n';
//    Polygon p1(5);
//    p1.line_[0].xCor_ = 3;
//    p1.line_[0].yCor_ = 4;
//
//    p1.line_[1].xCor_ = 5;
//    p1.line_[1].yCor_ = 11;
//
//    p1.line_[2].xCor_ = 12;
//    p1.line_[2].yCor_ = 8;
//
//    p1.line_[3].xCor_ = 9;
//    p1.line_[3].yCor_ = 5;
//
//    p1.line_[4].xCor_ = 5;
//    p1.line_[4].yCor_ = 6;
//    p1.print();
//    std::cout << p1.getArray() << '\n';
    Point d(2, 1);
    Point e(1, 3);
    Triangle tr1(a, b, c);
    Triangle tr2;
    tr2 = tr1;
    std::cout << findDist(a, b) * findDist(a, b) + findDist(b, c) * findDist(b, c) - findDist(a, c) * findDist(a, c)
              << '\n';
    std::cout << tr1.getArray() << '\n';

    Trapezoid trap1(a, b, c, d);
    Trapezoid trap2(a, b, c, e);
    trap1 = trap2;
    Polygon po(3);
    Point arr[4] = {a, b, c, d};
    RegularPolygon rep(4, arr);
//    std::cout << rep.getArray() << '\n';
//    std::cout << rep.getPerimeterClosed() << '\n';
//    RegularPolygon rep(3);

//Polynomials **********************************
    double arr1[3] = {1, 2, 3};
    double arr2[7] = {1, 2, 3, 5, 2, 3, 4};
    Polynomial poly1(3, arr1);
    Polynomial poly2(7, arr2);


    int size1;
    std::cout << "Enter degree of Polynomial\n";
    std::cin >> size1;
    Polynomial poly0(size1);
    std::cin >> poly0;
    std::cout << poly0 << ' ' << poly1 << '\n';
    std::cout << poly0 * poly1 << '\n';
//    std::cout << poly0 << '\n';
//    std::cout << poly1[0] << ' ' << poly1[1] << ' ' << poly1[2] << '\n';
//    poly1 = poly1 >> 1;
//    std::cout << poly1[0] << ' ' << poly1[1] << ' ' << poly1[2] << '\n';
    return 0;
}

