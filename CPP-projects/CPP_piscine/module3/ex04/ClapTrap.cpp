#include "ClapTrap.hpp"
#include <iostream>

/*
**	Construcotrs
*/

ClapTrap::ClapTrap()
{
	std::cout << "I am ClapTrap!" << std::endl;
	sethp(100);
	setmaxHp(100);
	seteP(100);
	setmaxEp(100);
	setlevle(1);
	setmeleeDamage(30);
	setrangeAttackDamage(20);
	setarmour(5);
	setname("Clapinator");

	return ;
}

ClapTrap::~ClapTrap()
{
	std::cout << "R.P.I. in pepperoni <" << this->_name << ">" << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
	*this = src;
	return ;
}

/*
**	operator overloads
*/

ClapTrap & ClapTrap::operator=(ClapTrap const & src)
{
	this->_hP = src.gethp();
	this->_maxHP = src.getmaxHp();
	this->_eP = src.geteP();
	this->_maxEP = src.getmaxEp();
	this->_levle = src.getlevle();
	this->_meleeDamage = src.getmeleeDamage();
	this->_rangeAttackDamage = src.getrangeAttackDamage();
	this->_armour = src.getarmour();
	this->_name = src.getname();
	return (*this);
}

/*
**	Member functions
*/
void	ClapTrap::rangedAttack(std::string const & target)
{
	std::cout << "<" << this->_name << "> attacks <" << target << "> at range, causing <" << this->_rangeAttackDamage << "> points of damage!" << std::endl;
}

void	ClapTrap::meleeAttack(std::string const & target)
{
	std::cout << "Bop!" << std::endl;
	std::cout << "<" << this->_name << "> attacks <" << target << "> causing <" << this->_meleeDamage << "> points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount <= this->_armour)
		std::cout << "All damage was absorbed by armour" << std::endl;
	else if(this->_hP >= amount - this->_armour)
	{
		std::cout << "<" << this->_name << "> takes <" << amount - this->_armour << "> points of damage!" << std::endl;
		this->_hP = this->_hP - (amount - this->_armour);
	}
	else
	{
		this->_hP = 0;
		std::cout << "<" << this->_name << "> Exploded!" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hP == this->_maxHP)
		std::cout << "<" << this->_name << "> has full hp" << std::endl;
	else if (this->_maxHP - this->_hP >= amount)
	{
		std::cout << "Sweet life juice!" << std::endl;
		std::cout << "<" << this->_name << "> repairs <" << amount << "> points of health" << std::endl;
		this->_hP = this->_hP + amount;
		std::cout << "<" << this->_name << "> has <" << this->_hP << "> points of health" << std::endl;
	} else if (this->_maxHP - this->_hP < amount)
	{
		std::cout << "Healsies!" << std::endl;
		std::cout << "<" << this->_name << "> got repaied to <100> points of health, which is the max" << std::endl;
		this->_hP = this->_maxHP;
	}
}

/*
**		Getters and setters
*/

unsigned int	ClapTrap::gethp(void) const
{
	return (this->_hP);
}
void		ClapTrap::sethp(unsigned int hp)
{
	this->_hP = hp;
}

unsigned int	ClapTrap::getmaxHp(void) const
{
	return (this->_maxHP);
}
void		ClapTrap::setmaxHp(unsigned int maxHp)
{
	this->_maxHP = maxHp;
}

unsigned int	ClapTrap::geteP(void) const
{
	return (this->_eP);
}
void		ClapTrap::seteP(unsigned int eP)
{
	this->_eP = eP;
}

unsigned int	ClapTrap::getmaxEp(void) const
{
	return (this->_maxEP);
}
void		ClapTrap::setmaxEp(unsigned int maxEp)
{
	this->_maxEP = maxEp;
}

unsigned int	ClapTrap::getlevle(void) const
{
	return (this->_levle);
}
void		ClapTrap::setlevle(unsigned int levle)
{
	this->_levle = levle;
}

unsigned int	ClapTrap::getmeleeDamage(void) const
{
	return (this->_meleeDamage);
}
void		ClapTrap::setmeleeDamage(unsigned int meleeDamage)
{
	this->_meleeDamage = meleeDamage;
}

unsigned int	ClapTrap::getrangeAttackDamage(void) const
{
	return (this->_rangeAttackDamage);
}
void		ClapTrap::setrangeAttackDamage(unsigned int rangedAttackDamage)
{
	this->_rangeAttackDamage = rangedAttackDamage;
}

unsigned int	ClapTrap::getarmour(void) const
{
	return (this->_armour);
}
void		ClapTrap::setarmour(unsigned int armour)
{
	this->_armour = armour;
}

std::string	ClapTrap::getname(void) const
{
	return (this->_name);
}

void		ClapTrap::setname(std::string name)
{
	this->_name = name;
}
