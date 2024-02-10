#pragma once
#include "main.hpp"


class PmergeMe
{
	private:
		char				 **_data;
		size_t				_flag_add_zero;
		size_t				_lenqt;
		std::vector<int>	 _my_vector;
		std::deque<int>		 _my_decue;
		long long 			 _vector_tyme_sort;
		long long 		 	 _decue_tyme_sort;
		// int 				 _count_vector;
		// int					 _count_decue;
	public:

		PmergeMe(/* args */);
		PmergeMe(char **data);
		PmergeMe(const PmergeMe &obj);
		PmergeMe& operator=(const PmergeMe &obj);
		void set_data(char **data);
		void put_in_conteyner();

		template 	<typename conteyner>
		void t_print(conteyner &vec,int n);

		template 	<typename conteyner>
		int binarySearch(conteyner& arr, int value);
		template 	<typename conteyner>
		void merge_insertion_sort(conteyner &v);
		template 	<typename conteyner>
		void  my_insert(conteyner &larg, conteyner &small);
		template 	<typename conteyner>
		bool hasDuplicates(const conteyner& nums);
		// template 	<typename conteyner>
		// void insertIntoMainChain(conteyner& inputVector);
	
		// std::vector<int> generateJacobsthalSequence(int n);

		void relise();
		~PmergeMe();
};

template 	<typename conteyner>
void PmergeMe::t_print(conteyner &vec ,int n)
{
	std::cout << n << "___________Vector elements:_____________";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

}

template 	<typename conteyner>
static void my_swap(conteyner & vec, int i, int j) {
    int temp = vec[i];
    vec[i] = vec[j];
    vec[j] = temp;
}


template 	<typename conteyner>
int PmergeMe::binarySearch(conteyner& arr, int value) {
    int low = 0;
    int high = arr.size() - 1;
    int closestMidIndex = low; // Initialize with the first index
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == value)
            return mid;
        else if (arr[mid] < value) {
            low = mid + 1;
            closestMidIndex = low; // Update closest middle index
        } else {
            high = mid - 1;
            closestMidIndex = mid; // Update closest middle index
        }
    }
    
    // If value is smaller than all elements, return the first index
    if (closestMidIndex == 0)
        return 0;
    // If value is greater than all elements, return the last index
    else if (closestMidIndex == static_cast<int>(arr.size()))
        return arr.size();
    else
        return closestMidIndex;
}




template 	<typename conteyner>
void PmergeMe::my_insert(conteyner &larg, conteyner &small)
{
	size_t smallSize = small.size();
	size_t i = 0;

	int valu_insert = 0;
	//// Jacobsthal sequence (n)=J(n−1)+2J(n−2) with initial values   ( 0 ) = 0 J(0)=0 and   ( 1 ) = 1 J(1)=1
	// insertIntoMainChain(small);
	while (i < smallSize)
	{
        valu_insert = binarySearch(larg,small[i]);
		larg.insert(larg.begin() + valu_insert, small[i]);
		// t_print(larg,5);
		// std::cout<<  "valu "<< valu_insert <<" \n";
		i++;
	}
}

template 	<typename conteyner>
void PmergeMe::merge_insertion_sort(conteyner &vec )
{
	int i = 0;
	int size = vec.size();
 	conteyner	larg;
	conteyner 	small;

	// t_print(vec,7);
	// std::cout << "size_" << size << "\n";
	if (size <= 2 )
	{
		// std::cout << "size_ if" << size << "\n";
		if(vec[0] > vec[1])
			my_swap(vec,1,0);
		return;
	}
	while (i + 1 < size)
	{
		if (vec[i] < vec[i + 1])
		{
			larg.push_back(vec[i]);
			small.push_back(vec[i + 1]);
		}
		else
		{
			larg.push_back(vec[i + 1]);
			small.push_back(vec[i]);
		}
		i += 2;
	}
	if (i < size)
	{
		small.push_back(vec[i]);
	}
	merge_insertion_sort(larg);
	my_insert(larg, small);
	vec = larg;
}

template 	<typename conteyner>
bool PmergeMe::hasDuplicates(const conteyner& nums) {
    for (size_t i = 0; i < nums.size(); ++i) {
        for (size_t j = i + 1; j < nums.size(); ++j) {
            if (nums[i] == nums[j]) {
                return true; // Duplicate found
            }
        }
    }
    return false; // No duplicates found
}



// // Function to insert elements from given vector into the main chain with alternating order
// template 	<typename conteyner>
// void PmergeMe::insertIntoMainChain(conteyner& inputVector) {
//     conteyner mainChain;
//    std::vector<int> jacobsthalSequence = generateJacobsthalSequence(inputVector.size() - 1);
    
//     // std::cout << "Elements inserted into the main chain with alternating order:" << std::endl;
    
//     for (size_t i = 1; i < inputVector.size(); ++i) 
// 	{
//         int element = inputVector[i];
        
//         if (jacobsthalSequence[i - 1] % 2 == 0) {
//             // If Jacobsthal number is even, insert in ascending order
//             auto it = mainChain.begin();
//             while (it != mainChain.end() && *it < element) {
//                 ++it;
//             }
//             mainChain.insert(it, element);
//         } else {
//             // If Jacobsthal number is odd, insert in descending order
//             auto it = mainChain.begin();
//             while (it != mainChain.end() && *it > element) {
//                 ++it;
//             }
//             mainChain.insert(it, element);
//         }
//     }
    
//     // Print the main chain
//     // for (size_t i = 0; i < mainChain.size(); ++i) {
//     //     std::cout << mainChain[i] << " ";
//     // }
//     // std::cout << std::endl;
// }