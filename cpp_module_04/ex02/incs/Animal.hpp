#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#pragma once
#include <iostream>
#include <string>

class Animal
{
	protected:
		std::string type;
		Animal();
		Animal(const Animal &to_copy);
		Animal &operator=(const Animal &to_copy);
	public:
		virtual ~Animal();
		virtual void makeSound() const = 0;
		virtual std::string getType() const = 0;
};

#endif
