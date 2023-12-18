#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include "colors.hpp"
#include<cmath>

class Fixed
{
private:
	int _valu;
	static const int _bit = 8;
public:
	Fixed();
	Fixed(const Fixed &other);
	Fixed(const int x);
    Fixed(const float x);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
	Fixed &operator=(const Fixed &other);
	~Fixed();
};
std::ostream &operator<<(std::ostream &o, const Fixed &obj);

#endif