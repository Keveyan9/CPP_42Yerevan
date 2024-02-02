#include "main.hpp"

bool isValidDate(const std::string& dateStr, const int start)
 {
    // Check if the string has the correct length
    if (dateStr.length() != 10)
        return false;

    // Check if dashes are at the correct positions
    if (dateStr[4] != '-' || dateStr[7] != '-')
        return false;

    // Attempt to parse the year, month, and day
    int year = std::atoi(dateStr.substr(0, 4).c_str());
    int month = std::atoi(dateStr.substr(5, 2).c_str());
    int day = std::atoi(dateStr.substr(8, 2).c_str());
    // Check if year, month, and day are within valid ranges
    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31 || year < start)
        return false;

    // Check for valid days in February
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            if (day > 29)
                return false;
        } else {
            if (day > 28)
                return false;
        }
    }

    // Check for valid days in months with 30 days
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30)
            return false;
    }

    return true;
}

// int main() {
//     std::string dateStr = "1899-02-02";

//     if (isValidDate(dateStr, 1990)) {
//         std::cout << "Valid date: " << dateStr << std::endl;
//     } else {
//         std::cout << "Invalid date: " << dateStr << std::endl;
//     }

//     return 0;
// }
