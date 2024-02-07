#include "main.hpp"
#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	std::cout <<YELLOW << "default constructor cold but don't have data please send data \n" << RESET;
}

PmergeMe::PmergeMe(char **data)
{
	_data = data;
	std::cout <<YELLOW << "constructor cold\n" << RESET;
}

PmergeMe::PmergeMe(const PmergeMe  &obj)
{
	_data = obj._data;
	std::cout <<YELLOW << "copy constructor cold\n" << RESET;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &obj)
{
	_data = obj._data;
	std::cout <<YELLOW << "operater = cold \n" << RESET;
	return(*this);
}

void PmergeMe::set_data(char **data)
{
	_data = data;
}

void PmergeMe::put_in_conteyner()
{
	int set_number;
	for(int i = 1;_data[i];i++)
	{
		set_number = my_atoi_chek(_data[i]);
		if(set_number == 0 )
			throw std::runtime_error(" can not be  zero");
		_my_vector.push_back(set_number);
		_my_decue.push_back(set_number);
		// std::cout << YELLOW << "relise test " << set_number << "\n" <<RESET;
	}

	_lenqt = _my_vector.size();
	if(_lenqt%2 != 0)
	{
		_my_vector.push_back(0);
		_my_decue.push_back(0);
		_flag_add_zero = 1;
		_lenqt++;
	}
	else
		_flag_add_zero = 0;

}


void PmergeMe::relise()
{
	size_t count ;

	put_in_conteyner();
	count = 0;
	if (hasDuplicates(_my_vector))
		throw std::runtime_error("have dublicet number");
	std::cout << "Before: ";
	while(count < _lenqt - _flag_add_zero)
		std::cout << _my_vector[count++] << " ";
	count = 0;
	std::cout <<"\nAfter :";
 	timeval start, end;
    // Measure start time vectors 
    gettimeofday(&start, NULL);


	// _______________sort vector_________________
	merge_insertion_sort(_my_vector);
	// t_print(_my_vector,3);
	// cod for mejerement vector time 
	gettimeofday(&end, NULL);
    // Calculate the elapsed time in milliseconds<
  _vector_tyme_sort = (end.tv_sec - start.tv_sec) * 1000000LL + (end.tv_usec - start.tv_usec);
	 // Measure start time vectors 
	gettimeofday(&start, NULL);

	// _________ sort decue ______
	merge_insertion_sort(_my_decue);
	// cod for mejerement vector time 
	gettimeofday(&end, NULL);
	// Calculate the elapsed time in milliseconds<
	_decue_tyme_sort = (end.tv_sec - start.tv_sec) * 1000000LL + (end.tv_usec - start.tv_usec);
	// t_print(_my_vector,3);
	for(size_t i = _flag_add_zero ; i < _lenqt ;i++)
	{
		std::cout << " " << _my_decue[i];
	}
	std::cout <<"\nTime to process a range of "<< _lenqt << std::fixed << " elements with vectors : " << _vector_tyme_sort << "\n";
	std::cout <<  "Time to process a range of "<< _lenqt << " elements with   decue : " << _decue_tyme_sort << "\n";
}

// std::vector<int> PmergeMe::generateJacobsthalSequence(int n)
// {
//     std::vector<int> sequence;
//     sequence.push_back(0); // J(0)
//     sequence.push_back(1); // J(1)
    
//     for (int i = 2; i <= n; ++i) {
//         sequence.push_back(sequence[i-1] + 2 * sequence[i-2]);
//     }
    
//     return sequence;
// }

PmergeMe::~PmergeMe()
{

}
