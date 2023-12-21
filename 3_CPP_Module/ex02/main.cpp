#include "main.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include " FragTrap.hpp"

int main()
{
    ClapTrap f16("f16");
    ClapTrap f17("f17");
    FragTrap su25;

    su25.attack(f16.getName());
    f16.takeDamage(su25.getAttackDamage());
    // su25.printLifeinfo();
    // su25.highFivesGuys();
    return 0;
}
