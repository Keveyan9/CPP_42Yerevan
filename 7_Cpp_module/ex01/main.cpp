#include <iostream>
#include "iter.hpp"

int main() {
    // Test case 1: Using iter with integers
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Iterating over intArray: ";
    iter(intArray, intArrayLength, printElement<int>);
    std::cout << std::endl;

    // Test case 2: Using iter with doubles
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    size_t doubleArrayLength = sizeof(doubleArray) / sizeof(doubleArray[0]);

    std::cout << "Iterating over doubleArray: ";
    iter(doubleArray, doubleArrayLength, printElement<double>);
    std::cout << std::endl;

    // Test case 3: Using iter with strings
    std::string stringArray[] = {"apple", "banana", "cherry"};
    size_t stringArrayLength = sizeof(stringArray) / sizeof(stringArray[0]);

    std::cout << "Iterating over stringArray: ";
    iter(stringArray, stringArrayLength, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}