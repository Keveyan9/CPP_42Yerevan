#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string _Doc_name;
	bool _sign;
	const short _gradeToSign;
    const short _gradeToExecute;
     short is_valide( short grade) const;
public:
	Form();
	Form(const std::string &, const short gradeToSign, const short gradeToExecute);
	Form &operator=(const Form &obj);
    Form(const Form &obj);
	~Form();
    void beSigned(const Bureaucrat &Bureaucrat);
	std::string getName() const;
    bool        isSigned() const;
    short getGradeToSign() const;
    short getGradeToExecute() const;
    // void &operator<<();
private:
	class GradeError : public std::exception
        {
            private:
                std::string _message;
            public:
                GradeError(const std::string &message);
                virtual ~GradeError() throw();
                virtual const char* what() const throw();
                virtual void setMessage(const std::string &message);
        };

};
std::ostream &operator<<(std::ostream &out, const Form &obj);
#endif