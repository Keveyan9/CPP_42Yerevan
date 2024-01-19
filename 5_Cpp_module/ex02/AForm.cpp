#include "AForm.hpp"

 short AForm::is_valide(short grade) const
{
	if (grade > 150)
	{
		throw GradeError("GradeTooLowException");
	}
	if (grade < 1) 
	{
		throw GradeError("GradeTooHighException");
	}
	return (grade);
}

AForm::AForm():_Doc_name("defolt"),_sign(0),_gradeToSign(2),_gradeToExecute(2)
{
	std::cout << YELLOW << "defolt from creat\n" << RESET;
}

AForm::AForm(const std::string &name, const short gradeToSign, const short gradeToExecute):_Doc_name(name), _sign(0),_gradeToSign(is_valide(gradeToSign)),_gradeToExecute(is_valide(gradeToExecute))
{
	std::cout << YELLOW<< "form_"<< name << "creat\n"<< RESET;
}

AForm::AForm(const AForm &obj) :_Doc_name(obj._Doc_name),
	_sign(obj._sign),_gradeToSign(obj._gradeToSign),_gradeToExecute(obj._gradeToExecute)
{
	std::cout << BLUE<<"copy constructor  Aform form coll name is " <<_Doc_name << std::endl << RESET;
}

AForm& AForm::operator=(const AForm &obj)
{
	this->_sign = obj._sign;
	return(*this);
}

AForm::~AForm()
{
	std::cout<< RED<< "destroy form "<<_Doc_name<< std::endl << RESET;
}

void AForm::beSigned(const Bureaucrat &Bureaucrat) {
	if (_sign == true) {
        throw GradeError("GradeAlreadySigned");
	} if (Bureaucrat.getGrade() <= _gradeToSign) {
		_sign = true;
	} else {
        throw GradeError("GradeTooLowException");
	}
};

std::string AForm::getName()const
{
	return(_Doc_name);
}

bool        AForm::isSigned() const {
	return (_sign);
};

short AForm::getGradeToSign() const {
	return (_gradeToSign);
};

short AForm::getGradeToExecute() const {
	return (_gradeToExecute);
};


AForm::GradeError::GradeError(const std::string &message)
{
	_message = message;
	std::cout << YELLOW << "gradeError create\n"<< RESET;
}

const char* AForm::GradeError::what() const throw()
{
	return(_message.c_str());
}
void  AForm::GradeError::setMessage( const std::string  &message)
{
	_message = message;
}

AForm::GradeError::~GradeError() throw()
{
	std::cout << RED << "gradeError destruct\n"<< RESET;
}

std::ostream &operator<<(std::ostream &out, const AForm &obj) {
	std::cout << obj.getName() << ", AForm grade to sign "
		<< obj.getGradeToSign() << ", grade to execute "
		<< obj.getGradeToExecute();
		obj.isSigned() == false ? std::cout << ", is not signed " << "." :
		std::cout << ", is signed" << std::endl;
	return (out);
};

void AForm::execute(Bureaucrat const & executor) const {
	if (_sign == false) {
		throw GradeError("FormIsNotSignedException");
	} if (executor.getGrade() > _gradeToExecute) {
		throw GradeError("GradeTooLowToExecuteException");
	}
	this->action();
};
