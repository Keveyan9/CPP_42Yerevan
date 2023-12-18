#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include"colors.hpp"

class ScavTrap: public ClapTrap
{
private:
	std::string		_name;
	unsigned int	_healthPoint;
	unsigned int	_energyPoint;
	unsigned int	_attackDemage;
public:

	ScavTrap();
	ScavTrap(ScavTrap &);
	ScavTrap(const std::string &);
	ScavTrap& operator=(const ScavTrap &);
    void attack(const std::string& target);
	void highFivesGuys(void);
	~ScavTrap();
};
#endif
