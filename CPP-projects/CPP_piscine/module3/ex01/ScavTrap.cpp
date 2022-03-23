#include "ScavTrap.hpp"
#include <iostream>

/*
** Constructors
*/

ScavTrap::ScavTrap(std::string const & name)
{
	std::cout << "Serena, my love!" << std::endl;
	sethp(100);
	setmaxHp(100);
	seteP(50);
	setmaxEp(50);
	setlevle(1);
	setmeleeDamage(20);
	setrangeAttackDamage(15);
	setarmour(3);
	setname(name);
	return ;
}
ScavTrap::~ScavTrap()
{
	std::cout << "R.I.P <" << this->_name << ">" << std::endl;
	return ;
}
ScavTrap::ScavTrap(ScavTrap const & src)
{
	*this = src;
	return ;
}

/*
**	operator overload
*/

ScavTrap & ScavTrap::operator=(ScavTrap const & src)
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

void	ScavTrap::lionRidle()
{
	std::string input;
	std::cout << "A murderer is condemned to death!" << std::endl;
	std::cout << "He has to choos between three rooms:" << std::endl;
	std::cout << "The first is full of raging fires!" << std::endl;
	std::cout << "The seccond, assassins with loaded guns!" << std::endl;
	std::cout << "The thrid, lions who have not eaten in years" << std::endl;
	std::cout << "Which room is the safest, 1, 2 ,3?" << std::endl;
	while(1)
	{
		std::getline(std::cin, input);
		if (!std::cin.good())
		{
			std::cout << "Nice try!" << std::endl;
			break ;
		}
		if (gethp() == 0)
			break ;
		if (input == "3" && input.size() == 3)
		{
			beRepaired(50);
			break ;
		} else
			takeDamage(25);
	}
}

void	ScavTrap::mapRidle()
{
	std::string input;
	std::cout << "I have cities but no houses" << std::endl;
	std::cout << "I have moutains but no trees" << std::endl;
	std::cout << "I have water, but no fished" << std::endl;
	std::cout << "what am I?" << std::endl;
	while(1)
	{
		std::getline(std::cin, input);
		if (!std::cin.good())
		{
			std::cout << "Nice try!" << std::endl;
			break ;
		}
		if (gethp() == 0)
			break ;
		if (input == "map" && input.size() == 3)
		{
			beRepaired(50);
			break ;
		}
		else
			takeDamage(25);
	}
}

void	ScavTrap::towleRidle()
{
	std::string input;
	std::cout << "What gets wet while drying?" << std::endl;
	while(1)
	{
		std::getline(std::cin, input);
		if (!std::cin.good())
		{
			std::cout << "Nice try!" << std::endl;
			break ;
		}
		if (gethp() == 0)
			break ;
		if (input == "towel" && input.size() == 5)
		{
			beRepaired(50);
			break ;
		}
		else
			takeDamage(25);
	}
}
void	ScavTrap::fishhookRidle()
{
	std::string input;
	std::cout << "First you eat me then you get eaten" << std::endl;
	while(1)
	{
		std::getline(std::cin, input);
		if (!std::cin.good())
		{
			std::cout << "Nice try!" << std::endl;
			break ;
		}
		if (gethp() == 0)
			break ;
		if (input == "fishhook" && input.size() == 8)
		{
			beRepaired(50);
			break ;
		}
		else
			takeDamage(25);
	}
}
void	ScavTrap::INOCRidle()
{
	std::string input;
	std::cout << "Which word in the dictionary is always spelled incorrectly?" << std::endl;
	while(1)
	{
		std::getline(std::cin, input);
		if (!std::cin.good())
		{
			std::cout << "Nice try!" << std::endl;
			break ;
		}
		if (gethp() == 0)
			break ;
		if (input == "incorrectly" && input.size() == 11)
		{
			beRepaired(50);
			break ;
		}
		else
			takeDamage(25);
	}
}

void	ScavTrap::challengeNewcomer()
{
	static int randNr;

	randNr = rand() % 5;
	void (ScavTrap:: *acctions[5])(void) =
	{
		&ScavTrap::lionRidle,
		&ScavTrap::mapRidle,
		&ScavTrap::fishhookRidle,
		&ScavTrap::towleRidle,
		&ScavTrap::INOCRidle
	};
	(this->*acctions[randNr])();
}

void	ScavTrap::rangedAttack(std::string const & target)
{
	std::cout << "<" << this->_name << "> attacks <" << target << "> at range, causing <" << this->_rangeAttackDamage << "> points of damage!" << std::endl;
}

void	ScavTrap::meleeAttack(std::string const & target)
{
	std::cout << "Bop!" << std::endl;
	std::cout << "<" << this->_name << "> attacks <" << target << "> causing <" << this->_meleeDamage << "> points of damage!" << std::endl;
}

void	ScavTrap::energyPack(unsigned int amount)
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

void	ScavTrap::takeDamage(unsigned int amount)
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

void	ScavTrap::beRepaired(unsigned int amount)
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

unsigned int	ScavTrap::gethp(void) const
{
	return (this->_hP);
}
void		ScavTrap::sethp(unsigned int hp)
{
	this->_hP = hp;
}

unsigned int	ScavTrap::getmaxHp(void) const
{
	return (this->_maxHP);
}
void		ScavTrap::setmaxHp(unsigned int maxHp)
{
	this->_maxHP = maxHp;
}

unsigned int	ScavTrap::geteP(void) const
{
	return (this->_eP);
}
void		ScavTrap::seteP(unsigned int eP)
{
	this->_eP = eP;
}

unsigned int	ScavTrap::getmaxEp(void) const
{
	return (this->_maxEP);
}
void		ScavTrap::setmaxEp(unsigned int maxEp)
{
	this->_maxEP = maxEp;
}

unsigned int	ScavTrap::getlevle(void) const
{
	return (this->_levle);
}
void		ScavTrap::setlevle(unsigned int levle)
{
	this->_levle = levle;
}

unsigned int	ScavTrap::getmeleeDamage(void) const
{
	return (this->_meleeDamage);
}
void		ScavTrap::setmeleeDamage(unsigned int meleeDamage)
{
	this->_meleeDamage = meleeDamage;
}

unsigned int	ScavTrap::getrangeAttackDamage(void) const
{
	return (this->_rangeAttackDamage);
}
void		ScavTrap::setrangeAttackDamage(unsigned int rangedAttackDamage)
{
	this->_rangeAttackDamage = rangedAttackDamage;
}

unsigned int	ScavTrap::getarmour(void) const
{
	return (this->_armour);
}
void		ScavTrap::setarmour(unsigned int armour)
{
	this->_armour = armour;
}

std::string	ScavTrap::getname(void) const
{
	return (this->_name);
}

void		ScavTrap::setname(std::string name)
{
	this->_name = name;
}

