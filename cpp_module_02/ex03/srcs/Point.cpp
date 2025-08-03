#include "../incs/Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float xVal, const float yVal) : x(xVal), y(yVal) {}

Point &Point::operator=(const Point &to_copy)
{
	if (this == &to_copy)
		return *this;

	return *this;
}

Point::Point(const Point &to_copy) : x(to_copy.x), y(to_copy.y) {}

Point::~Point(){}

Fixed Point::getX(void) const
{
	return this->x;
}

Fixed Point::getY(void) const
{
	return this->y;
}

std::ostream	&operator<<(std::ostream &stream, Point const point)
{
	stream << "x: " << point.getX() << " / y: " << point.getY() << std::endl;
	return (stream);
}
