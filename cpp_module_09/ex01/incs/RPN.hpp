#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <exception>

class RPN
{
	private:
		std::stack<int> stack;

		RPN(const RPN &to_copy);
		RPN &operator=(const RPN &to_copy);

        static bool isOperator(char c);
        static bool isDigit(char c);
		void applyOperator(char op);

	public:
		RPN();
		~RPN();

		int evaluate(const std::string &expr);

		class DivideByZeroException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};

		class StackUnderflowException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};

		class InvalidExprException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};
};

#endif