#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "Amateria class's default constructor called!!" << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type) {}

str ::string const &AMateria::getType() const
	return(_type);


AMateria AMateria::&operator=(const AMateria &argument)
{
	this->_type = argument._type;
	return(this);
}

void AMateria::use(ICharacter &target)
{
    std::cout << "AMateria is used by " << target.getName() << std::endl;
}

AMateria::AMateria(const AMateria &copy)
{
	 this->_type = copy._type;
}

AMateria::~AMateria()
{
	std::cout << "Destructor is called" << std::endl;
};