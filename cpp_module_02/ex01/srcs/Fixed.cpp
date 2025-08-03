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

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixed_point_number = num << fraction_bits;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixed_point_number = num * (1 << fraction_bits);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl; 
}

int Fixed::getRawBits(void) const
{
	return this->fixed_point_number;
}

void Fixed::setRawBits(int const raw)
{
	this->fixed_point_number = raw;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(this->getRawBits()) / (1 << fraction_bits);
}

int Fixed::toInt(void) const
{
	return this->fixed_point_number >> fraction_bits;
}

std::ostream &operator<<(std::ostream &stream, Fixed const &i)
{
	stream << i.toFloat();
	return stream;
}
