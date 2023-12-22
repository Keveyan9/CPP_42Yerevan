#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
    std::cout << "Animal class's default constructor called!!" << std::endl;
}

Animal::Animal(const std::string &type) : _type(type)
{
    std::cout << "Animal class's parametrized constructor called!!" << std::endl;
}

Animal::Animal(const Animal &copy)
{
    *this = copy;
    std::cout << "Animal class's copy constructor called!!" << std::endl;
}

Animal &Animal::operator=(const Animal &assign)
{
    if (this == &assign)
        return (*this);
    _type = assign._type;
    return (*this);
}

void Animal::makeSound() const
{
    std::cout << "Animal makesound() called" << std::endl;
}

const std::string &Animal::getType() const
{
    return (_type);
}

Animal::~Animal()
{
    std::cout << "Animal destructor called!!" << std::endl;
}