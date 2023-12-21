#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap ,public FragTrap
{
private:
	std::string _clap_name;
public:
	DiamondTrap();
	DiamondTrap(const std::string &name);
    DiamondTrap(const DiamondTrap &copy);
    DiamondTrap &operator=(const DiamondTrap &assign);
	using ScavTrap::attack;
	using FragTrap::_healthPoint;
	using ScavTrap::_energyPoint;
	using FragTrap::_attackDemage;
	void whoAmI();
	~DiamondTrap();
};



#endif