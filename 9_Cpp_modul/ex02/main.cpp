#include"PmergeMe.hpp"
#include "main.hpp"

int main(int argc, char **argv) 
{
	
	try
	{
		if (argc <= 3)
			throw std::runtime_error("it is litel input");
		
	
	}
	catch(const std::exception& error_messege)
	{
		std::cout << error_messege.what() << std::endl;
	}

	return(0);
}

