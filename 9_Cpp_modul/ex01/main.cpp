#include "main.hpp"
#include "RPN.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) 
	{
        std::cerr << "Usage: " << argv[0] << " \"RPN expression\"" << std::endl;
        return 1;
    }
    
    try 
	{
        int result ;

		result = 0;
		RPN::evaluate_RPN(argv[1],result);
        std::cout << result << std::endl;
    }
	catch (const std::exception& e)
	{
       std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
//	1 2 -blablabla + error
//	1 2blablabla - + error
//	" 1" "1 " space before and after month/day instead of "0" number
