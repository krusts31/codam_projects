#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	return ;
}

Cure::~Cure()
{
	return ;
}

Cure & Cure::operator=(Cure const & src)
{
	if (this == &src)
		return (*this);
	this->_xp = src.getXP();
	return (*this);
}

Cure::Cure(Cure const & src) : Cure::AMateria()
{
	*this = src;
	return ;
}

AMateria	*Cure::clone()	const
{
	return (new Cure());
}

void		Cure::use(ICharacter	&target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
