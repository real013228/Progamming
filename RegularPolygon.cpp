//
// Created by real0 on 19.02.2022.
//

#include "RegularPolygon.h"

RegularPolygon::RegularPolygon(int size, Point* arr){
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