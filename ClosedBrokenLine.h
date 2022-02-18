//
// Created by real0 on 18.02.2022.
//

#ifndef OOP_CLOSEDBROKENLINE_H
#define OOP_CLOSEDBROKENLINE_H

#include "BrokenLine.h"

class ClosedBrokenLine : public BrokenLine {
public:
    ClosedBrokenLine();

    explicit ClosedBrokenLine(int size);

    ClosedBrokenLine(const ClosedBrokenLine &other);

    ClosedBrokenLine &operator=(const ClosedBrokenLine &other);

    double getPerimeterClosed();

    ~ClosedBrokenLine();
};

#endif //OOP_CLOSEDBROKENLINE_H
