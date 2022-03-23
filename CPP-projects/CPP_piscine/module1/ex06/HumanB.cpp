#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>

HumanB::HumanB(std::string name) : _name(name)
{
	return ;
}

HumanB::~HumanB()
{
	return ;
}

std::string	HumanB::getName() const
{
	return (this->_name);
}

void		HumanB::setName(std::string name)
{
	this->_name = name;
}

void		HumanB::attack() const
{
	std::cout << getName() << " attacks with his " << this->_weapon->getType() << std::endl;
}

void		HumanB::setWeapon(Weapon & weapon)
{
	this->_weapon = &weapon;
}
