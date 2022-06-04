#include <iostream>


template<int degree>
constexpr int valueToDegree(int value) {
    return value * valueToDegree<degree - 1>(value);
}

template<>
constexpr int valueToDegree<1>(int value) {
    return value;
}

template<>
constexpr int valueToDegree<0>(int value) {
    return 1;
}

template<int value, int curDegree, int ... coefficients>
struct Answer;

template<int value, int curDegree, int curCoeff, int ... coefficients>
struct Answer<value, curDegree, curCoeff, coefficients...> {
    static int const answer = valueToDegree<curDegree>(value) * curCoeff + Answer<value, curDegree + 1, coefficients...>::answer;
};

template<int value, int degree>
struct Answer<value, degree> {
    static int const answer = 0;
};

template<int value, int ...coefficients>
struct Polynomial {
    static int const answer = Answer<value, 0, coefficients...>::answer;
};

//template<int value, int curCoefficient, int ...coefficients>
//std::ostream &operator<<(std::ostream &out, Polynomial<value, curCoefficient, coefficients...> &poly) {
//    out << curCoefficient << Polynomial<value, coefficients...>();
//    return out;
//}


template<int value, int curCoefficient, int ...coefficients>
std::ostream &operator<<(std::ostream &out, Polynomial<value, curCoefficient, coefficients...>) {
    out << curCoefficient << Polynomial<value, coefficients...>();
    return out;
}

template <int value>
std::ostream &operator<<(std::ostream &out, Polynomial<value>) {
    return out;
}

