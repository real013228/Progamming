#include <iostream>
#include "Polynomial.h"


int main() {
    constexpr int x = 5;
    Polynomial<2, 1, 1>p1;
    std::cout << p1;
    std::cout << Polynomial<13, 1, 1>();
    return 0;
}
