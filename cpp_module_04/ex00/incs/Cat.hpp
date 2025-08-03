#ifndef CAT_HPP
#define CAT_HPP

#pragma once
#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat &to_copy);
		Cat &operator=(const Cat &to_copy);
		virtual ~Cat();

		void makeSound() const;
		std::string getType() const;
};


#endif