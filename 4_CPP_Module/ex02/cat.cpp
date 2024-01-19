#include "cat.hpp"

Cat::Cat() : Animal("Cat"), _b(new Brain())
{
    std::cout << "Cat default constructor called!!" << std::endl;
}

Cat::Cat(const Cat &cat) : Animal(cat) ,_b(new Brain(*cat._b))
{
    std::cout << "Cat class's copy constructor called!!" << std::endl;
}

Cat &Cat::operator=(const Cat &c)
{
     if (this == &c)
        return (*this);
    delete _b;
    _b = new Brain(*c._b);
    return (*this);
}


void Cat::makeSound() const
{
    std::cout << "Cat makesound() called: Meauu!!" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called!!" << std::endl;
    delete _b;
}