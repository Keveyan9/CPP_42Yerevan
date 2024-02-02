// #include <iostream>
// #include <string>

// // Function to trim leading and trailing whitespace characters from a string
// std::string trim(const std::string& str) {
//     size_t first = str.find_first_not_of(" \t\n");
//     size_t last = str.find_last_not_of(" \t\n");
//     if (first == std::string::npos || last == std::string::npos) {
//         // No non-whitespace characters found, return an empty string
//         return "";
//     } else {
//         return str.substr(first, last - first + 1);
//     }
// }

// int main() {
//     std::string str1 = "   test";
//     std::string str2 = "fwaf   | fwafwa";

//     std::cout << "Original string 1: '" << str1 << "'" << std::endl;
//     std::cout << "Trimmed string 1: '" << trim(str1) << "'" << std::endl;

//     std::cout << "Original string 2: '" << str2 << "'" << std::endl;
//     std::cout << "Trimmed string 2: '" << trim(str2) << "'" << std::endl;

//     return 0;
// }
