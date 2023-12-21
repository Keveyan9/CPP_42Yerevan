#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("defolt"),_healthPoint(10),_energyPoint(10),_attackDemage(0)
{
	std::cout << YELLOW << " ClapTrap default creating cllas" << RESET <<std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name),_healthPoint(10),_energyPoint(10),_attackDemage(0)
{
	std::cout << GREEN << " creating ClapTrap  named instance " << RESET <<std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "ClapTrap Copy Constructor called" << std::endl;
	*this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &assign)
{
	std::cout << "ClapTrap Assignment operator called" << std::endl;
	_name = assign._name;
	_healthPoint = assign._healthPoint;
	_energyPoint = assign._energyPoint;
	_attackDemage = assign._attackDemage;
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (_energyPoint > 0 && _healthPoint > 0)
	{
		std::cout  << YELLOW << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDemage 
				<< " points of damage!" << RESET << std::endl;
		_energyPoint--;
	}
	else if (_healthPoint == 0)
		std::cout<< RED  << "ClapTrap " << _name << " cannot be attacked, because it does not have hit points left!" 
			<< RESET << std::endl;
	else if (_energyPoint == 0)
		std::cout << RED << "ClapTrap " << _name << " cannot be attacked, because it does not have energy points left!" <<
		 RESET << std::endl;
}

const std::string &ClapTrap::getName() const
{
	return (_name);
}

void ClapTrap::printLifeinfo()
{
	std::cout << this->_name << "'s hit points are " << this->_healthPoint << std::endl;
	std::cout << this->_name << "'s energy points are " << this->_energyPoint << std::endl;
}

const unsigned int &ClapTrap::getAttackDamage() const
{
	return(_attackDemage);
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (_healthPoint > amount) 
	{
		std::cout << "ClapTrap " << _name << " was attacked and lost " << _attackDemage << " points!" << std::endl;
		_healthPoint -= amount;
	}
	else if (_healthPoint == 0)
	{
		std::cout<< RED << "ClapTrap " << _name << " is already dead, stop it!!!" << RESET<<std::endl;
	}
	else
	{
		std::cout << RED<< "ClapTrap " << _name << " has died, stop it!!!" << RESET<<std::endl;
	}
}


void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoint > 0 && _healthPoint > 0)
	{
		std::cout << "ClapTrap " << _name << " is being repaired and getting " << amount << " points back!" << std::endl;
		_healthPoint += amount;
		_energyPoint--;
	}
	else if (_healthPoint == 0)
		std::cout << "ClapTrap " << _name << " cannot be attacked, because it does not have hit points left!" << std::endl;
	else
		std::cout << "ClapTrap " << _name << " cannot be repaired, because it does not have energy points left!" << std::endl;
}


ClapTrap::~ClapTrap()
{

	std::cout << RED << "destroy cllas" << RESET<< std::endl;
}