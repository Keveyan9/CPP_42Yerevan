 #include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	_name = "defolt";
	_healthPoint = 100;
	_attackDemage = 20;
	_energyPoint = 50;
	
	std::cout << YELLOW << "default creating cllas" << RESET <<std::endl;
}

ScavTrap::ScavTrap(std::string name): _name(name),_healthPoint(10),_energyPoint(10),_attackDemage(0)
{
	std::cout << GREEN << " creating cllas and  have name" << RESET <<std::endl;
}

ScavTrap::ScavTrap (const ScavTrap &copy)
{
	std::cout << "ClapTrap Copy Constructor called" << std::endl;
	*this = copy;
}

ScavTrap &ScavTrap::operator=(const ClapTrap &assign)
{
	std::cout << "ClapTrap Assignment operator called" << std::endl;
	_name = assign._name;
	_healthPoint = assign._healthPoint;
	_energyPoint = assign._energyPoint;
	_attackDemage = assign._attackDemage;
	return (*this);
}
