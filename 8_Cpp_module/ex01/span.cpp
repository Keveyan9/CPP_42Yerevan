#include "span.hpp"

Span::~Span(){}

Span::Span():_N(0),_busy(0){}

Span::Span(unsigned int n):_N(n),_busy(0)
{

}

Span::Span(const Span &obj)
{
	this->_N	=	obj._N;
	this->_busy =	obj._busy;
	this->_ls	=	obj._ls;
	
}

Span& Span::operator=(const Span& obj)
{
	this->_N	=	obj._N;
	this->_busy =	obj._busy;
	this->_ls	=	obj._ls;
	return(*this);
}


void Span::addNumber(const int num)
{
	if (this->_busy < this->_N)
	{
		this->_ls.push_back(num);
		this->_busy++;
	}
	else
		throw std::out_of_range("out of rang!");
}

int Span::longestSpan()
{
	if(_busy <= 1)
		throw std::runtime_error("your Span is one element !");
	std::sort(_ls.begin(), _ls.end());
	return(*(_ls.end()-1) -*(_ls.begin()));
}

int Span::shortestSpan()
{
	int span = 0;
	if(_busy <= 1)
		throw std::runtime_error("your Span is one element !");
	std::sort(_ls.begin(), _ls.end());
	span = _ls[1] - _ls[0];
	for(unsigned int n = 1; n < (_busy - 1); n++)
	{
		// _span.push_back(_ls[n+1] - _ls[n]);
		if(_ls[n+1] - _ls[n] < span)
		{
			span = _ls[n+1] - _ls[n];
		}
	}
	// std::sort(_span.begin(),_span.end());
	//return(_span[0]);
	return(span);
}
