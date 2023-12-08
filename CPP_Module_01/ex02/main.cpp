#include <iostream>
#include <iomanip>

int main()
{
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPtr = &string;
    std::string &stringRef = string;

    std::cout << "Memory address of the string: " << &string << "\n";
    std::cout << "Memory address held by stringPtr: " << stringPtr << "\n";
    std::cout << "Memory address held by stringRef: " << &stringRef << "\n";

    std::cout << "The value of string variable: " << string << "\n";
    std::cout << "The value of stringPtr variable: " << *stringPtr << "\n";
    std::cout << "The value of stringRef variable: " << stringRef << "\n";
}