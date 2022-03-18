//
// Created by real0 on 16.03.2022.
//

#ifndef OOP2_CURRENCIES_H
#define OOP2_CURRENCIES_H
#include <iostream>
#include <vector>
#include "Currency.h"
#define COUNTOFVALUES 34
#define TIME 10000

class Currencies {
public:
    std::vector<std::vector<Currency>> values;

    explicit Currencies(int size);

    float medium(int nameOfCurrency, int rounds);

    float middle(int nameOfCurrency, int rounds);
};


#endif //OOP2_CURRENCIES_H
