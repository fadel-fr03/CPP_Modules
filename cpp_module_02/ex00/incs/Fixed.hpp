#ifndef FIXED_HPP
#define FIXED_HPP

#pragma once
#include <iostream>

class Fixed
{
	private:
		int fixed_point_number;
		static const int fraction_bits = 8;

	public:
		Fixed();
		Fixed(const Fixed &to_copy);
		Fixed &operator=(const Fixed &to_copy);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif