#include "Fixed.hpp"

Fixed& Fixed::operator=(const Fixed &other)
{
    std::cout << YELLOW << "Assignation operator called"<< RESET << std::endl;
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

Fixed::Fixed(const int x) : _valu ( x * pow(2, _bit))
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float x) : _valu(roundf((x * pow(2, _bit))))
{
    std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
    return ((float)_valu / (float)pow(2, _bit));
}

int Fixed::toInt(void) const
{
    return (_valu / pow(2, _bit));
}

std::ostream& operator<<(std::ostream &os, const Fixed &obj)
{
    os << obj.toFloat();
    return (os);
}

Fixed::~Fixed()
{
	std::cout << RED << "Destructor called" <<RESET << std::endl;
}