#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap() 
{
	_healthPoint = 100;
	_attackDemage = 30;
	_energyPoint = 100;
	std::cout << YELLOW << "FragTrap default creating cllas" << RESET <<std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "FragTrap Parametrized Constructor called" << std::endl;
	_healthPoint = 100;
	_attackDemage = 30;
	_energyPoint = 100;
}


FragTrap::FragTrap(const FragTrap &copy):ClapTrap(copy)
{
	std::cout << "FragTrap Copy Constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &assign)
{
	if (this != &assign)
	{
		std::cout << "FragTrap Assignment operator called" << std::endl;
		_name = assign._name;
		_healthPoint = assign._healthPoint;
		_energyPoint = assign._energyPoint;
		_attackDemage = assign._attackDemage;
	}
	return (*this);
}

void FragTrap::highFivesGuys()
{
	std::cout << "I am kidding you, give high five!!" << std::endl;
}

FragTrap::~FragTrap()
{
 	std::cout << "FragTrap Destructor called" << std::endl;
}