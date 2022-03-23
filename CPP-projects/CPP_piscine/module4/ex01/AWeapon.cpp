#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const & name, int apcost, int damage)
{
	setname(name);
	setAPcost(apcost);
	setdamage(damage);
	return ;
}

AWeapon::AWeapon()
{
	setname("deafult");
	setAPcost(9999999);
	setdamage(0);
	return ;
}

AWeapon::~AWeapon()
{
	return ;
}
AWeapon::AWeapon(AWeapon const & src)
{
	*this = src;
}

AWeapon & AWeapon::operator=(AWeapon const & src)
{
	this->_name = src._name;
	this->_damage = src._damage;
	this->_APcost = src._APcost;
	return (*this);
}

/*
**	Getters and Setters
*/

std::string	AWeapon::getname(void) const
{
	return (this->_name);
}

void	AWeapon::setname(std::string name)
{
	this->_name = name;
}

int	AWeapon::getdamage(void) const
{
	return (this->_damage);
}

void	AWeapon::setdamage(unsigned int damage)
{
	this->_damage = damage;
}

int	AWeapon::getAPcost(void) const
{
	return (this->_APcost);
}

void	AWeapon::setAPcost(unsigned int APcost)
{
	this->_APcost = APcost;
}
