//
// Created by real0 on 18.02.2022.
//

#ifndef OOP_BROKENLINE_H
#define OOP_BROKENLINE_H
#include "Point.h"
class BrokenLine{
public:
    int size_{};
    Point* line_{};

    BrokenLine();
    BrokenLine(int size);
    BrokenLine(const BrokenLine& other);
    ~BrokenLine();
    BrokenLine& operator = (const BrokenLine& other);
    double getPerimeter() const;
    int getSize() const;
    void print() const;
};



#endif //OOP_BROKENLINE_H
