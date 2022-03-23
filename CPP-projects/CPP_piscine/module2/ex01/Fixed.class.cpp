#include "Fixed.class.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructot called" << std::endl;
	*this = src;
	return ;
}

Fixed::Fixed(int const param)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = (param << Fixed::_numberOfFractionalBits);
}

Fixed::Fixed(float const param)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(param * (1 << Fixed::_numberOfFractionalBits));
}

Fixed::Fixed() : _fixedPointValue(0)
{
	std::cout << "Default constructot called" << std::endl;
	return ;
}

Fixed::~Fixed()
{
	std::cout << "Deconstrucotr called" << std::endl;
	return ;
}

std::ostream &operator<<(std::ostream &out, Fixed const &_fixedPointValue)
{
	out << _fixedPointValue.toFloat();
	return (out);
}

Fixed &	Fixed::operator=(Fixed const & src)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_fixedPointValue = src.getRawBits();

	return *this;
}

int	Fixed::getRawBits(void) const
{
	return (this->_fixedPointValue);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_fixedPointValue / (float)(1 << Fixed::_numberOfFractionalBits));
}

int	Fixed::toInt(void) const
{
	return (this->_fixedPointValue >> Fixed::_numberOfFractionalBits);
}
