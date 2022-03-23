#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>

HumanA::HumanA(std::string name, Weapon & weapon) : _name(name), _weapon(weapon)
{
	return ;
}

HumanA::~HumanA()
{
	return ;
}

std::string	HumanA::getName() const
{
	return (this->_name);
}

void		HumanA::setName(std::string name)
{
	this->_name = name;
}

void	HumanA::attack() const
{
	std::cout << getName() << " attacks with his " << _weapon.getType() << std::endl;
}
