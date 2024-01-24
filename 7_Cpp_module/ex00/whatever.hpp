#pragma once
#include <iostream>

// Function template for swapping two values
template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// Function template for finding the minimum of two values
template <typename T>
T min(const T& a, const T& b) {
    return (b < a) ? b : a;
}

// Function template for finding the maximum of two values
template <typename T>
T max(const T& a, const T& b) {
    return (a < b) ? b : a;
}