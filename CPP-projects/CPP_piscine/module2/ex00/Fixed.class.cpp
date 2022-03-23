#include "Fixed.class.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructot called" << std::endl;
	*this = src;

	return ;
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

Fixed &	Fixed::operator=(Fixed const & src)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_fixedPointValue = src.getRawBits();

	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits function called" << std::endl;
	return (this->_fixedPointValue);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

