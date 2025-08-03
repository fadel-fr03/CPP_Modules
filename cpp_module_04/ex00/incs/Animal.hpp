#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#pragma  once
#include <iostream>
#include <string>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal &to_copy);
		Animal &operator=(const Animal &to_copy);
		virtual ~Animal();

		virtual void makeSound() const;
		virtual std::string getType() const;
};

#endif
