#ifndef WEAPON_HPP
#define WEAPON_HPP

#include "main.hpp"

class Weapon
{
private:
	std::string _type;
public:
	Weapon();
	~Weapon();
	Weapon(const std::string &str);
	std::string getType() const;
	void    setType(const std::string& str);
};

#endif