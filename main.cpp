#include <iostream>
#include <cmath>
#include <vector>
#define DELTA 0.001

double max(double a, double b){
    return a > b ? a : b;
}

class Point{
public:
    double xCor_;
    double yCor_;
    Point() = default;
    Point(double xCor, double yCor)
    : xCor_(xCor)
    , yCor_(yCor)
    {
        std::cout << "called constructor\n";
    }
    Point(const Point& other){
        this->  xCor_ = other.xCor_;
        this->yCor_ = other.yCor_;
        std::cout << "called copy constructor\n";
    }

    Point& operator = (const Point& point){
        this->xCor_ = point.xCor_;
        this->yCor_ = point.yCor_;
        std::cout << "called operator =\n";
        return *this;
    }

    Point& operator = (std::pair<double, double> x){
        this->xCor_ = x.first;
        this->yCor_ = x.second;
        std::cout << "called operator =\n";
        return *this;
    }
    void print() const{
        std::cout << '(' << this->xCor_ << " " << this->yCor_ << ')' << '\n';
    }
};

double findDist(const Point& p1, const Point& p2){
    double dx = std::abs(p1.xCor_ - p2.xCor_);
    double dy = std::abs(p1.yCor_ - p2.yCor_);
    return sqrt(dx*dx + dy*dy);
}

class BrokenLine{
public:
    int size_;
    Point* line_;

    BrokenLine() = default;
    BrokenLine(int size){
        size_ = size;
        line_ = new Point[size];
        Point zero(0, 0);
        for(size_t i = 0; i < size; i++){
            line_[i] = zero;
        }
    }
    BrokenLine(const BrokenLine& other){
        this->line_ = new Point[other.size_];
        this->size_ = other.size_;
        for(size_t i = 0; i < other.size_; i++){
            this->line_[i] = other.line_[i];
        }
    }

    ~BrokenLine(){
        size_ = 0;
        delete[] line_;
    };

    BrokenLine& operator = (const BrokenLine& other){
        delete[] this->line_;
        this->size_ = other.size_;
        this->line_ = new Point[size_];
        for(size_t i = 0; i < size_; i++){
            this->line_[i] = other.line_[i];
        }
        return *this;
    }
    double getPerimeter() const{
        double ans = 0;
        for(size_t i = 0; i < size_ - 1; i++){
            ans += findDist(line_[i], line_[i + 1]);
        }
        return ans;
    }
    int getSize() const;
    void print() const;
};

int BrokenLine::getSize() const{
    return size_;
}
void BrokenLine::print() const {
    for(size_t i = 0; i < size_; i++){
        std::cout << '(' << line_[i].xCor_ << ", " << line_[i].yCor_ << ')' << '\n';
    }
}

class ClosedBrokenLine : public BrokenLine{
public:
    ClosedBrokenLine() = default;
    explicit ClosedBrokenLine(int size) : BrokenLine(){
        size_ = size;
        line_ = new Point[size];
        Point zero(0, 0);
        for(size_t i = 0; i < size; i++){
            line_[i] = zero;
        }
    }
    ClosedBrokenLine(const ClosedBrokenLine& other) : BrokenLine(other) {
        this->line_ = new Point[other.size_];
        this->size_ = other.size_;
        for(size_t i = 0; i < other.size_; i++){
            this->line_[i] = other.line_[i];
        }
    }

    ClosedBrokenLine& operator = (const ClosedBrokenLine& other){
        delete[] this->line_;
        this->size_ = other.size_;
        this->line_ = new Point[size_];
        for(size_t i = 0; i < size_; i++){
            this->line_[i] = other.line_[i];
        }
        return *this;
    }
    double getPerimeterClosed(){
        double ans = 0;
        ans += this->getPerimeter();
        ans += findDist(this->line_[0],this->line_[size_ - 1]);
        return ans;
    }
    ~ClosedBrokenLine() = default;
};

class Polygon : public ClosedBrokenLine{
public:
    Polygon() = default;
    Polygon(int size) : ClosedBrokenLine(){
        size_ = size;
        line_ = new Point[size];
        Point zero(0, 0);
        for(size_t i = 0; i < size; i++){
            line_[i] = zero;
        }
    }
    Polygon(const Polygon& other) : ClosedBrokenLine(other) {
        this->line_ = new Point[other.size_];
        this->size_ = other.size_;
        for(size_t i = 0; i < other.size_; i++){
            this->line_[i] = other.line_[i];
        }
    }

    Polygon& operator = (const Polygon& other){
        delete[] this->line_;
        this->size_ = other.size_;
        this->line_ = new Point[size_];
        for(size_t i = 0; i < size_; i++){
            this->line_[i] = other.line_[i];
        }
        return *this;
    }
    double getArray() const{
        double ans = 0;
        for(size_t i = 0; i < size_ - 1; i++){
            ans += line_[i].xCor_ * line_[i + 1].yCor_;
        }
        for(size_t i = 1; i < size_; i++){
            ans -= line_[i].xCor_ * line_[i - 1].yCor_;
        }
        ans += line_[size_ - 1].xCor_ * line_[0].yCor_;
        ans -= line_[0].xCor_ * line_[size_ - 1].yCor_;
        return std::abs(ans) / 2;
    }
    ~Polygon() = default;
};

class Triangle {
private:
    Point p1_{};
    Point p2_{};
    Point p3_{};
public:
    Triangle() = default;
    Triangle(const Point& p1, const Point& p2, const Point& p3){
        p1_ = p1;
        p2_ = p2;
        p3_ = p3;
    }
    Triangle(const Triangle& other){
        p1_ = other.p1_;
        p2_ = other.p2_;
        p3_ = other.p3_;
    }
    Triangle& operator = (const Triangle& other)= default;
    ~Triangle() = default;
    double getArray() const{
        double ans = 0;
        ans += p1_.xCor_ * p2_.yCor_;
        ans += p2_.xCor_ * p3_.yCor_;

        ans -= p2_.xCor_ * p1_.yCor_;
        ans -= p3_.xCor_ * p2_.yCor_;

        ans += p3_.xCor_ * p1_.yCor_;

        ans -= p1_.xCor_ * p3_.yCor_;
        return std::abs(ans) / 2;
    }
};

class Trapezoid{
public:
    Point p1_;
    Point p2_;
    Point p3_;
    Point p4_;

    static bool checkTrapezoid(const Point& p1, const Point& p2, const Point& p3, const Point& p4) {
        if(std::abs(p1.yCor_ - p2.yCor_) * std::abs(p3.xCor_ - p4.xCor_) == std::abs(p3.yCor_ - p4.yCor_) * std::abs(p1.xCor_ - p2.xCor_) || std::abs(p3.yCor_ - p2.yCor_) * std::abs(p1.xCor_ - p4.xCor_) == std::abs(p1.yCor_ - p4.yCor_) * std::abs(p3.xCor_ - p2.xCor_)){
            return true;
        } else {
            return false;
        }
    }
    Trapezoid() = default;
    Trapezoid(const Point& p1, const Point& p2, const Point& p3, const Point& p4){
        this->p1_ = p1;
        this->p2_ = p2;
        this->p3_ = p3;
        this->p4_ = p4;
    }
    Trapezoid(const Trapezoid& other){
        if(checkTrapezoid(other.p1_, other.p2_, other.p3_, other.p4_)){
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
    Trapezoid& operator = (const Trapezoid& other){
        if(checkTrapezoid(other.p1_, other.p2_, other.p3_, other.p4_)){
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
};

class RegularPolygon : public Polygon {
public:
    RegularPolygon(int size, Point* arr){
        line_ = new Point[size];
        size_ = size;
        Point zero(0, 0);
        for(size_t i = 0; i < size_; i++){
            line_[i] = arr[i];
        }
        double edge = findDist(arr[0], arr[1]);
        for(size_t i = 0; i < size_ - 1; i++) {
            if (findDist(arr[i], arr[i + 1]) - edge > DELTA || findDist(arr[0], arr[size_ - 1]) - edge > DELTA){
                std::cout << findDist(arr[0], arr[size_ - 1]) << "it's not regular polygon, so it will be nullified\n";
                for(size_t j = 0; j < size_; j++) {
                    line_[j] = zero;
                }
                break;
            }
        }
    }
};

class Polynomial{
private:
    int degree_;
    double* coeffs_;
public:
    Polynomial() = default;
    Polynomial(int size){
        degree_ = size;
        coeffs_ = new double[size];
        for(size_t i = 0; i < size; i++){
            coeffs_[i] = 0;
        }
    }
    Polynomial(int degree, const double* coeffs){
        degree_ = degree;
        coeffs_ = new double[degree_];
        for(size_t i = 0; i < degree_; i++){
            coeffs_[i] = coeffs[i];
        }
    }
    Polynomial(const Polynomial& other){
        if(this->coeffs_)
            delete[] coeffs_;
        coeffs_ = new double [other.degree_];
        degree_ = other.degree_;
        for(size_t i = 0; i < degree_; i++){
            coeffs_[i] = other.coeffs_[i];
        }
    }
    Polynomial& operator = (const Polynomial& other){
        delete[] coeffs_;
        coeffs_ = new double [other.degree_];
        degree_ = other.degree_;
        for(size_t i = 0; i < degree_; i++){
            coeffs_[i] = other.coeffs_[i];
        }
    }

    bool operator == (const Polynomial& other){
        if(this->degree_ == other.degree_){
            for(size_t i = 0; i < degree_; i++){
                if(coeffs_[i] != other.coeffs_[i]){
                    return false;
                }
            }
            return true;
        } else {
            return false;
        }
    }

    bool operator != (const Polynomial& other){
        if(this->degree_ == other.degree_){
            for(size_t i = 0; i < degree_; i++){
                if(coeffs_[i] != other.coeffs_[i]){
                    return true;
                }
            }
            return false;
        } else {
            return true;
        }
    }

    Polynomial& operator ++ (){
        for(size_t i = 0; i < degree_; i++){
            coeffs_[i] = coeffs_[i] + 1;
        }
        return *this;
    }

    Polynomial& operator -- (){
        for(size_t i = 0; i < degree_; i++){
            coeffs_[i] = coeffs_[i] - 1;
        }
        return *this;
    }
    Polynomial& operator - (){
        for(size_t i = 0; i < degree_; i++){
            coeffs_[i] = coeffs_[i] * (-1);
        }
        return *this;
    }
    Polynomial& operator + (const Polynomial& other){
        Polynomial* result = new Polynomial(max(degree_, other.degree_), degree_ > other.degree_ ? coeffs_ : other.coeffs_);
        result->degree_ = max(degree_, other.degree_);
        double diff = this->degree_ - other.degree_;
        for(size_t i = 0; i < result->degree_; i++){
            result->coeffs_[i] = diff > 0 ?
                    diff > i ? this->coeffs_[i] : this->coeffs_[i] + other.coeffs_[i] :
                    diff + i < 0 ? other.coeffs_[i] : this->coeffs_[i] + other.coeffs_[i];
        }
        return *result;
    }


    Polynomial& operator += (const Polynomial& other){
        this->degree_ = max(degree_, other.degree_);
        double diff = this->degree_ - other.degree_;
        for(size_t i = 0; i < this->degree_; i++){
            this->coeffs_[i] = diff > 0 ?
                                 diff > i ? this->coeffs_[i] : this->coeffs_[i] + other.coeffs_[i] :
                                 diff + i < 0 ? other.coeffs_[i] : this->coeffs_[i] + other.coeffs_[i];
        }
        return *this;
    }

    Polynomial& operator - (Polynomial& other){
        return *this + (other * (-1));
    }

    Polynomial& operator -= (Polynomial& other){
        *this = *this + (other * (-1));
        return *this;
    }

    Polynomial& operator * (double value){
        Polynomial* result = new Polynomial();
        result->degree_ = degree_;
        if (value == 0) {
            result->coeffs_ = new double[degree_]{0};
        } else {
            result->coeffs_ = new double [this->degree_];
            for (size_t i = 0; i < this->degree_; i++)
                result->coeffs_[i] = this->coeffs_[i] * value;
        }
        return *result;
    }

    Polynomial& operator *= (double value){
        if (value == 0) {
            this->coeffs_ = new double[degree_]{0};
        } else {
            for (size_t i = 0; i < this->degree_; i++)
                this->coeffs_[i] = this->coeffs_[i] * value;
        }
        return *this;
    }

    Polynomial& operator / (double value){
        Polynomial* result = new Polynomial();
        result->degree_ = degree_;
        if (value == 0) {
            result->coeffs_ = new double[degree_]{0};
        } else {
            result->coeffs_ = new double [this->degree_];
            for (size_t i = 0; i < this->degree_; i++)
                result->coeffs_[i] = this->coeffs_[i] / value;
        }
        return *result;
    }

    Polynomial& operator /= (double value){
        if (value == 0) {
            this->coeffs_ = new double[degree_]{0};
        } else {
            for (size_t i = 0; i < this->degree_; i++)
                this->coeffs_[i] = this->coeffs_[i] / value;
        }
        return *this;
    }

    Polynomial& operator << (int ind){
        Polynomial *result = new Polynomial();
        result->coeffs_ = new double[degree_ - ind];
        result->degree_ = degree_ - ind;

        for(int i = 0; i < degree_ - ind; i++) {
            result->coeffs_[i] = this->coeffs_[i + ind];
        }
        return *result;
    }

    Polynomial& operator >> (int ind){
        Polynomial *result = new Polynomial();
        result->coeffs_ = new double[degree_ - ind];
        result->degree_ = degree_ - ind;

        for(int i = 0; i < degree_ - ind; i++) {
            result->coeffs_[i] = this->coeffs_[i];
        }
        return *result;
    }

    double& operator [] (int index){
        return coeffs_[index];
    }

    void printCoeffs(){
        for(size_t i = 0; i < degree_; i++){
            std::cout << coeffs_[i] << ' ';
        }
        std::cout << '\n';
    }

    ~Polynomial(){
        degree_ = 0;
        delete[] coeffs_;
    }
    friend std::ostream& operator << (std::ostream& out, const Polynomial& poly);
    friend std::istream& operator >> (std::istream& in, Polynomial& poly);
};

std::ostream& operator << (std::ostream& out, const Polynomial& poly) {
    for (size_t i = 0; i < poly.degree_; i++) {
        out << poly.coeffs_[i] << ' ';
    }
    return out;
}

std::istream& operator >> (std::istream& in, Polynomial& poly){
    for(size_t i = 0; i < poly.degree_; i++){
        in >> poly.coeffs_[i];
    }
    return in;
}

int main() {

    Point a(1, 1);
    Point b(1, 2);
    Point c(2, 2);
    BrokenLine l1(4);
    BrokenLine l2(2);
    BrokenLine l3{};

    ClosedBrokenLine l4(4);
    ClosedBrokenLine l5(1);
    for(int i = 0; i < l4.getSize(); i++){
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
    std::cout << findDist(a, b) * findDist(a, b) + findDist(b, c) * findDist(b, c) - findDist(a, c) * findDist(a, c) << '\n';
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
    double arr1[4] = {1, 2, 3, 4};
    double arr2[7] = {1, 2, 3, 5, 2, 3, 4};
    Polynomial poly1(4, arr1);
    Polynomial poly2(7, arr2);
    poly1 = poly2 / 3;


    int size1;
    std::cout << "Enter degree of polynomial\n";
    std::cin >> size1;
    Polynomial poly0(size1);
    std::cin >> poly0;
    std::cout << poly0 << '\n';
    poly0 = poly2;
    std::cout << poly0 << '\n';
//    std::cout << poly1[0] << ' ' << poly1[1] << ' ' << poly1[2] << '\n';
//    poly1 = poly1 >> 1;
//    std::cout << poly1[0] << ' ' << poly1[1] << ' ' << poly1[2] << '\n';
    return 0;
}
