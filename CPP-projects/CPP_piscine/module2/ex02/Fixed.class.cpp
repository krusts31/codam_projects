#include "Fixed.class.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(Fixed const & src)
{
	*this = src;
	return ;
}

Fixed::Fixed(int const param)
{
	this->_fixedPointValue = (param << Fixed::_numberOfFractionalBits);
}

Fixed::Fixed(float const param)
{
	this->_fixedPointValue = roundf(param * (1 << Fixed::_numberOfFractionalBits));
}

Fixed::Fixed() : _fixedPointValue(0)
{
	return ;
}

Fixed::~Fixed()
{
	return ;
}

std::ostream &operator<<(std::ostream &out, Fixed const &_fixedPointValue)
{
	out << _fixedPointValue.toFloat();
	return (out);
}
/*
**		operator overloads
*/
Fixed &	Fixed::operator=(Fixed const & src)
{
	this->_fixedPointValue = src.getRawBits();

	return *this;
}

bool Fixed::operator>(Fixed const & src) const
{
	return (this->getRawBits() > src.getRawBits());
}

bool Fixed::operator<(Fixed const & src) const
{
	return (this->getRawBits() < src.getRawBits());
}

bool Fixed::operator>=(Fixed const & src) const
{
	return (this->getRawBits() >= src.getRawBits());
}

bool Fixed::operator<=(Fixed const & src) const
{
	return (this->getRawBits() <= src.getRawBits());
}

bool Fixed::operator==(Fixed const & src) const
{
	return (this->getRawBits() == src.getRawBits());
}
bool Fixed::operator!=(Fixed const & src) const
{
	return (this->getRawBits() != src.getRawBits());
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

Fixed Fixed::operator+(Fixed const &src)
{
	Fixed val(*this);

	val.setRawBits(this->getRawBits() + src.getRawBits());
	return (val);
}

Fixed Fixed::operator-(Fixed const &src)
{
	Fixed val(*this);

	val.setRawBits(this->getRawBits() - src.getRawBits());
	return (val);
}

Fixed Fixed::operator*(Fixed const &src)
{
	Fixed val(*this);
	long tmp1, tmp2;

	tmp1 = ((long)this->getRawBits());
	tmp2 = ((long)src.getRawBits());
	val.setRawBits((tmp1 * tmp2) / (1 << Fixed::_numberOfFractionalBits));
	return (val);
}

Fixed Fixed::operator/(Fixed const &src)
{
	Fixed val(*this);
	long tmp1, tmp2;

	tmp1 = ((long)this->getRawBits());
	tmp2 = ((long)src.getRawBits());
	val.setRawBits((tmp1 * (1 << Fixed::_numberOfFractionalBits)) / tmp2);
	return (val);
}

Fixed Fixed::operator++()
{
	this->_fixedPointValue++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed Fixed::operator--()
{
	this->_fixedPointValue--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return (tmp);
}
Fixed const &Fixed::min(Fixed const &x, Fixed const &y)
{
	if (x > y)
		return (y);
	return (x);
}

Fixed &Fixed::min(Fixed &x, Fixed &y)
{
	if (x > y)
		return (y);
	return (x);
}

Fixed const &min(Fixed const &x, Fixed const &y)
{
	return (Fixed::min(x, y));
}

Fixed &min(Fixed &x, Fixed &y)
{
	return (Fixed::min(x, y));
}

Fixed const &Fixed::max(Fixed const &x, Fixed const &y)
{
	if (x > y)
		return (x);
	return (y);
}

Fixed &Fixed::max(Fixed &x, Fixed &y)
{
	if (x > y)
		return (x);
	return (y);
}

Fixed const &max(Fixed const &x, Fixed const &y)
{
	return (Fixed::max(x, y));
}

Fixed &max(Fixed &x, Fixed &y)
{
	return (Fixed::max(x, y));
}
