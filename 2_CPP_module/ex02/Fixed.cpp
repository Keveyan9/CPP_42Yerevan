#include "Fixed.hpp"

Fixed::Fixed():_valu(0)
{
}

Fixed::Fixed(const int x)
{
    _valu = x << this->_bit;
}

Fixed::Fixed(const float x):_valu(roundf((x * (1 << this->_bit))))
{
}

Fixed::Fixed(const Fixed &other):_valu(other._valu)
{
}

int Fixed::getRawBits(void) const
{
    return (_valu);
}

void Fixed::setRawBits(int const raw)
{
    _valu = raw;
}

float Fixed::toFloat(void) const
{
    return ((float)_valu / (float)(1 << this->_bit));
}

int Fixed::toInt(void) const
{
    return (_valu / pow(2, _bit));
}

bool Fixed::operator<(const Fixed &obj) const
{
    return (_valu < obj._valu);
}

bool Fixed::operator>(const Fixed &obj) const
{
    return (_valu > obj._valu);
}

bool Fixed::operator<=(const Fixed &obj) const
{
    return (_valu < obj._valu);
}

bool Fixed::operator>=(const Fixed &obj) const
{
    return (_valu > obj._valu);
}

bool Fixed::operator==(const Fixed &obj) const
{
    return (_valu == obj._valu);
}

bool Fixed::operator!=(const Fixed &obj) const
{
    return (_valu != obj._valu);
}

std::ostream &operator<<(std::ostream &os, const Fixed &obj)
{
    os << obj.toFloat();
    return (os);
}

float Fixed::operator+(const Fixed &obj) const
{
    return (_valu + obj._valu);
}

float Fixed::operator-(const Fixed &obj) const
{
    return (_valu - obj._valu);
}

float Fixed::operator*(const Fixed &obj) const
{
    return (toFloat() * obj.toFloat());
}

float Fixed::operator/(const Fixed &obj) const
{
    return (toFloat() / obj.toFloat());
}

Fixed &Fixed::operator++()
{
    _valu += 1;
    return (*this);
}

Fixed Fixed::operator++(int x)
{
    (void) x;
    Fixed tmp = *this;

    _valu += 1;
    return (tmp);
}

Fixed &Fixed::operator--()
{
    _valu -= 1;
    return (*this);
}

Fixed Fixed::operator--(int x)
{
    (void) x;
    Fixed tmp = *this;

    _valu -= 1;
    return (tmp);
}

Fixed &Fixed::min(Fixed &nmb1, Fixed &nmb2)
{
    if (nmb1._valu < nmb2._valu)
        return (nmb1);
    return (nmb2);
}

const Fixed &Fixed::min(const Fixed &nmb1, const Fixed &nmb2)
{
    if (nmb1._valu < nmb2._valu)
        return (nmb1);
    return (nmb2);
}

Fixed &Fixed::max(Fixed &nmb1, Fixed &nmb2)
{
    if (nmb1.toFloat() > nmb2.toFloat())
        return (nmb1);
    return (nmb2);
}

const Fixed &Fixed::max(const Fixed &nmb1, const Fixed &nmb2)
{
    if (nmb1.toFloat() > nmb2.toFloat())
        return (nmb1);
    return (nmb2);
}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this == &other)
        return (*this);
    this->_valu = other._valu;
    return (*this);
}

Fixed::~Fixed()
{
	std::cout << RED << "Destructor called" << RESET << std::endl;
}