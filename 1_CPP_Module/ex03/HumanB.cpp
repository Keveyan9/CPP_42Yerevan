#include"main.hpp"

HumanB::HumanB(){}
HumanB::~HumanB(){}

HumanB::HumanB(const std::string& name)
{
	_name = name;
}

void  HumanB::attack()
{
	
    std::cout << _name << " attacks with his " << _weapon->getType() << "\n";
}

void  HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}