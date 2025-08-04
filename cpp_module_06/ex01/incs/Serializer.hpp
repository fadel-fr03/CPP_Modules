#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <stdint.h>
#include <iostream>
#include "Data.hpp"

class Serializer
{
	private:
		// Default constructor
		Serializer();

		// Destructor
		~Serializer();

		// Copy constructor
		Serializer(const Serializer &);

		// Copy assignment operator
		Serializer &operator=(const Serializer &);

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
