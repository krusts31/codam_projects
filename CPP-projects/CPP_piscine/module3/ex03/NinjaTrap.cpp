#include "NinjaTrap.hpp"
#include <stdlib.h> 
#include <iostream>
#include <string>

NinjaTrap::NinjaTrap(std::string const & name)
{
	sethp(60);
	setmaxHp(60);
	seteP(120);
	setmaxEp(120);
	setlevle(1);
	setmeleeDamage(60);
	setrangeAttackDamage(5);
	setarmour(0);
	setname(name);

	std::cout << "Inner pease and sword!" << std::endl;
	return ;
}
NinjaTrap::~NinjaTrap()
{
	std::cout << "Bushido fails me <" << this->_name << "> dies" << std::endl;
	return ;
}

NinjaTrap & NinjaTrap::operator=(NinjaTrap const & src)
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

NinjaTrap::NinjaTrap(NinjaTrap const & src)
{
	*this = src;
	return ;
}


void	NinjaTrap::ninjaShoebox(ScavTrap& scav)
{
  	std::cout << this->_name << ": I SCAVenge you, " \
			<< scav.getname() << "... I don't even lol" << std::endl;
}

void	NinjaTrap::ninjaShoebox(ClapTrap& clap)
{
	std::cout << this->_name << ": I CLAP to your ignorance, " \
				<< clap.getname() << "..." << std::endl;
}

void	NinjaTrap::ninjaShoebox(FragTrap& frag)
{
	std::cout << this->_name << ": You want a FRAGment of me, " \
				<< frag.getname() << "?" << std::endl;
}

void	NinjaTrap::ninjaShoebox(NinjaTrap& ninja)
{
	std::cout << this->_name << ": I NINJA... fuck this puns. Good luck, "\
	 			<< ninja.getname() << std::endl;
}
