#include "Bureaucrat.hpp"

int main ()
{
	try
    {
        
        Bureaucrat a("test", 1);
        a.dicrement();
        std::cout << a.getGrade() << std::endl;
    }
    catch(std::exception &test)
    {
        std::cout << BLUE << test.what() << RESET <<std::endl;
    }


}