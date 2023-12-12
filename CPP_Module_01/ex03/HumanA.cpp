#include"main.hpp"

HumanA::~HumanA(){}

HumanA::HumanA(const std::string& name, Weapon &weapon):_name(name),_weapon(weapon)
{
	// _name = name;
	// _weapon = weapon;
}

void  HumanA::attack()
{
    std::cout << _name << " attacks with his " << _weapon.getType() << "\n";
}
