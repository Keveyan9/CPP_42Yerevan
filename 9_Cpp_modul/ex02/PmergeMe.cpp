#include "main.hpp"
#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	std::cout <<YELLOW << "default constructor cold but don't have data please send data \n" << RESET;
}

PmergeMe::PmergeMe(std::string &data)
{
	_data = data;
	std::cout <<YELLOW << " constructor cold\n" << RESET;
}

PmergeMe::PmergeMe(const PmergeMe  &obj)
{
	_data = obj.set_data;
	std::cout <<YELLOW << " copy constructor cold\n" << RESET;

}

PmergeMe& PmergeMe::operator=(PmergeMe &obj)
{
	_data = obj.set_data;
	std::cout <<YELLOW << " operater = cold \n" << RESET;
	return(*this);
}

PmergeMe::set_data(std::string &data)
{
	_data = data;
}