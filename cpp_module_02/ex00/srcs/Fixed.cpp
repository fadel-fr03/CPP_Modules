#include "../incs/Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixed_point_number = 0;
}

Fixed::Fixed(const Fixed &to_copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = to_copy;
}

Fixed &Fixed::operator=(const Fixed &to_copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &to_copy)
		this->setRawBits(to_copy.getRawBits());
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl; 
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixed_point_number;
}

void Fixed::setRawBits(int const raw)
{
	this->fixed_point_number = raw;
}