#include "main.hpp"

#include "DiamondTrap.hpp"

int main()
{
     ClapTrap f16("f16");
    FragTrap f17("f17");
    DiamondTrap test;
    DiamondTrap su25("su25");
    DiamondTrap test2;
    test = su25;

    su25.attack(f17.getName());
    f17.takeDamage(su25.getAttackDamage());
    su25.printLifeinfo();
    su25.whoAmI();
    return 0;
}
