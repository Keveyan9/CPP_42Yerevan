#include "main.hpp"

// this Atoi  i wrote  for push swap but now chanhge  for c++ 09

static void	chek_plus_minus( const char **str, int *minus_counter)
{
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			*minus_counter = -1;
		(*str)++;
		if (!(**str >= '0' && **str <= '9'))
		{
			throw std::runtime_error ("non corect number input \n");
		}	
	}
}

 long double	my_atoi(const char *str)
{
	long 	res;
	int			minus_counter;
	int			flout_point;

	flout_point = 0 ;
	res = 0;
	minus_counter = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		||*str == '\v' || *str == '\f' || *str == '\r')
		str++;
	chek_plus_minus(&str, &minus_counter);
	while (*str >= '0' && *str <= '9' && *str)
	{
		res = (res * 10) +(*str - '0');
		str++;
		flout_point = flout_point * 10;
		if(*str == '.' && flout_point == 0)
		{
			flout_point = 1;
			str++;
		}
	}
	if(flout_point < 1)
		flout_point = 1;
	if (!(*str))
		return (static_cast<long double>(res*minus_counter)/flout_point);
	throw std::runtime_error ("non corect number input\n");
	return(0);
}