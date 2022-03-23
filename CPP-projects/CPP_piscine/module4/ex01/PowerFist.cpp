#include "PowerFist.hpp"
#include <iostream>

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50)
{
	return ;
}

PowerFist::~PowerFist()
{
	return ;
}

PowerFist & PowerFist::operator=(PowerFist const & src)
{
	if (this == &src)
		return (*this);
	setname(src.getname());
	setdamage(src.getdamage());
	setAPcost(src.getAPcost());
	return (*this);
}

PowerFist::PowerFist(PowerFist const & src) : PowerFist::AWeapon(src)
{
	return ;
}

void	PowerFist::attack() const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
