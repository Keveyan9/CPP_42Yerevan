#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string _name;
    public:
        PresidentialPardonForm(const std::string &name);
        PresidentialPardonForm(const PresidentialPardonForm &obj);
        virtual ~PresidentialPardonForm();
        PresidentialPardonForm &operator=(const PresidentialPardonForm &obj);
        void action() const;
};