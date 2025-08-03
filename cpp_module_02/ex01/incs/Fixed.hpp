#ifndef FIXED_HPP
#define FIXED_HPP

#pragma once
#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int fixed_point_number;
		static const int fraction_bits = 8;

	public:
		Fixed();
		Fixed(const Fixed &to_copy);
		Fixed &operator=(const Fixed &to_copy);
		Fixed(const int num);
		Fixed(const float num);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream &operator<<(std::ostream &stream, Fixed const &i);

#endif