#include <iostream>
#include <vector>
#include "MyAllocator.h"
#include <map>


int main() {
    std::vector<double, MyAllocator<double>> vec(5);
    vec.push_back(1);
    for(auto &i: vec) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
    return 0;
}
