#include "cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat default constructor called!!" << std::endl;
}

Cat::Cat(const Cat &cat) : Animal(cat)
{
    *this = cat;
    std::cout << "Cat class's copy constructor called!!" << std::endl;
}

Cat &Cat::operator=(const Cat &)
{
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "Cat makesound() called: Meauu!!" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called!!" << std::endl;
}