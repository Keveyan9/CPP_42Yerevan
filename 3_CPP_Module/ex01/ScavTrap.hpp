#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include"colors.hpp"

class ScavTrap: ClapTrap
{
protected:
	 bool _gateKeeper;
public:

	ScavTrap();
	ScavTrap(ScavTrap &);
	ScavTrap(const std::string &);
	//ScavTrap& operator=(const ScavTrap &);
    void attack(const std::string& target);
	void highFivesGuys(void);
	~ScavTrap();
};
#endif
