//
// Created by real0 on 16.03.2022.
//

#include "Currencies.h"
#include <algorithm>

float Currencies::medium(int nameOfCurrency, int rounds) {
    float average = 0;
    for (int i = 0; i < rounds; ++i){
        average += values[i][nameOfCurrency].value;
    }
    return average / static_cast<float>(rounds);
}

float Currencies::middle(int nameOfCurrency, int rounds) {
    std::vector<float> arr(rounds);
    for(int i = 0; i < rounds; ++i){
        arr.push_back(values[i][nameOfCurrency].value);
    }
    std::sort(arr.begin(), arr.end());
    return arr[arr.size() / 2];
}

Currencies::Currencies(int size) {
    std::vector<Currency> ap(COUNTOFVALUES);
    for(int i = 0; i < size; ++i){
        values.push_back(ap);
    }
}
