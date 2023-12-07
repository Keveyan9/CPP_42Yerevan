#include "main.hpp"

int main()
{
	PhoneBook phoneBook ;
		std::string s;
	while (1)
	{
		std::cout << "\nEnter one of three commands:  ADD, SEARCH and EXIT\n";
		std ::cin >> s;
		 if (std::cin.eof())
        	break ;
		if (s.compare("ADD") == 0)
		{
			phoneBook.addContact();

		}
		else if (s.compare("SEARCH") == 0)
		{
			phoneBook.searchContact();			
		}
		else if (s.compare("EXIT") == 0)
		{
			exit(0);
		}
	}
}
