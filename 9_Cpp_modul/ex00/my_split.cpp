#include "main.hpp"

void my_split(const std::string& str, char delimiter, std::string *array,int bloc) 
{
    size_t start = 0;
    size_t end = str.find(delimiter);
    int i = 0;

    while (end != std::string::npos)
     {
        // std::cout << "int i in split " << i <<"\n";
        if(i >= bloc)
            throw std::runtime_error("more split then 2 bloks");
        array[i++] = str.substr(start, end - start);
        start = end + 1;
        end = str.find(delimiter, start);
    }

    // Add the last substring
    if(i == bloc - 1)
    {
        array[i++] = str.substr(start, end);
        return;
    }
    throw std::runtime_error("last block is more or little");
    //  std::cout << "int i in split " << i << "   " << bloc << "\n";
}