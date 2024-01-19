#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice &copy) : AMateria(copy._type) {}

Ice &Ice::operator=(const Ice &assign)
{
    (void)assign;
    AMateria::operator=(assign);
    return (*this);
}

void Ice::use(ICharacter &obj)
{
    std::cout << "* shoots an ice bolt at " << obj.getName() << " *" << std::endl;
}

AMateria *Ice::clone() const
{
	return (new Ice());
}

Ice::~Ice() {}