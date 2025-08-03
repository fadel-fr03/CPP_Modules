#ifndef BRAIN_HPP
#define BRAIN_HPP

#pragma once
#include <iostream>
#include <string>

class Brain 
{
	private:
		std::string ideas[100];
	
	public:
		Brain();
		Brain(const Brain &to_copy);
		Brain &operator=(const Brain &to_copy);
		virtual ~Brain();

		int number_ideas;
		void setIdea(std::string idea);
		std::string getIdea(int i);
};


#endif
