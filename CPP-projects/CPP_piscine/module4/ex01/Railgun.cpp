#include "Railgun.hpp"
#include <iostream>
Railgun::Railgun() : AWeapon("Rail gun", 3, 15)
{
	return ;
}
Railgun::~Railgun()
{
	return ;
}

Railgun::Railgun(Railgun const & src) : AWeapon(src)
{
	return ;
}

Railgun & Railgun::operator=(Railgun const & src)
{
	if (this == &src)
		return (*this);
	setname(src.getname());
	setdamage(src.getdamage());
	setAPcost(src.getAPcost());
	return (*this);
}

void	Railgun::attack() const
{
	std::cout << "* Bang *" << std::endl;
}
//	cool vim comand hold shit. pres v relese pres u relese
