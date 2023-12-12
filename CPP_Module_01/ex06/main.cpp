#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl H;

    if (ac == 2 && av[1])
    {
       H.complain(av[1]);
    }
    else
        std::cerr << "Enter one of the arguments DEBUG, INFO, WARNING, ERROR\n";
}
