#include "dog.hpp"

Dog::Dog() : Animal("Dog"), _b(new Brain())
{
    std::cout << "Dog default constructor called!!" << std::endl;
}

Dog::Dog(const Dog &dog) : Animal(dog) ,_b(new Brain(*dog._b))
{

    std::cout << "Dog class's copy constructor called!!" << std::endl;
}

Dog &Dog::operator=(const Dog &c)
{
    if (this == &c)
        return (*this);
    delete _b;
    _b = new Brain(*c._b);
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "Dog makesound() called: Haf-Haf!!" << std::endl;
}

Dog::~Dog()
{
    std::cout << this->_type << "Dog destructor called!!" << std::endl;
    delete _b;
}