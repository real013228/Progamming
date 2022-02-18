//
// Created by real0 on 19.02.2022.
//

#ifndef OOP_POLYGON_H
#define OOP_POLYGON_H

#include "ClosedBrokenLine.h"

class Polygon : public ClosedBrokenLine {
public:
    Polygon();

    Polygon(int size) : ClosedBrokenLine();

    Polygon(const Polygon &other) : ClosedBrokenLine(other);

    Polygon &operator=(const Polygon &other);

    double getArray() const;

    ~Polygon();
};

#endif //OOP_POLYGON_H
