#ifndef CLABTRAP_HPP
# define CLABTRAP_HPP

#include <iostream>
#include <stdbool.h>
#include"colors.hpp"

class ClapTrap
{
protected:
	std::string		_name;
	unsigned int	_healthPoint;
	unsigned int	_energyPoint;
	unsigned int	_attackDemage;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &);
	ClapTrap& operator=(const ClapTrap &);

	const std::string &getName() const;
	void printLifeinfo();
	const unsigned int &getAttackDamage() const;
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	~ClapTrap();
};

#endif