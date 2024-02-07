#include "main.hpp"

// this Atoi  i wrote  for push swap but now chanhge  for c++ 09

static void	chek_plus_minus( const char **str)
{
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			throw std::runtime_error ("can not be minus");
		(*str)++;
		if (!(**str >= '0' && **str <= '9'))
		{
			throw std::runtime_error ("non corect number input");
		}	
	}
}

int 	my_atoi_chek(const char *str)
{
	int	res;

	res = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		||*str == '\v' || *str == '\f' || *str == '\r')
		str++;
	chek_plus_minus(&str);
	while (*str >= '0' && *str <= '9' && *str)
	{
		res = (res * 10) +(*str - '0');
		str++;
		if(*str == '.')
		{
			throw std::runtime_error ("can not bi point number");
		}
	}
	if (!(*str))
		return (res);
	throw std::runtime_error ("non corect number input");
	return(0);
}