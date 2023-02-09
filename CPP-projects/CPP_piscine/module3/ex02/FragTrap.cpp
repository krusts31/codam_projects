#include "FragTrap.hpp"
#include <stdlib.h> 
#include <iostream>
#include <string>

/*
**	Construcot
*/

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
	std::cout << "R.I.P <" << this->_name << ">" << std::endl;
	return ;
}

FragTrap::FragTrap(FragTrap const & src): ClapTrap()
{
	*this = src;
	return ;
}

/*
**	operator overloads
*/

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

/*
**	member functions
*/

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
