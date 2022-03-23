#include "RadScorpion.hpp"
#include <iostream>

RadScorpion::RadScorpion() : RadScorpion::Enemy("RadScorpion", 80)
{
	std::cout << "* click click click *" << std::endl;
	return ;
}

RadScorpion::~RadScorpion()
{
	std::cout << "* SPROTCH *" << std::endl;
	return ;
}

RadScorpion & RadScorpion::operator=(RadScorpion const & src)
{
	if (this == &src)
		return (*this);
	settype(src.gettype());
	sethp(src.gethp());
	return (*this);
}

RadScorpion::RadScorpion(RadScorpion const &src) : RadScorpion::Enemy(src)
{
}
