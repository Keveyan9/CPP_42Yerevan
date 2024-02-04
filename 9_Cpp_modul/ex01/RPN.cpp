#include "RPN.hpp"
#include "main.hpp"

RPN::RPN(){}
RPN::RPN(const RPN& ){}
RPN& RPN::operator= (const RPN& ){return (*this);}
RPN::~RPN(){}


bool  RPN::is_Operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int RPN::perform_Operation(int operand1, int operand2, char op) {
    switch(op) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 != 0)
                return operand1 / operand2;
            else
                throw std::invalid_argument("Division by zero error");
        default:
            throw std::invalid_argument("Invalid operator");
    }
}

void RPN::evaluate_RPN(const std::string& expression ,int &result) {
    std::stack<int> operands;
  	std::istringstream iss(expression);
  	std::string token;
    
    while (iss >> token) {
        if (isdigit(token[0])) 
		{
            operands.push(my_atoi(token.c_str()));
        }
		 else if (is_Operator(token[0])) 
		{
            if (operands.size() < 2) 
			{
                throw std::invalid_argument("Insufficient operands for operator");
            }
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();
            int result = perform_Operation(operand1, operand2, token[0]);
            operands.push(result);
        } else
		{
            throw std::invalid_argument("Invalid token");
        }
    }
    
    if (operands.size() != 1) 
	{
		throw std::invalid_argument("Invalid expression");
    }
    	result = operands.top();
}