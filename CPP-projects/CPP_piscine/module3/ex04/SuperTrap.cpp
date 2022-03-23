#include "SuperTrap.hpp"

void	SuperTrap::rangedAttack(std::string const & target)
{
	std::cout << "<" << this->_name << "> attacks <" << target << "> at range, causing <" << this->_rangeAttackDamage << "> points of damage!" << std::endl;
}

void	SuperTrap::meleeAttack(std::string const & target)
{
	std::cout << "Bop!" << std::endl;
	std::cout << "<" << this->_name << "> attacks <" << target << "> causing <" << this->_meleeDamage << "> points of damage!" << std::endl;
}

SuperTrap::SuperTrap()
{
	std::cout << "Super trap default constructor called" << std::endl;
}

SuperTrap::SuperTrap(std::string name)
{
	std::cout << "I am the ultimet dude!" << std::endl;
	sethp(100);
	setmaxHp(100);
	seteP(120);
	setmaxEp(120);
	setlevle(1);
	setmeleeDamage(60);
	setrangeAttackDamage(20);
	setarmour(5);
	setname(name);
	return ;
}

SuperTrap::~SuperTrap(void)
{
	std::cout << "No more I be" << std::endl;
	return ;
}

SuperTrap	&SuperTrap::operator=(const SuperTrap &src)
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
