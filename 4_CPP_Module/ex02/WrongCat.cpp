#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "WrongCat default constructor called!!" << std::endl;
}

WrongCat::WrongCat(const WrongCat &cat) : WrongAnimal(cat)
{
    *this = cat;
    std::cout << "WrongCat class's copy constructor called!!" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &)
{
    return (*this);
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat makesound() called: Meauu!!" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called!!" << std::endl;
}