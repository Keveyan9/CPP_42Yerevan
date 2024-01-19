#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"
#include <fstream>
#include <iostream>

class Bureaucrat;

class AForm
{
private:
	const std::string _Doc_name;
	bool _sign;
	const short _gradeToSign;
    const short _gradeToExecute;
     short is_valide( short grade) const;
public:
	AForm();
	AForm(const std::string &, const short gradeToSign, const short gradeToExecute);
	AForm &operator=(const AForm &obj);
    AForm(const AForm &obj);
	~AForm();
    void beSigned(const Bureaucrat &Bureaucrat);
	std::string getName() const;
    bool        isSigned() const;
    short getGradeToSign() const;
    short getGradeToExecute() const;
    virtual void  action() const = 0;
    void  execute(Bureaucrat const & executor) const;
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
std::ostream &operator<<(std::ostream &out, const AForm &obj);
#endif