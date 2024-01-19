#include "Bureaucrat.hpp"

int main ()
{
	try
    {
        
        Bureaucrat a("test", 15);
        a.increment();
        std::cout << a.getGrade() << std::endl;
    }
    catch(std::exception &test)
    {
        std::cout << BLUE << test.what() << RESET <<std::endl;
    }


}