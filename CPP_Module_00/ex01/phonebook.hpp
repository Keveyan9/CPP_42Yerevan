#include "main.hpp"

#ifndef PHONEBOOK_HPP

# define PHONEBOOK_HPP

#define pce 8 

class PhoneBook
{

	private:
		Contact _contact[pce];
		int		_list_number;
		int		_busy;
	public:
		PhoneBook();
		~PhoneBook();
		void addContact();
		void searchContact();
};

#endif