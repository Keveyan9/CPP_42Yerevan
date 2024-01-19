#include "Bureaucrat.hpp"

 short Form::is_valide(short grade) const
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

Form::Form():_Doc_name("defolt"),_sign(0),_gradeToSign(2),_gradeToExecute(2)
{
	std::cout << YELLOW << "defolt from creat\n" << RESET;
}

Form::Form(const std::string &name, const short gradeToSign, const short gradeToExecute):_Doc_name(name), _sign(0),_gradeToSign(is_valide(gradeToSign)),_gradeToExecute(is_valide(gradeToExecute))
{
	std::cout << YELLOW<< "form_"<< name << "creat\n"<< RESET;
}

Form::Form(const Form &obj) :_Doc_name(obj._Doc_name),
	_sign(obj._sign),_gradeToSign(obj._gradeToSign),_gradeToExecute(obj._gradeToExecute)
{
	std::cout << BLUE<<"copy constructor form coll name is " <<_Doc_name << std::endl << RESET;
}

Form& Form::operator=(const Form &obj)
{
	this->_sign = obj._sign;
	return(*this);
}

Form::~Form()
{
	std::cout<< RED<< "destroy form "<<_Doc_name<< std::endl << RESET;
}

void Form::beSigned(const Bureaucrat &Bureaucrat) {
	if (_sign == true) {
        throw GradeError("GradeAlreadySigned");
	} if (Bureaucrat.getGrade() <= _gradeToSign) {
		_sign = true;
	} else {
        throw GradeError("GradeTooLowException");
	}
};

std::string Form::getName()const
{
	return(_Doc_name);
}

bool        Form::isSigned() const {
	return (_sign);
};

short Form::getGradeToSign() const {
	return (_gradeToSign);
};

short Form::getGradeToExecute() const {
	return (_gradeToExecute);
};


Form::GradeError::GradeError(const std::string &message)
{
	_message = message;
	std::cout << YELLOW << "gradeError create\n"<< RESET;
}

const char* Form::GradeError::what() const throw()
{
	return(_message.c_str());
}
void  Form::GradeError::setMessage( const std::string  &message)
{
	_message = message;
}

Form::GradeError::~GradeError() throw()
{
	std::cout << RED << "gradeError destruct\n"<< RESET;
}

std::ostream &operator<<(std::ostream &out, const Form &obj) {
	std::cout << obj.getName() << ", Form grade to sign "
		<< obj.getGradeToSign() << ", grade to execute "
		<< obj.getGradeToExecute();
		obj.isSigned() == false ? std::cout << ", is not signed " << "." :
		std::cout << ", is signed" << std::endl;
	return (out);
};