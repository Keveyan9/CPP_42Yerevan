#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include<cstdlib>

void replacing(const std::string &filename, const std::string &s1, const std::string &s2)
{
	std::ifstream inputFile(filename.c_str());

	 if (!inputFile.is_open())
    {
        std::cerr << "Error opening file." << "\n";
       exit (1); // Return an error code
    }

	std::stringstream buffer;
	std::string fileContents;
	std::string new_name;
	size_t pos ;
	pos = 0;

	if (s1 == s2 || s1.empty())
	{
        std::cerr << "s1 and s2  equal or s1 is empty" << "\n";
       exit (1); // Return an error code
    }
	
	if (inputFile.is_open())
		buffer << inputFile.rdbuf();
	else
	{
		std::cerr << "Failed to open file: " << filename << std::endl;
		return;
	}
	inputFile.close();
	fileContents = buffer.str();
	new_name = filename + ".replace";
	std::ofstream outFile(new_name.c_str());
	if (!outFile)
	{
		std::cerr << "Error opening file " << new_name  << std::endl;
		return;
	}
	pos = fileContents.find(s1, pos);
	while (pos != std::string::npos)
	{
		fileContents.erase(pos, s1.length());
		fileContents.insert(pos, s2);
		pos += s2.length();
		pos = fileContents.find(s1, pos);
	}
	outFile << fileContents;
	outFile.close();
}

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "was not input filename, s1, s2"<< std::endl;
		return (0);
	}
	replacing(av[1], av[2], av[3]);
}
