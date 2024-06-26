#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

class Harl
{
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
		void nonofthem(void);
	public:
		Harl();
		~Harl();
		void complain(std::string level);
};

#endif
