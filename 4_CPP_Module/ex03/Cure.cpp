#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure &copy) : AMateria(copy._type) {}

Cure &Cure::operator=(const Cure &assign)
{
	(void)assign;
    return (*this);
}

void Cure::use(ICharacter &obj)
{
	std::cout << "* heals " << obj.getName() << " wounds *" << std::endl;
}

AMateria *Cure::clone() const
{
	return (new Cure());
}

Cure::~Cure() {}