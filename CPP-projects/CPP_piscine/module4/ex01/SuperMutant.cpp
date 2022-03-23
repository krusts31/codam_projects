#include "SuperMutant.hpp"
#include <iostream>

SuperMutant::SuperMutant() : SuperMutant::Enemy("Super Mutant", 170)
{
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
	return ;
}

SuperMutant::~SuperMutant()
{
	std::cout << "*Aaaargh...*" << std::endl;
	return ;
}

SuperMutant & SuperMutant::operator=(SuperMutant const & src) 
{
	settype(src.gettype());
	sethp(src.gethp());
	return (*this);
}

SuperMutant::SuperMutant(SuperMutant const & src) : SuperMutant::Enemy(src)
{
	return ;
}

void	SuperMutant::takeDamage(int damage)
{
	if (damage <= 3)
		return ;
	Enemy::takeDamage(damage - 3);
}
