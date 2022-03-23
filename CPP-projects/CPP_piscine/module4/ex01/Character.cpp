#include "Character.hpp"
#include <iostream>

Character::Character(std::string const & name)
{
	setAP(40);
	setname(name);
	setweapon(NULL);
	return ;
}

Character::~Character()
{
	return ;
}

Character & Character::operator=(Character const & src)
{
	setAP(src.getAP());
	setname(src.getname());
	setweapon(src.getweapon());
	return (*this);
}

int	Character::getAP(void) const
{
	return (this->_AP);
}

void	Character::setAP(unsigned int AP)
{
	this->_AP = AP;
}

std::string	Character::getname(void) const
{
	return (this->_name);
}

void	Character::setname(std::string name)
{
	this->_name = name;
}

AWeapon	*Character::getweapon(void) const
{
	return (this->_weapon);
}

void	Character::setweapon(AWeapon *weapon)
{
	this->_weapon = weapon;
}

void	Character::recoverAP()
{
	if ( getAP() >= 40 )
	{
		std::cout << "Energy FULL!" << std::endl;
		return ;
	}
	else
	{
		std::cout << "You have recived energy points! AWWW YEAH!" << std::endl;
		setAP(getAP() + 10);
	}
}

void	Character::attack(Enemy *enemy)
{
	if (getweapon() == NULL || !enemy)
		return ;
	if ((getAP() < getweapon()->getAPcost()) && (getweapon()->getname() == "Power Fist"))
	{
		std::cout << "Not enough AP for a Power Fist!" << std::endl;
		return ;
	}
	if ((getAP() < getweapon()->getAPcost()) && (getweapon()->getname() == "Plasma Rifle"))
	{
		std::cout << "not enough AP to use a Plasma Rifle" << std::endl;
		return ;
	}
	std::cout << getname() << " attacks " << enemy->gettype() << " with a " << getweapon()->getname() << std::endl;	
	setAP(getAP() - getweapon()->getAPcost());
	getweapon()->attack();
	enemy->takeDamage(getweapon()->getdamage());
	if (enemy->gethp() == 0)
		delete(enemy);
}

void	Character::equip(AWeapon *weapon)
{
	setweapon(weapon);
}

std::ostream &operator<<(std::ostream &out, Character const &src)
{
	out << src.getname() << " has " << src.getAP() << " AP and ";
	if (src.getweapon())
		out << "wields a " << src.getweapon()->getname();
	else
		out << "is unarmed";
	out << std::endl;
	return (out);
}
