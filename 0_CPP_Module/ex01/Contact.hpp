#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact
{
	private:
		std::string _index;
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;
	public:
		Contact();
		Contact(const std::string &,const std::string &, const std::string &, const std::string &, const std::string &, const std::string &);
		~Contact();
		void printContact(bool flag);
		void printContact();
};
#endif