#include "Brain.hpp"

Brain::Brain()
{
    this->ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "MY brain";
    std::cout << "Brain default constructor called!!" << std::endl;
}

Brain::Brain(const Brain &b)
{
    std::cout << "Brain copy constructor called!!" << std::endl;
    this->ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		this->ideas[i] = b.ideas[i];
}

Brain &Brain::operator=(const Brain &assign)
{
    if(this == &assign)
    {
        return (*this);
    }
	for(int i = 0; i < 100; i++)
		this->ideas[i] = assign.ideas[i];
	return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain destructor called!!" << std::endl;
    delete [] ideas;
}