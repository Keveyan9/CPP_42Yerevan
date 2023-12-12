#ifndef HUMANB_HPP
# define HUMANB_HPP

#include"main.hpp"

class HumanB
{
private:
	std::string _name;
	Weapon *_weapon;
public:
	HumanB(const std::string& name);
	HumanB();
	~HumanB();
    void	attack();
	void setWeapon(Weapon &weapon);

};
#endif