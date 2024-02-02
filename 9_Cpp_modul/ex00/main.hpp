#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include "colors.hpp"
#include <fstream>
#include <map>
#include <cstdlib>


struct row_data
{
	long double valu;
	std::string days[2];
};

void my_split(const std::string& str, char delimiter, std::string *array,int bloc);
long double	my_atoi(const char *str);
bool isValidDate(const std::string& dateStr, const int start);
void my_trim(std::string &obj);