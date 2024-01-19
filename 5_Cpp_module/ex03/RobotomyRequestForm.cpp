#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string &name) : AForm("RobotomyRequest", 72, 45) {
    _name = name;
};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm(obj) {
    _name = obj._name;
};

RobotomyRequestForm::~RobotomyRequestForm() {};

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj) {
    if (this != &obj) {
        AForm::operator=(obj);
        _name = obj._name;
    }
    return (*this);
};

void RobotomyRequestForm::action() const 
{

    std::cout << "Dzzzzzzzzzzzz" << std::endl;
    std::srand(time(NULL));
    int randNum = std::rand() % 2;
    switch(randNum) {
        case 0 :
            std::cout << _name << " has been robotomized successfully 50% of the time" << std::endl;
            break ;
        default:
            std::cout << _name << "'s robotomy failed" << std::endl;
    }
};