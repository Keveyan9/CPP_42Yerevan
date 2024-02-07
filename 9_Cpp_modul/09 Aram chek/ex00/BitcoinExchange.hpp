#pragma once
#include "main.hpp"

class BitcoinExchange
{
private:
	std::map<std::string, double>_myMap;
	std::string 				_csv_base;
	std::string 				_input_data;
	std::ifstream 				_base_file;
	std::ifstream				 _data_file;
public:
	BitcoinExchange(/* args */);
	BitcoinExchange(const std::string &csv_base,char *input_data);
	BitcoinExchange( const BitcoinExchange &obj);
	BitcoinExchange &operator=( const BitcoinExchange &obj);
	void set_input_data( std::string  input_data);
	void set_base(std::string csv_base);
	void chek_csvbase_maping();
	row_data valid_row(std::string &row,const char delimiter);
	void relise();
 	~BitcoinExchange();
};


