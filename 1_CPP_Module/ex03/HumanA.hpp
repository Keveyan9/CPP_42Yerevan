#ifndef HUMANA_HPP
# define HUMANA_HPP

#include"main.hpp"

class HumanA
{
private:
	std::string _name;
	Weapon &_weapon;
public:
	HumanA(const std::string& name, Weapon& weapon);
	~HumanA();
    void    attack(); 
};
#endif