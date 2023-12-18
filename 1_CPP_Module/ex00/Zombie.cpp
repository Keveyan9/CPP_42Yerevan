#include "Zombie.hpp"

Zombie::Zombie() 
{
    std::cout << "Default constructor is called\n";
}

Zombie::Zombie( const std::string &name)
{
    _name = name;
	std::cout << "Zombie object " << _name << " created\n";
}

void Zombie::printzombi()
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}


Zombie::~Zombie()
{
    std::cout << _name << " is destroyed\n";
}