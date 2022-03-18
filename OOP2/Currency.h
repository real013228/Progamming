//
// Created by real0 on 16.03.2022.
//

#ifndef OOP2_CURRENCY_H
#define OOP2_CURRENCY_H


class Currency {
public:
    std::string id;
    std::string numCode;
    std::string charCode;
    int nominal = 0;
    std::string name;
    float value = 0;
    float previous = 0;
};


#endif //OOP2_CURRENCY_H
