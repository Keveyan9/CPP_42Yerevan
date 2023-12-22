#ifndef WrongCat_HPP
# define WrongCat_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
    WrongCat();
    WrongCat(const WrongCat &cat);
    WrongCat &operator=(const WrongCat &c);
    void makeSound() const;
    ~WrongCat();
};

#endif