#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
    private:
        std::string *ideas;
    public:
        Brain();
        Brain(const Brain &b);
        Brain &operator=(const Brain &b);
        ~Brain();
};

#endif