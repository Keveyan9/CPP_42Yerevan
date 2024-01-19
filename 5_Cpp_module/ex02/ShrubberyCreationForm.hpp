#pragma once
#include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        std::string _name;
    public:
        ShrubberyCreationForm(const std::string &name);
        ShrubberyCreationForm(const ShrubberyCreationForm &obj);
        virtual ~ShrubberyCreationForm();
        
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &obj);
        void action() const;
};