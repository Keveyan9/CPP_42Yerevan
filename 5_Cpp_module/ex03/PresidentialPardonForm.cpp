#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &name) : AForm("PresidentialPardon", 25, 5)
{
  _name = name;
  std::cout << BLUE<<"make constructor PresidentialPardonForm form coll name is " <<_name << std::endl << RESET;
};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : AForm(obj) {
    _name = obj._name;
    std::cout << BLUE<<"copy constructor PresidentialPardonForm form coll name is " <<_name << std::endl << RESET;
};

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << RED << "PresidentialPardonForm destruct<"<< _name << "\n" << RESET;
};

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj) {
    if (this != &obj) {
        AForm::operator=(obj);
       _name= obj._name;
    }
    return (*this);
};

void PresidentialPardonForm::action() const {
    std::cout << _name << " has been pardoned by Zaphod Beeblebrox" << std::endl;
};