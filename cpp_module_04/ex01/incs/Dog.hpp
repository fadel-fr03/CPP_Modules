#ifndef DOG_HPP
#define DOG_HPP

#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *brain;

	public:
		Dog();
		Dog(const Dog &to_copy);
		Dog &operator=(const Dog &to_copy);
		virtual ~Dog();

		void makeSound() const;
		std::string getType() const;
		void setIdea(std::string idea);
		void getIdeas();
};

#endif