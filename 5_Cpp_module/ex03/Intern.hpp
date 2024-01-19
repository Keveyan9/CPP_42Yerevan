#pragma once
#include "AForm.hpp"

class Intern
{
    private:
        AForm *makeRobotomyRequestForm(const std::string &target);
        AForm *makePresidentialPardonForm(const std::string &target);
        AForm *makeShrubberyCreationForm(const std::string &target);
    public:
        Intern();
        Intern(const Intern &obj);
        ~Intern();
        Intern &operator=(const Intern &obj);
        AForm *makeForm(const std::string &nameForm, const std::string &target);
};