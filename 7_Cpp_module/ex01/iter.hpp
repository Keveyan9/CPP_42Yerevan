#pragma once 
#include <iostream>

template <typename T, typename Function>
void iter(T* array, size_t length, Function func) {
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}

// Function template to demonstrate usage
template <typename T>
void printElement(const T& element) {
    std::cout << element << " ";
}