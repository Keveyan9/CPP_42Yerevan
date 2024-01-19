#include "AMateria.hpp"

class Cure : public AMateria
{
public:
    Cure();
    Cure(const Cure &);
    Cure &operator=(Cure const &);
    void use(ICharacter &);
    AMateria *clone() const;
    ~Cure();
};