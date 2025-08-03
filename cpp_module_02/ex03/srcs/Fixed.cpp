#include "../incs/Fixed.hpp"

// Constructors

Fixed::Fixed()
{
	//std::cout << "Default constructor called" << std::endl;
	this->fixed_point_number = 0;
}

Fixed::Fixed(const Fixed &to_copy)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = to_copy;
}

Fixed &Fixed::operator=(const Fixed &to_copy)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &to_copy)
		this->setRawBits(to_copy.getRawBits());
	return *this;
}

Fixed::Fixed(const int num)
{
	//std::cout << "Int constructor called" << std::endl;
	this->fixed_point_number = num << fraction_bits;
}

Fixed::Fixed(const float num)
{
	//std::cout << "Float constructor called" << std::endl;
	this->fixed_point_number = num * (1 << fraction_bits);
}


// Destructor

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl; 
}

// Setters and Getters

int Fixed::getRawBits(void) const
{
	return this->fixed_point_number;
}

void Fixed::setRawBits(int const raw)
{
	this->fixed_point_number = raw;
}

// Value returners

float Fixed::toFloat(void) const
{
	return static_cast<float>(this->getRawBits()) / (1 << fraction_bits);
}

int Fixed::toInt(void) const
{
	return this->fixed_point_number >> fraction_bits;
}

// << operator overload

std::ostream &operator<<(std::ostream &stream, Fixed const &i)
{
	stream << i.toFloat();
	return stream;
}

// Comparison operators overload

bool Fixed::operator>(const Fixed &num) const
{
	if (this->getRawBits() > num.getRawBits())
		return true;
	return false;
}

bool Fixed::operator<(const Fixed &num) const
{
	if (this->getRawBits() < num.getRawBits())
		return true;
	return false;
}

bool Fixed::operator>=(const Fixed &num) const
{
	if (this->getRawBits() >= num.getRawBits())
		return true;
	return false;
}

bool Fixed::operator<=(const Fixed &num) const
{
	if (this->getRawBits() <= num.getRawBits())
		return true;
	return false;
}

bool Fixed::operator==(const Fixed &num) const
{
	if (this->getRawBits() == num.getRawBits())
		return true;
	return false;
}

bool Fixed::operator!=(const Fixed &num) const
{
	if (this->getRawBits() != num.getRawBits())
		return true;
	return false;
}

// Arithmetic operators overload

Fixed Fixed::operator+(const Fixed &num) const
{
	Fixed f(this->toFloat() + num.toFloat());
	return f;
}

Fixed Fixed::operator-(const Fixed &num) const
{
	Fixed f(this->toFloat() - num.toFloat());
	return f;
}

Fixed Fixed::operator*(const Fixed &num) const
{
	Fixed f(this->toFloat() * num.toFloat());
	return f;
}

Fixed Fixed::operator/(const Fixed &num) const
{
	Fixed f(this->toFloat() / num.toFloat());
	return f;
}

// Increment/Decrement operators overload
// prefix
Fixed &Fixed::operator++(void)
{
	++this->fixed_point_number;
	return *this;
}

// postfix
Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	tmp.fixed_point_number = this->fixed_point_number++;
	return tmp;
}

// prefix
Fixed &Fixed::operator--(void)
{
	--this->fixed_point_number;
	return *this;
}

// postfix
Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	tmp.fixed_point_number = this->fixed_point_number--;
	return tmp;
}

// Min and Max

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}
