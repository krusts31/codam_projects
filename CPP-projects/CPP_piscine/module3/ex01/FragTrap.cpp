#include "FragTrap.hpp"
#include <stdlib.h> 
#include <iostream>
#include <string>

FragTrap::FragTrap()
{
	std::cout << "Hey, best friend!" << std::endl;
	sethp(100);
	setmaxHp(100);
	seteP(100);
	setmaxEp(100);
	setlevle(1);
	setmeleeDamage(30);
	setrangeAttackDamage(20);
	setarmour(5);
	setname("FR4F-TP");

	return ;
}
FragTrap::~FragTrap()
{
	std::cout << "R.I.P. <" << this->_name << ">" << std::endl;
	return ;
}

FragTrap & FragTrap::operator=(FragTrap const & src)
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

FragTrap::FragTrap(FragTrap const & src)
{
	*this = src;
	return ;
}

void	FragTrap::headBut(std::string const & target)
{
	std::cout << "<" << this->_name << "> hits <" << target << "> with his head causing <" << this->_meleeDamage << "> points of damage!" << std::endl;
}
void	FragTrap::klinch(std::string const & target)
{
	std::cout << "<" << this->_name << "> klinches with<" << target << "> /I got him Boss!/"  << std::endl;
}
void	FragTrap::hug(std::string const & target)
{
	std::cout << "<" << this->_name << "> hugs <" << target << "> /Psst! Ad-ass-bay, over ere-bay!/"  << std::endl;
}

void	FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	if (this->_eP >= 25)
	{
		this->_eP = this->_eP - 25;
		static int randNr;

		randNr = rand() % 5;
		void (FragTrap:: *acctions[5])(std::string const & target) =
		{
			&FragTrap::rangedAttack,
			&FragTrap::meleeAttack,
			&FragTrap::headBut,
			&FragTrap::klinch,
			&FragTrap::hug
		};
		(this->*acctions[randNr])(target);
	}
	else
		std::cout << "Frigid! <" << this->_name << "> is out of Energy" << std::endl;
}


void	FragTrap::rangedAttack(std::string const & target)
{
	std::cout << "<" << this->_name << "> attacks <" << target << "> at range, causing <" << this->_rangeAttackDamage << "> points of damage!" << std::endl;
}

void	FragTrap::meleeAttack(std::string const & target)
{
	std::cout << "Bop!" << std::endl;
	std::cout << "<" << this->_name << "> attacks <" << target << "> causing <" << this->_meleeDamage << "> points of damage!" << std::endl;
}

void	FragTrap::energyPack(unsigned int amount)
{
	if (this->_eP == this->_maxEP)
		std::cout << "<" << this->_name << "> has max EP" << std::endl;
	else if (this->_maxEP - this->_eP >= amount)
	{
		std::cout << "I got the POWA!" << std::endl;
		std::cout << "<" << this->_name << "> regains energy <" << amount << "> points of energy" << std::endl;
		this->_eP = this->_eP + amount;
		std::cout << "<" << this->_name << "> has <" << this->_eP << "> points of energy" << std::endl;
	} else if (this->_maxEP - this->_eP < amount)
	{
		std::cout << "I feel the power!" << std::endl;
		std::cout << "<" << this->_name << "> got enegized to <" << this->_maxEP << "> points of energy, which is the max" << std::endl;
		this->_eP = this->_maxEP;
	}
}

void	FragTrap::takeDamage(unsigned int amount)
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

void	FragTrap::beRepaired(unsigned int amount)
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

unsigned int	FragTrap::gethp(void) const
{
	return (this->_hP);
}
void		FragTrap::sethp(unsigned int hp)
{
	this->_hP = hp;
}

unsigned int	FragTrap::getmaxHp(void) const
{
	return (this->_maxHP);
}
void		FragTrap::setmaxHp(unsigned int maxHp)
{
	this->_maxHP = maxHp;
}

unsigned int	FragTrap::geteP(void) const
{
	return (this->_eP);
}
void		FragTrap::seteP(unsigned int eP)
{
	this->_eP = eP;
}

unsigned int	FragTrap::getmaxEp(void) const
{
	return (this->_maxEP);
}
void		FragTrap::setmaxEp(unsigned int maxEp)
{
	this->_maxEP = maxEp;
}

unsigned int	FragTrap::getlevle(void) const
{
	return (this->_levle);
}
void		FragTrap::setlevle(unsigned int levle)
{
	this->_levle = levle;
}

unsigned int	FragTrap::getmeleeDamage(void) const
{
	return (this->_meleeDamage);
}
void		FragTrap::setmeleeDamage(unsigned int meleeDamage)
{
	this->_meleeDamage = meleeDamage;
}

unsigned int	FragTrap::getrangeAttackDamage(void) const
{
	return (this->_rangeAttackDamage);
}
void		FragTrap::setrangeAttackDamage(unsigned int rangedAttackDamage)
{
	this->_rangeAttackDamage = rangedAttackDamage;
}

unsigned int	FragTrap::getarmour(void) const
{
	return (this->_armour);
}
void		FragTrap::setarmour(unsigned int armour)
{
	this->_armour = armour;
}

std::string	FragTrap::getname(void) const
{
	return (this->_name);
}

void		FragTrap::setname(std::string name)
{
	this->_name = name;
}

//end of get set
