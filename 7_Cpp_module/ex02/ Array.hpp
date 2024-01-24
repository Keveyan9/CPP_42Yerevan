#include <iostream>
#include <exception>

// Array class template
template <typename T>
class Array {
private:
    T* elements; // Pointer to the array elements
    unsigned int arraySize; // Number of elements in the array

public:
    // Default constructor: creates an empty array
    Array() : elements(nullptr), arraySize(0) {}

    // Parameterized constructor: creates an array of n elements initialized by default
    explicit Array(unsigned int n) : arraySize(n) {
        elements = new T[arraySize];
        for (unsigned int i = 0; i < arraySize; ++i) {
            elements[i] = T(); // Default initialization
        }
    }

    // Copy constructor
    Array(const Array& other) : arraySize(other.arraySize) {
        elements = new T[arraySize];
        for (unsigned int i = 0; i < arraySize; ++i) {
            elements[i] = other.elements[i];
        }
    }

    // Assignment operator
    Array& operator=(const Array& other) {
        if (this != &other) { // Avoid self-assignment
            delete[] elements; // Deallocate existing memory

            arraySize = other.arraySize;
            elements = new T[arraySize];

            for (unsigned int i = 0; i < arraySize; ++i) {
                elements[i] = other.elements[i];
            }
        }
        return *this;
    }

    // Destructor
    ~Array() {
        delete[] elements;
    }

    // Subscript operator: allows access to array elements
    T& operator[](unsigned int index) {
        if (index >= arraySize) {
            throw std::out_of_range("Index out of bounds");
        }
        return elements[index];
    }

    // Member function size: returns the number of elements in the array
    unsigned int size() const {
        return arraySize;
    }
};