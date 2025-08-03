#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#pragma once
#include <iostream>
#include <string>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &to_copy);
		WrongAnimal &operator=(const WrongAnimal &to_copy);
		~WrongAnimal();

		void makeSound() const;
		std::string getType() const;
};

#endif