#ifndef DOG_HPP
#define DOG_HPP

#pragma once
#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog &to_copy);
		Dog &operator=(const Dog &to_copy);
		virtual ~Dog();

		void makeSound() const;
		std::string getType() const;
};

#endif