#pragma once
#include <sstream>
#include <limits>
#include <iostream>
#include <iomanip>
#include <iomanip>

class ScalarConverter {
public:
    // Static method for converting string literals to various scalar types
    static void convert(const std::string& literal);

private:
 	ScalarConverter();
    // ScalarConverter(const ScalarConverter&);
    ~ScalarConverter();
    // ScalarConverter& operator=(const ScalarConverter&);
};