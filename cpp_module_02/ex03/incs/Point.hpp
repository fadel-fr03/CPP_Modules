#ifndef POINT_HPP
#define POINT_HPP

#pragma once
#include "Fixed.hpp"

class Point
{
	private:
		const Fixed x;
		const Fixed y;

	public:
		Point();
		Point(const float xVal, const float yVal);
		Point &operator=(const Point &to_copy);
		Point(const Point &to_copy);
		~Point();

		Fixed getX(void) const;
		Fixed getY(void) const;
};

std::ostream	&operator<<(std::ostream &o, Point const point);

#endif