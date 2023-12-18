#include "main.hpp"

Contact::Contact(){}
Contact::~Contact(){}

Contact::Contact(const std::string &i,const std::string &f, const std::string &l, const std::string &n, const std::string &p, const std::string &d)
  
    :_index(i), _firstName(f), _lastName(l), _nickname(n), _phoneNumber(p), _darkestSecret(d)
{}
void printColumn(std::string &str )
{
    std::string copy;
    if (str.length() <= 10)
        std::cout << std::right << std::setw(10) << str << "|";
    else
    {
       copy = str.substr(0, 9) + ".";
         std::cout << std::right << std::setw(10) << copy << "|";
    }
}

void Contact::printContact()
{
    std::cout << "\n";
    printColumn(_index);
    printColumn(_firstName);
    printColumn(_lastName);
    printColumn(_nickname);

}

int length_need (std::string name, std::string word)
{
    return(name.length() + word.length());
}

void Contact::printContact(bool flag)
{
    (void) flag;
    std::cout << "\n";
    std::cout << std::right << std::setw(10) << "index"
              << "|"
              << std::right << std::setw(length_need(_firstName,"first name")) << "first name"
              << "|"
              << std::right << std::setw(length_need(_lastName,"lastName")) << "last name"
              << "|"
              << std::right << std::setw(length_need(_nickname,"nickname")) << "nickname"
             << "|"
            << std::right << std::setw(length_need(_phoneNumber,"phoneNumber")) << "phone number" 
            << "|"
                 << std::right << std::setw(length_need(_darkestSecret,"darkestSecret")) << "darkest secret\n";

    std::cout << std::right << std::setw(10) << _index
              << "|"
              << std::right << std::setw(length_need(_firstName,"first name")) << _firstName
              << "|"
              << std::right << std::setw(length_need(_lastName,"lastName")) << _lastName
               << "|"
              << std::right << std::setw(length_need(_nickname,"nickname")) << _nickname
             << "|"
            << std::right << std::setw(length_need(_phoneNumber,"phoneNumber")) << _phoneNumber
            << "|"
                 << std::right << std::setw(length_need(_darkestSecret,"darkestSecret")) << _darkestSecret  << "\n";
}

