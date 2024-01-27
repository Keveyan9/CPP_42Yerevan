#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

template <typename conteyners>

 typename conteyners::iterator easyfind(conteyners &boxs, int n)
{
	typename conteyners::iterator ret_data = std::find(boxs.begin(), boxs.end(), n);
	if(ret_data == boxs.end())
	{
		throw std::out_of_range("out of rang!\n");
	}
	return(ret_data);
}

