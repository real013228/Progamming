//
// Created by real0 on 19.02.2022.
//
#ifndef OOP_REGULARPOLYGON_H
#define OOP_REGULARPOLYGON_H

#include "Polygon.h"
#define DELTA 0.001

class RegularPolygon : public Polygon {
public:
    RegularPolygon(int size, Point *arr);
};

#endif //OOP_REGULARPOLYGON_H
