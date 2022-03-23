#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	return ;
}

Ice::~Ice()
{
	return ;
}

Ice::Ice(Ice const & src) : Ice::AMateria()
{
	*this = src;
	return ;
}

Ice & Ice::operator=(Ice const & src)
{
	if (this != &src)
	{
		this->_xp = src.getXP();
	}
	return (*this);
}

AMateria	*Ice::clone()	const
{
	return (new Ice());
}

void		Ice::use(ICharacter & target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" \
		<< std::endl;
}
