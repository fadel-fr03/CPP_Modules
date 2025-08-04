#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>
#include <string>

class Data
{

	public:
		int age;
		std::string name;
		std::string job;

		// Default constructor
		Data();

		// Destructor
		~Data();

		// Parametarized constructor
		Data(int age, std::string name, std::string job);

		// Copy constructor
		Data(const Data &to_copy);

		// Copy assignment operator
		Data &operator=(const Data &to_copy);
};

#endif
