#include "ClapTrap.hpp"

int main()
{
    ClapTrap f16("f16");
    ClapTrap f17("f17");

    f16.printLifeinfo();
    f17.printLifeinfo();
    f16.attack(f17.getName());
    f16.attack(f17.getName());
    f17.attack(f16.getName());
    f17.attack(f16.getName());
    f17.attack(f16.getName());
    f17.takeDamage(f16.getAttackDamage());
    f17.takeDamage(f16.getAttackDamage());
    f17.printLifeinfo();
    f17.beRepaired(1);
    f16.printLifeinfo();
    f17.printLifeinfo();
    return 0;
}
