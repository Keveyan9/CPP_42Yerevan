#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm(const std::string &name);
        RobotomyRequestForm(const RobotomyRequestForm &obj);
        virtual ~RobotomyRequestForm();
        RobotomyRequestForm &operator=(const RobotomyRequestForm &obj);
        void action() const;
    private:
        std::string _name;
};