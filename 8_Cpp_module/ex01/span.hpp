#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
private:
    unsigned int _N;
	unsigned int _busy;
    std::vector<int> _ls;
	// std::vector<int> _span;
public:
    Span();
    Span(unsigned int n);
    Span(const Span &obj);
    Span& operator=(const Span &obj);
    ~Span();

    void addNumber(const int num);
    int shortestSpan();
    int longestSpan();
};