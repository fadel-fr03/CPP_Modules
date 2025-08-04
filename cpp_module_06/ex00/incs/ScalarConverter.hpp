#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <climits>
#include <cctype>
#include <cstdlib>
#include <cmath>


class ScalarConverter
{
	private:
		// Default constructor
		ScalarConverter();

		// Destructor
		~ScalarConverter();

		// Copy constructor
		ScalarConverter(const ScalarConverter &);

		// Copy assignment operator
		ScalarConverter &operator=(const ScalarConverter &);

	public:
		static void convert(std::string const &literal);
};

#endif
