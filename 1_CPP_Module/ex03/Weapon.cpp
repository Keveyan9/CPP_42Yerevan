#include"main.hpp"

Weapon::Weapon(){};

Weapon::Weapon(const std::string &str):_type(str){
	// _type = str;
}


std::string Weapon::getType() const
{
    return (_type);
}

void    Weapon::setType(const std::string& str){
    _type = str;
}
Weapon::~Weapon(){}

