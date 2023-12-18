#ifndef FIXED_HPP
#define FIXED_HPP

#include"iostream"

class Fixed
{
private:
	int _valu;
	static const int bit = 8;
public:
	Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	~Fixed();
};

#endif