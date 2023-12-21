#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap 
{
protected:
	 bool _gateKeeper;
public:

	ScavTrap();
	ScavTrap(const std::string &);
	ScavTrap(const ScavTrap &);
	ScavTrap& operator=(const ScavTrap &);
    void attack(const std::string& target);
	void guardGate();
	~ScavTrap();
};
#endif
