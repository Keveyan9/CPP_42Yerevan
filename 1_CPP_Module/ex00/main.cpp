#include "Zombie.hpp"

	int main()
{
    Zombie  *z;

    z = newZombie("first");
    z->printzombi();
    randomChump("secօnd");
    delete z;
    return (0);
}
