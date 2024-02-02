#include"BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() 
{
	std::cout << YELLOW << " Worning "<< RESET << "defolt bitcoin class creat enter base and input data\n";
}

// parametric constructers 

BitcoinExchange::BitcoinExchange(const std::string &csv_base, char *input_data)
{
	_csv_base = csv_base;
	_input_data = input_data;
	 _base_file.open(csv_base.c_str());
	if(!(_base_file.good()))
		throw std::runtime_error ("base file cannot open");
	chek_csvbase_maping();
	_data_file.open(input_data);
	if(!(_data_file.good()))
		throw std::runtime_error ("data file cannot open");
	std::cout << GREEN << " parametric constructers collse"<< RESET << " bitcoin class base_name " << YELLOW << csv_base 
		<< RESET<< " input data name " << YELLOW << input_data << RESET<< "\n";
}

//copy constructer 
BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
{
	this->_csv_base		=	obj._csv_base;
	this->_input_data	=	obj._input_data;
	_base_file.open(_csv_base.c_str());
	if(!_csv_base.empty())
	{
		if(!_base_file.good())
			throw std::runtime_error ("base file in copy  cannot open");
		chek_csvbase_maping();
	}
	_data_file.open(_input_data.c_str());
	if(!_data_file.good() && !_input_data.empty())
		throw std::runtime_error ("data file cannot open");
	std::cout << BLUE << "copy constructor is called \n" << RESET;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj)
{
	if(&obj != this)
	{
		this->_csv_base		=	obj._csv_base;
		this->_input_data	=	obj._input_data;
	_base_file.open(_csv_base.c_str());
	if(!_csv_base.empty())
	{
		if(!_base_file.good())
			throw std::runtime_error ("base file in operator= cannot open");
		chek_csvbase_maping();
	}
	_data_file.open(_input_data.c_str());
	if(!(_data_file.good()) && !_input_data.empty())
		throw std::runtime_error ("data file cannot open in operator=");
	}
	std::cout <<  " bitcoin copy operator  called,  base name" << YELLOW << _csv_base 
		<< RESET<< " input data name " << YELLOW << _input_data << RESET<< "\n";
	return(*this);
}

void BitcoinExchange::set_input_data(std::string input_data)
{
 	_input_data = input_data;

	if(_data_file.good())
		_data_file.close();
	_data_file.open(_input_data.c_str());
	if(!_data_file.good())
		throw std::runtime_error ("data file cannot open in operator=");
	std::cout << GREEN << "new input data name " << YELLOW << _input_data << RESET<< "\n";
}

void BitcoinExchange ::set_base(std::string csv_base)
{
 	_csv_base = csv_base;

	if(_base_file.good())
		_base_file.close();
	_base_file.open(_csv_base.c_str());
	if(!_base_file.good())
		throw std::runtime_error ("csv file cannot open in operator =");
	chek_csvbase_maping();
	std::cout << GREEN << "new base name " << YELLOW << _csv_base << RESET<< "\n";
}

BitcoinExchange::~BitcoinExchange()
{

}

void BitcoinExchange::chek_csvbase_maping()
{
	std::string row;
	row_data S_valid_row;
	std::string ferst_row[2];
	// ferst line cheke
	std::getline(_base_file, row);
	my_split(row,',',ferst_row,2);
	if( ferst_row[0].size() == 4 && ferst_row[0] == "date" 
		&& ferst_row[1].size() == 13 && ferst_row[1] == "exchange_rate")
	{
	while (std::getline(_base_file, row)) // Read file line by line
	{
		S_valid_row = valid_row(row,',');
		_myMap.insert(std::make_pair(S_valid_row.days[0], S_valid_row.valu));
		// std::cout << i++ << " __   " << S_valid_row.days[0] << std::endl; // Print each line to standard output
	}
		_base_file.close();
	}
	else
		throw std::runtime_error("in base ferst row is not corect ");
}

row_data BitcoinExchange::valid_row(std::string &row,const char delimiter)
{
	row_data row_chek;
	if(row.empty())
		throw std::runtime_error("row is empty");
	my_split(row, delimiter,row_chek.days,2);
	my_trim(row_chek.days[0]);
	my_trim(row_chek.days[1]);
	if(row_chek.days[1].empty())
		throw std::runtime_error("dont have valu data");
	row_chek.valu = my_atoi(row_chek.days[1].c_str());
	if (row_chek.valu < 0)
		throw std::runtime_error("base valu can not be minus");
	if(!isValidDate(row_chek.days[0],2009))
		throw  std::runtime_error("base data days not corectly ");
	return(row_chek);
}

void BitcoinExchange::relise()
{
	if(_data_file.good())
	{
		int i = 0;
		std::string	row;
		row_data	S_valid_row;
		std::string	ferst_row[2];
		// ferst line cheke
		std::getline(_data_file, row);
		my_split(row,'|',ferst_row,2);
		my_trim(ferst_row[0]);
		my_trim(ferst_row[1]);
		if( ferst_row[0].size() == 4 && ferst_row[0] == "date" 
			&& ferst_row[1].size() == 5 && ferst_row[1] == "value")
		{
			while(std::getline(_data_file, row))
			{
				try
				{
					S_valid_row = valid_row(row,'|');
					if(S_valid_row.valu <= 1000 && S_valid_row.valu >= 0 )
					{
					// std::cout << i++ << " __   " << S_valid_row.days[0] << " value " << S_valid_row.valu<< std::endl; // Print each line to standard output
						auto it =_myMap.find(S_valid_row.days[0]);
						if(it == _myMap.end())
							it = _myMap.lower_bound(S_valid_row.days[0]);
						if(it != _myMap.begin())
							it--;
						std::cout << BOLDBLUE << S_valid_row.days[0] << "=>" << S_valid_row.valu<< " = " << std::fixed << (it->second * S_valid_row.valu) << RESET << "\n";
					}
					else
						std::cout << RED <<" WORNING" << S_valid_row.days[0] << "this days valu is not corectli "<< RESET << "\n";
				}
				catch(const std::exception& error_messege)
				{
					std::cout << error_messege.what() << std::endl;
				}
			}
		}
		else
			throw std::runtime_error("in data_input ferst row is not corect");
	}
}