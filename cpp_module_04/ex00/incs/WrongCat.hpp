#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#pragma once
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat &to_copy);
		WrongCat &operator=(const WrongCat &to_copy);
		~WrongCat();

		void makeSound() const;
		std::string getType() const;
};


#endif