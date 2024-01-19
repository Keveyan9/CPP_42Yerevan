
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try
    {
        Bureaucrat a("bob", 5);
        Form form("Babken", 15, 20);
        std::cout << form << std::endl;
        a.signForm(form);
        std::cout << form << std::endl;
        a.signForm(form);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}