#include "ScavTrap.hpp"
#include <iostream>

/*
**	Constructor
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
	std::cout << "No...don’t say your goodbyes,<" << this->_name << ">. Don’t you give up. Don’t do it." << std::endl;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const & src): ClapTrap()
{
	*this = src;
	return ;
}
/*
**	operator overloads
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
