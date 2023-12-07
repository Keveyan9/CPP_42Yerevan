#include "main.hpp"


PhoneBook::PhoneBook(){}

PhoneBook::~PhoneBook(){}

bool    strIsDigit(std::string &str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (!isdigit(str[i]))
            return (false);
    }
    return (true);
}

void PhoneBook::addContact()
{
	std::string index;
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;
    int         flag = 0;
    std::cout << "Input first name for contact:\n";
    std::cin >> firstName;
     if (std::cin.eof())
       exit(0);
    std::cout << "Input last name for contact:\n";
    std::cin >> lastName;
   if (std::cin.eof())
       exit(0);
    std::cout << "Input nickname for contact:\n";
    std::cin >> nickname;
    if (std::cin.eof())
       exit(0);
    std::cout << "Input phone number for contact:\n";
    std::cin >> phoneNumber;
    if (std::cin.eof())
       exit(0);
    std::cout << "Input darkest secret for contact:\n";
    std::cin >> darkestSecret;
    if (std::cin.eof())
       exit(0);

    if (firstName.empty())
        flag = 1;
    else if (lastName.empty())
        flag = 1;
    else if (nickname.empty())
        flag = 1;
    else if (phoneNumber.empty() || !strIsDigit(phoneNumber))
        flag = 1;
    else if (darkestSecret.empty())
        flag = 1;
    if (flag == 1)
    {
        std::cout << "Some inputs are empty or phone number does not contain only digits for contact\n";
        return;
    }
	else
	{
		if (_list_number == pce)
			_list_number = 0;
			index = std::to_string(_list_number + 1);
		_contact[_list_number] = Contact(index,firstName, lastName, nickname, phoneNumber, darkestSecret);
        if(_busy != pce)
            _busy++;
		_list_number++;
	}
}




void PhoneBook::searchContact()
{
    int        i = 0;
    std::string      s_index;


    int t = 0;
    if(_busy)
    {
        std::cout << std::right << std::setw(10) << "index"
              << "|"
              << std::right << std::setw(10) << "first name"
              << "|"
              << std::right << std::setw(10) << "last name"
              << "|"
              << std::right << std::setw(10) << "nickname"
                << "|" ;
        while (t < _busy )
     {
         _contact[t].printContact();
         t++;
     }

     std::cout << "\nInput index of the contact to display:\n";
     std::cin >> s_index;
    if (std::cin.eof())
       exit(0);
     if(strIsDigit(s_index))
	    	i = std::stoi(s_index);
	    else
	    {
           std::cout << "is not number\n";
	    	return;
    	}
	    if (i >= 1 && i <= _busy && i > 0)
	     _contact[i - 1].printContact(1);
     else if (i > _busy )
         std::cout << "phonbook  contact is empty\n";
        }
         else
             std::cout << "phonbook is empty\n";
}