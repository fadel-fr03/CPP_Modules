#ifndef CONTACT_HPP
#define CONTACT_HPP
#pragma once

#include <string>

class Contact {
	private:
		std::string	firstname;
		std::string	lastname;
		std::string	nickname;
		std::string	secret;
		std::string	number;
	public:
		const std::string&	get_firstname(void) const;
		const std::string&	get_lastname(void) const;
		const std::string&	get_nickname(void) const;
		const std::string&	get_secret(void) const;
		const std::string&	get_number(void) const;
		void				set_firstname(std::string firstname);
		void				set_lastname(std::string lastname);
		void				set_nickname(std::string nickname);
		void				set_secret(std::string secret);
		void				set_number(std::string number);
};

#endif
