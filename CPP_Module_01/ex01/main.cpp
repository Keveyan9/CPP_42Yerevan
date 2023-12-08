#include "Zombie.hpp"

int main ()
{
    int pce;

    pce = 5;
	Zombie *z;

	 z = zombieHorde(pce, "testIsZombie");
    for (int i = 0; i < pce; i++)
        z[i].printzombi();
    delete[] z;
    while (1);
    
    
    return (0);
	
}