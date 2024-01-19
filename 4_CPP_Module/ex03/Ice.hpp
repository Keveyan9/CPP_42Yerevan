#include "AMateria.hpp"

class Ice : public AMateria
{
public:
    Ice();
    Ice(const Ice &src);
    Ice &operator=(Ice const &src);
    AMateria *clone() const;
    void use(ICharacter &);
    ~Ice();
};