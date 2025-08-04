#include "../incs/RPN.hpp"

RPN::RPN()
{}

RPN::~RPN()
{}

RPN::RPN(const RPN &to_copy)
{
	(void)to_copy;
}

RPN &RPN::operator=(const RPN &to_copy)
{
	(void)to_copy;
	return *this;
}

bool RPN::isOperator(char c)
{
	return (c == '-') || (c == '+') || (c == '/') || (c == '*');
}

bool RPN::isDigit(char c)
{
	return (c >= '0') && (c <= '9');
}

const char *RPN::DivideByZeroException::what() const throw()
{
	return "Error: Divide By Zero.";
}

const char *RPN::StackUnderflowException::what() const throw()
{
	return "Error: Not enough operands.";
}

const char *RPN::InvalidExprException::what() const throw()
{
	return "Error";
}

void RPN::applyOperator(char op)
{
	if (stack.size() < 2)
		throw StackUnderflowException();

	int first;
	int second;
	int to_push;

	first = stack.top();
	stack.pop();

	second = stack.top();
	stack.pop();

	if (op == '-')
		to_push = second - first;
	else if (op == '+')
		to_push = second + first;
	else if (op == '*')
		to_push = second * first;
	else
	{
		if (first == 0)
			throw DivideByZeroException();
		to_push = second / first;
	}

	stack.push(to_push);
}

int RPN::evaluate(const std::string &expr)
{
	std::stringstream ss(expr);
	std::string token;
	while (ss >> token)
	{
		if (isDigit(token[0]) && token.length() == 1)
		{
			int num = std::atoi(&token[0]);
			stack.push(num);
		}
		else if (isOperator(token[0]) && token.length() == 1)
			applyOperator(token[0]);
		else
			throw InvalidExprException();
	}

	if (stack.size() != 1)
		throw InvalidExprException();
	
	int res = stack.top();
	stack.pop();

	return res;
}
