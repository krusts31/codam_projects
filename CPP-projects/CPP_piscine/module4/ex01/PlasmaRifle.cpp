#include "PlasmaRifle.hpp"
#include <iostream>
PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21)
{
	return ;
}
PlasmaRifle::~PlasmaRifle()
{
	return ;
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const & src) : AWeapon(src)
{
	return ;
}

PlasmaRifle & PlasmaRifle::operator=(PlasmaRifle const & src)
{
	if (this == &src)
		return (*this);
	setname(src.getname());
	setdamage(src.getdamage());
	setAPcost(src.getAPcost());
	return (*this);
}

void	PlasmaRifle::attack() const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}

