//#pragma once
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "colors.hpp"
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	std::string _name;
	int _grade;
public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(std::string name);
	std::string getName() const;
	int getGrade()const;
	Bureaucrat& operator=(const Bureaucrat &targed);
	void increment();
	void dicrement();
	void signForm(AForm &Aform);
	void executeForm(AForm const & form); // TODO
	~Bureaucrat() throw() ;
private:
	class GradeError : public std ::exception
	{
		private:
			std::string _message;
		public:
			GradeError(const std::string &message) throw();
			virtual const char* what() const throw();
			void setMessage(const std::string &message);
			~GradeError() throw();
	};
};
std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj);
#endif 