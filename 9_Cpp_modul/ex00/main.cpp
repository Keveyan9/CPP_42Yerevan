
#include "BitcoinExchange.hpp"
#include "main.hpp"

int main(int argc, char **argv) 
{
	
	try
	{
		if (argc != 2)
			throw std::runtime_error("it is bad input");
		BitcoinExchange change("data.csv",argv[1]);
		change.relise();
	
	}
	catch(const std::exception& error_messege)
	{
		std::cout << error_messege.what() << std::endl;
	}

	return(0);
}

