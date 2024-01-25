#include "ScalarConverter.hpp"

    static bool convertToChar(const std::string& literal, char& result) 
	{
		if (literal == "nan")
		{
			std::cout << "char: impossible\n";
			return(false);
		}
		if(literal[literal.size()-1] == 'f')
		{
			std::cout << "char: '*'\n";
			return false;
		}
        if (literal.size() == 3 && literal[0] == '\'' && literal[2] == '\'')
		 {
            result = static_cast <char>(literal[1]);
            return true;
        } 
		else
		{

            std::cout << "char: Non displayable" << std::endl;
            return false;
        }
    }

    // Helper method to convert string to int
    static bool convertToInt(const std::string& literal, int& result)
	{
		if (literal == "nan")
		{
			std::cout << "int: impossible\n";
			return(false);
		}
        std::istringstream iss(literal);
		iss>>result;
		result = static_cast <int> (result);
        return !(iss.fail());
    }

    // Helper method to convert string to float
    static bool convertToFloat(const std::string& literal, float& result)
	{
		if (literal == "nan")
		{
			std::cout << "float: nanf\n";
			return(false);
		}
		std::istringstream iss(literal);
        iss>>result;
		result = static_cast <float> (result);
        return !(iss.fail());
    }

    // Helper method to convert string to double
    static bool convertToDouble(const std::string& literal, double& result)
	{	
		if (literal == "nan")
		{
			std::cout << "float: nan\n";
			return(false);
		}
       std::istringstream iss(literal);
        iss>>result;
		result = static_cast <double> (result);
        return !(iss.fail());
    }


	ScalarConverter::ScalarConverter()
	{

	}
	ScalarConverter::~ScalarConverter()
	{

	}

 	void ScalarConverter::convert(const std::string& literal) 
	{
        char charResult;
        int intResult;
        float floatResult;
        double doubleResult;

        // Convert to char
        if (convertToChar(literal, charResult)) {
            std::cout << "Char: " << charResult << std::endl;
        }

        // Convert to int
        if (convertToInt(literal, intResult)) 
		{
            std::cout << "Int: " << intResult << std::endl;
        }

        // Convert to float
        if (convertToFloat(literal, floatResult))
		{
			if(floatResult - static_cast<int>(floatResult) == 0)
			{
         		std::cout << std::fixed << std::setprecision(1) <<"Float: " << static_cast<float> (floatResult )<< "f"<< std::endl;
			}
			else
				std::cout << std::fixed <<"Float: " << static_cast<float> (floatResult )<< "f"<< std::endl;
        }

        // Convert to double
        if (convertToDouble(literal, doubleResult)) {
            std::cout << std::fixed << "Double: " << doubleResult << std::endl;
        }
    }
