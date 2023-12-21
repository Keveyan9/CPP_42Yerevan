#include "ClapTrap.hpp"
#include"ScavTrap.hpp"


    
int main()
{
    ClapTrap f16("f16");
    ClapTrap f17("f17");
    ScavTrap su25;

    f17.attack(f16.getName());
    f16.takeDamage(su25.getAttackDamage());
    su25.printLifeinfo();
    su25.getName();
    su25.guardGate();

    
    return 0;
}
