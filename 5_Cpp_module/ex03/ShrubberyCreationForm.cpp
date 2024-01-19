#include "ShrubberyCreationForm.hpp"
#include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm(const std::string &name): AForm("Shrubbery", 145, 137)
{
	std::cout << BLUE<<"make constructor  ShrubberyCreation form coll name is " <<_name << std::endl << RESET;
	_name = name;

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj):AForm(obj)
{
	std::cout << BLUE<<"copy constructor  ShrubberyCreation form coll name is " <<_name << std::endl << RESET;
	this->_name = obj._name;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << RED << "ShrubberyCreationForm destruct\n"<< RESET;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
	AForm::operator=(obj);
	this->_name = obj._name;
	return(*this);
}

void ShrubberyCreationForm::action() const {

	const std::string filname= _name + "_shrubbery";
	 std::ofstream ofs(filname.c_str() , std::ofstream::out);
    std::string str = "Hi";
    if (ofs.is_open()) {
        ofs << "          *          " << std::endl;
        ofs << "         * *         " << std::endl;
        ofs << "        *   *        " << std::endl;
        ofs << "       *     *       " << std::endl;
        ofs << "      *       *      " << std::endl;
        ofs << "     *         *     " << std::endl;
        ofs << "    *************    " << std::endl;
        ofs << "         ***         " << std::endl;
        ofs << "         ***         " << std::endl;
        ofs << "     __________      " << std::endl;
        ofs << "                     " << std::endl;
        if (ofs.good() == false) {
            std::cerr << "something went wrong" << std::endl;
        }
        ofs.close();
    } else {
        std::cerr << "Error opening file" << std::endl;
    }
	std::cout << RED << "Action test \n"<< RESET;
};