#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal
{
private :
    Brain *_b;
public:
    Dog();
    Dog(const Dog &);
    Dog &operator=(const Dog &a);
    virtual void makeSound() const;//override;
    ~Dog();
};

#endif