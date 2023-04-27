//
// Created by Doctor on 4/24/2023.
//

#include "dynamic.h"
template<typename T>
dynamic<T>::dynamic() {
    start_pointer = nullptr;
    arr_size = 0;
}

template<typename T>
void dynamic<T>::print() {
    for(int i = 0; i < this->arr_size; i++){
        std::cout << (*this)[i] << ", ";
    }
    std::cout << std::endl;
}