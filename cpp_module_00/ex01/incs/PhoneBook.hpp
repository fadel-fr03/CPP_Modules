#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#pragma once

#include "Contact.hpp"
#include <iostream>

class PhoneBook {
	private:
		Contact	contacts[8];
		int 	size;
		int 	index;
	public:
		PhoneBook() : size (0), index (0) {}
		int 	get_size(void) const;
		void	add_contact(std::string data[5]);
		void	display_contact(int i) const;
		void	display_phonebook(void) const;
};

#endif