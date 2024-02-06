// // #include <iostream>
// // #include <vector>
// // #include <algorithm>

// // // Function to perform binary search and return the position to insert 'value'
// // // in the sorted sequence 'arr'
// // int binarySearch(const std::vector<int>& arr, int value) {
// //     int low = 0;
// //     int high = arr.size() - 1;
// //     int closestMidIndex = low; // Initialize with the first index
    
// //     while (low <= high) {
// //         int mid = low + (high - low) / 2;
        
// //         if (arr[mid] == value)
// //             return mid;
// //         else if (arr[mid] < value) {
// //             low = mid + 1;
// //             closestMidIndex = low; // Update closest middle index
// //         } else {
// //             high = mid - 1;
// //             closestMidIndex = mid; // Update closest middle index
// //         }
// //     }
    
// //     // If value is smaller than all elements, return the first index
// //     if (closestMidIndex == 0)
// //         return 0;
// //     // If value is greater than all elements, return the last index
// //     else if (closestMidIndex == arr.size())
// //         return arr.size();
// //     else
// //         return closestMidIndex;
// // }

// // int main() {
// //     std::vector<int> arr = {1,  5 }; // Sorted array
    
// //     int target = 3; // Example target value
    
// //     int index = binarySearch(arr, target);
    
// //     std::cout << "Closest middle index: " << index << std::endl;
    
// //     return 0;
// // }


// // #include <iostream>
// // #include <vector>

// // // Function to generate Jacobsthal sequence up to n terms
// // std::vector<int> generateJacobsthalSequence(int n) {
// //     std::vector<int> sequence;
// //     sequence.push_back(0); // J(0)
// //     sequence.push_back(1); // J(1)
    
// //     for (int i = 2; i <= n; ++i) {
// //         sequence.push_back(sequence[i-1] + 2 * sequence[i-2]);
// //     }
    
// //     return sequence;
// // }

// // // Function to insert Jacobsthal sequence elements into the main chain with minimal comparisons
// // void insertIntoMainChain(const std::vector<int>& jacobsthalSequence) {
// //     std::cout << "Elements inserted into the main chain with minimal comparisons:" << std::endl;
    
// //     for (size_t i = 1; i < jacobsthalSequence.size(); ++i) {
// //         int element = jacobsthalSequence[i];
// //         std::cout << element << " ";
// //     }
    
// //     std::cout << std::endl;
// // }

// // int main() {
// //     int n = 10; // Generate Jacobsthal sequence up to n terms
    
// //     std::vector<int> jacobsthalSequence = generateJacobsthalSequence(n);
    
// //     insertIntoMainChain(jacobsthalSequence);
    
// //     return 0;
// // }

// #include <iostream>
// #include <vector>
// #include <algorithm>

// // Function to generate Jacobsthal sequence up to n terms
// std::vector<int> generateJacobsthalSequence(int n) {
//     std::vector<int> sequence;
//     sequence.push_back(0); // J(0)
//     sequence.push_back(1); // J(1)
    
//     for (int i = 2; i <= n; ++i) {
//         sequence.push_back(sequence[i-1] + 2 * sequence[i-2]);
//     }
    
//     return sequence;
// }

// // Function to insert elements from given vector into the main chain with alternating order
// void insertIntoMainChain(const std::vector<int>& inputVector) {
//     std::vector<int> mainChain;
//     std::vector<int> jacobsthalSequence = generateJacobsthalSequence(inputVector.size() - 1);
    
//     std::cout << "Elements inserted into the main chain with alternating order:" << std::endl;
    
//     for (size_t i = 1; i < inputVector.size(); ++i) {
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
//     for (size_t i = 0; i < mainChain.size(); ++i) {
//         std::cout << mainChain[i] << " ";
//     }
//     std::cout << std::endl;
// }

// int main() {
//     std::vector<int> inputVector = {1, 2, 5, 48, 547, 545, 598, 4865, 55, 654};
    
//     insertIntoMainChain(inputVector);
    
//     return 0;
// }
#include <iostream>
#include <vector>
#include <algorithm>

// Function to generate Jacobsthal sequence up to n terms
std::vector<int> generateJacobsthalSequence(int n) {
    std::vector<int> sequence;
    sequence.push_back(0); // J(0)
    sequence.push_back(1); // J(1)
    
    for (int i = 2; i <= n; ++i) {
        sequence.push_back(sequence[i-1] + 2 * sequence[i-2]);
    }
    
    return sequence;
}

// Custom implementation of reverse
void customReverse(std::vector<int>& vec, int start, int end) {
    while (start < end) {
        std::swap(vec[start], vec[end]);
        ++start;
        --end;
    }
}

// Function to reverse groups of numbers in a vector based on Jacobsthal sequence
void reverseGroups(std::vector<int>& numbers, const std::vector<int>& jacobsthalSequence) {
    int groupStart = 0;
    int groupEnd = 0;
    for (size_t i = 1; i < jacobsthalSequence.size(); ++i) {
        int groupSize = jacobsthalSequence[i];
        groupEnd = groupStart + groupSize - 1;
        customReverse(numbers, groupStart, groupEnd);
        groupStart = groupEnd + 1;
    }
}

// Function to print a vector
void printVector(const std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> numbers = {1, 2, 5, 48, 547, 545, 598, 4865, 55, 654};
    int n = numbers.size() - 1; // Generate Jacobsthal sequence up to n terms
    std::vector<int> jacobsthalSequence = generateJacobsthalSequence(n);
    
    std::cout << "Original vector:" << std::endl;
    printVector(numbers);
    
    reverseGroups(numbers, jacobsthalSequence);
    
    // std::cout << "Reversed groups based on Jacobsthal sequence:" << std::endl;
    // printVector(numbers);
    
    return 0;
}
