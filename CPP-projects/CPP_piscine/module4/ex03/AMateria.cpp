#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria()
{
	return ;
}

AMateria::AMateria(std::string const & type)
{
	this->_type = type;
	this->_xp = 0;
	return ;
}

AMateria::~AMateria()
{
	return ;
}

AMateria & AMateria::operator=(AMateria const & src)
{
	if (this == &src)
		return (*this);
	this->_xp = src._xp;
	this->_type = src._type;
	return (*this);
}

AMateria::AMateria(AMateria const & src)
{
	*this = src;
	return ;
}

std::string const &	AMateria::getType(void)	const
{
	return (this->_type);
}

unsigned int		AMateria::getXP()	const
{
	return (this->_xp);
}

void			AMateria::addXP()
{
	if (this->_xp > 4294967250)
	{
		std::cout << "You have maxed out your spell" << std::endl;
		return ;
	}
	this->_xp = this->_xp + 10;
//	std::cout << "this is the xp " << this->_xp << std::endl;
}
