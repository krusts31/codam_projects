#include "Character.hpp"

Character::Character()
{
	return ;
}

Character::Character(const std::string & name) : _name(name)
{
	this->_index = 0;
	this->_inventory[0] = NULL;
	this->_inventory[1] = NULL;
	this->_inventory[2] = NULL;
	this->_inventory[3] = NULL;
	return ;
}

Character::~Character()
{
	for (int i = 0; i != 4; i++)
	{
		if (this->_inventory[i] != NULL)
		{
			delete (this->_inventory[i]);
			this->_inventory[i] = NULL;
		}
	}
	return ;
}

Character & Character::operator=(Character const & src)
{
	if (this == &src)
		return (*this);
	this->_name = src._name;
	this->_index = src._index;
	for (int i = 0; i != 4; i++)
	{
		if (this->_inventory[i] != NULL)
		{
			delete (this->_inventory[i]);
			this->_inventory[i] = NULL;
		}
		if (src._inventory[i] == NULL)
			this->_inventory[i] = NULL;
		else
		{
			if (src._inventory[i] != NULL)
				this->_inventory[i] = src._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	}
	return (*this);
}

Character::Character(Character const & src)
{
	this->_inventory[0] = NULL;
	this->_inventory[1] = NULL;
	this->_inventory[2] = NULL;
	this->_inventory[3] = NULL;
	this->_name = src._name;
	this->_index = src._index;
	for (int i = 0; i != 4; i++)
	{
		this->_inventory[i] = src._inventory[i]->clone();
	}
}

void	Character::equip(AMateria *m)
{
	if (m == NULL)
	{
		std::cout << "Can't equir nothing" << std::endl;
		return ;
	}
	if (this->_index < 4)
	{
		this->_inventory[this->_index] = m;
		this->_index++;
	}
	return ;
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3)
	{
		this->_inventory[idx] = NULL;
		this->_index--;
	}
	return ;
}

void	Character::use(int idx, ICharacter & target)
{
	if (idx < 0 || idx > 4)
	{
		std::cout << "Invetory slots are limited to 0, 1, 2 ,3" << std::endl;
		return ;
	}
	if (this-> _inventory[idx] == NULL)
	{
		std::cout << "In this inventroy slots there is nothing equpied " << std::endl;
		return ;
	}
	this->_inventory[idx]->use(target);
	this->_inventory[idx]->addXP();
}

std::string	const & Character::getName() const
{
	return (this->_name);
}
