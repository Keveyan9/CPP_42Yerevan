#pragma once
#include "PmergeMe.hpp"
#include "main.hpp"

class PmergeMe
{
	private:
	std::string		 _data;
	std::vector(int) _my_vector;

	public:

		PmergeMe(/* args */);
		PmergeMe(std::string &data);
		PmergeMe(PmergeMe &obj);
		PmergeMe operator=(PmergeMe &obj);
		void set_data(std::string &data);
		~PmergeMe();
};