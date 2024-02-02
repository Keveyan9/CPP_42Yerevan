#include "main.hpp"

void my_trim(std::string &obj)
{
	size_t first = obj.find_first_not_of(" \t\n");
	size_t last = obj.find_last_not_of(" \t\n");
	obj = obj.substr(first, last - first + 1);
}