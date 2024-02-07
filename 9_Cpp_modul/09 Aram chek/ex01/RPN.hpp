#pragma once
#include "main.hpp"

class RPN
{
private:
    static std::stack<double> stack;
    RPN();
	RPN(const RPN&);
	RPN& operator= (const RPN&);
	~RPN();
public:
    static bool is_Operator(const char *c);
    static int perform_Operation(int operand1, int operand2, char op);
    static void evaluate_RPN(const std::string& expression, int &result);
};