
#include "Intern.hpp"

// int	main(void)
// {
// 	{
// 		Intern someRandomIntern;
// 		AForm *rrf;
// 		rrf = someRandomIntern.makeForm( "robotomy request", "Bender");
// 		delete rrf;
// 		rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
// 		delete rrf;
// 		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
// 		delete rrf;
// 		rrf = someRandomIntern.makeForm("prsidential pardon", "Bender");
// 		delete rrf;
// 	}
// 	return (0);
// }

int	main()
{
	Bureaucrat	*bur;
	AForm		*form;
	Intern		intern;

	std::cout << MAGENTA<< "---------------------------------------------------------------------" << std::endl;
	form = intern.makeForm("robotomy request", "Bender");
	std::cout << MAGENTA<< "---------------------------------------------------------------------" << std::endl;
	try
	{
		bur = new Bureaucrat("Bob", 24);
		std::cout << *bur << std::endl;
		std::cout << *form << std::endl;
		std::cout << MAGENTA<< "---------------------------------------------------------------------" << std::endl;
		if (bur->getGrade() <= form->getGradeToExecute())
        	bur->signForm(*form);
		else
		{
			while (bur->getGrade() > form->getGradeToSign())
				bur->increment();
			bur->signForm(*form);
		}
		if (bur->getGrade() <= form->getGradeToExecute())
        	bur->executeForm(*form);
		else
		{
			while (bur->getGrade() > form->getGradeToSign())
				bur->increment();
			bur->executeForm(*form);
		}
		std::cout << MAGENTA<< "---------------------------------------------------------------------" << std::endl;
		std::cout << *bur << std::endl;
		std::cout << *form << std::endl;
		std::cout << MAGENTA<< "---------------------------------------------------------------------" << std::endl;
		delete bur;
	}
	catch(const std::exception &e)
	{
		std::cout << GREEN << "❗️EXCEPTION❗️ " << RED << e.what() << std::endl;
	}
	delete form;
}
