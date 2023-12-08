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
	void send_name(std::string naming);
	void printzombi(void);
	~Zombie();
};
Zombie* zombieHorde( int N, std::string name );
#endif