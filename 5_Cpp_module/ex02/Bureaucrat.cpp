#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(std::string name):_name(name),_grade(1)
{
	std::cout << YELLOW << "create beuracrat deffolt\n" << RESET;
}

Bureaucrat::Bureaucrat(std::string name, int range):_name(name) ,_grade(range)
{
	if(_grade > 150)
		throw GradeError("GradeTooLowException");
	if(_grade < 1)
	   throw GradeError("GradeTooHighException");
	std::cout << YELLOW <<"create beuracrat \n" << RESET;
}

Bureaucrat& Bureaucrat:: operator=(const Bureaucrat &target)
{
	if (this != &target)
	{
		this->_name = target._name;
		this->_grade = target._grade;
	}
		return(*this);
}

std::string Bureaucrat::getName() const
{
	return(_name);
}

int Bureaucrat::getGrade()const 
{
	return (_grade);
}

void Bureaucrat::increment()
{
	if(_grade == 150)
		throw GradeError("GradeTooLowException");
	_grade++;
}
void Bureaucrat::dicrement()
{
	if(_grade == 1 )
		throw GradeError("GradeTooHighException");
	_grade--;
}

Bureaucrat::~Bureaucrat() throw()
{
	std::cout << RED << "beuracrat destroy\n" <<RESET;
}

Bureaucrat::GradeError::GradeError(const std::string &message) throw(): _message(message)
{
	std::cout << YELLOW << "gradeError create\n"<< RESET;
}

const char* Bureaucrat::GradeError::what() const throw()
{
	return(_message.c_str());
}
void  Bureaucrat::GradeError::setMessage( const std::string  &message)
{
	_message = message;
}

Bureaucrat::GradeError::~GradeError() throw()
{
	std::cout << RED << "gradeError destruct\n"<< RESET;
}


void Bureaucrat::signForm(AForm &Aform) 
{
	try
    {
        Aform.beSigned(*this);
        std::cout << this->getName() << " signed " << Aform.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << this->getName() << " couldn’t sign " << Aform.getName()
            << " because " << e.what() << std::endl;
    }
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj) {
    std::cout << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
    return (out);
};


void Bureaucrat::executeForm(AForm const & form) {
    try
    {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << this->getName() << " couldn’t execute " << form.getName()
           << " because of " << e.what() << std::endl;
    }
};
