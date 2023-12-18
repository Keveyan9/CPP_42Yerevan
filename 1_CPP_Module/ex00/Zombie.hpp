#ifndef ZOMBIE
# define ZOMBIE

#include <iostream>
#include <string>

class Zombie
{
private:
	std::string _name; 
public:
	Zombie();
	Zombie(const std::string &name);
	void printzombi(void);
	~Zombie();
};

void randomChump( std::string name );
Zombie *newZombie(std::string name);

#endif