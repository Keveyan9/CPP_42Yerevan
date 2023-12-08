#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *dynamic_Zombe;

	dynamic_Zombe = new Zombie[N];
	for(int i = 0;i < N ;i++)
		dynamic_Zombe[i].send_name(name);
	return(dynamic_Zombe);
}
