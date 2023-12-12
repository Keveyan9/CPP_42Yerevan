
#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void    Harl::debug(void)
{
    std::cout << "I love to get extra cake (debug)\n";
}

void    Harl::info(void)
{
    std::cout << "You dont put extra cake, you are done!!! (info)\n";
}

void    Harl::warning(void)
{
    std::cout << "I think I deserve to have extra cake for free, give it to me!! (warning)\n";
}

void    Harl::error(void)
{
    std::cout << "I want to speak to the manager now (error)\n";
}

void    Harl::nonofthem(void)
{
    std::cout << "WRONG LEVEL!!!!\n";
}

void Harl::complain(std::string level)
{
    int i;

    i = 0;
   void (Harl::*function[5])() ={
    &Harl::nonofthem,
    &Harl::debug,
    &Harl::warning,
    &Harl::info,
    &Harl::error};

    i = (level == "DEBUG") * 1 + (level == "ERROR") * 4 + (level == "WARNING")* 2 + (level == "INFO") * 3;
	(this->*(function[i]))();

}