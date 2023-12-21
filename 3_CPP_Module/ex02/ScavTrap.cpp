
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() 
{
	_name = "defolt";
	_healthPoint = 100;
	_attackDemage = 20;
	_energyPoint = 50;
	std::cout << YELLOW << "ScavTrap default creating cllas" << RESET <<std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	_name = name;
	_healthPoint = 100;
	_attackDemage = 20;
	_energyPoint = 50;
	
	std::cout << GREEN << " ScavTrap creating cllas and  give name" << RESET <<std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap Copy Constructor called" << std::endl;
	this->_gateKeeper = copy._gateKeeper;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &assign)
{
	if(this != &assign )	
	{
		std::cout << "ScavTrap Assignment operator called" << std::endl;
		_name = assign._name;
		_healthPoint = assign._healthPoint;
		_energyPoint = assign._energyPoint;
		_attackDemage = assign._attackDemage;
	}
	return (*this);
}

void ScavTrap::attack(const std::string& target)
{

	if (_energyPoint > 0 && _healthPoint > 0)
	{
		std::cout  << YELLOW << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDemage 
				<< " points of damage!" << RESET << std::endl;
		_energyPoint--;
	}
	else if (_energyPoint == 0)
		std::cout<< RED  << "ClapTrap " << _name << " cannot be attacked, because it does not have hit points left!" 
			<< RESET << std::endl;
	
	else
		std::cout << "ScavTrap " << _name << " cannot be attacked, because it does not have hit points left!" << std::endl;
}

void ScavTrap::guardGate()
{
	if (this->_gateKeeper == false)
	{
		this->_gateKeeper = true;
		std::cout << "ScavTrap " << this->_name << " is now guarding the gate." << std::endl;
	}
	else
		std::cout << "ScavTrap " << this->_name << " is already guarding the gate." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}