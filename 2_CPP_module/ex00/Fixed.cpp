#include "Fixed.hpp"

Fixed& Fixed::operator=(const Fixed &other)
{
    std::cout << "Assignation operator called\n";
    if (this == &other)
        return (*this);
    this->_valu = other._valu;
    return (*this);
}

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
    _valu = 0;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called\n";
    return (_valu);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called\n";
    _valu = raw;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called\n";
 *this = other;
}


Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}