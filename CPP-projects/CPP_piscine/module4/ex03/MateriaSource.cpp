#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	this->_index = 0;
	_inventory[0] = NULL;
	_inventory[1] = NULL;
	_inventory[2] = NULL;
	_inventory[3] = NULL;
	return ;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i != 4; i++)
	{
		if(this->_inventory[i] != NULL)
		{
			delete(this->_inventory[i]);
			this->_inventory[i] = NULL;
		}
	}	
	return ;
}

MateriaSource::MateriaSource(MateriaSource const & src)
{
	this->_index = 0;
	_inventory[0] = NULL;
	_inventory[1] = NULL;
	_inventory[2] = NULL;
	_inventory[3] = NULL;
	*this = src;
	return ;
}

MateriaSource & MateriaSource::operator=(const MateriaSource & src)
{
	if (this == &src)
		return (*this);
	for (int i = 0; i != 4; i++)
	{
		if (this->_inventory[i] != NULL)
		{
			delete (this->_inventory[i]);	//this crashes the programm
			this->_inventory[i] = NULL;
		}
		this->_inventory[i] = src._inventory[i]->clone();
	}
	this->_index = src._index;
	return (*this);
}

void		MateriaSource::learnMateria(AMateria *src)
{
	if (this->_index < 4)
	{
		this->_inventory[this->_index] = src;
		this->_index++;
		return ;
	}
	delete(src);
	src = NULL;
}
AMateria	*MateriaSource::createMateria(std::string const & type)
{
	AMateria	*ret;
	if (type == "ice")
	{
		for (int i = 0; i !=4; i++)
		{
			if (this->_inventory[i] != NULL)
			{
				if (this->_inventory[i]->getType() == "ice") 
				{
					ret = this->_inventory[i]->clone();	
					return (ret);
				}
			}
		}
		std::cout << "YOU still have not learned the mysterys of the" << \
			" spell of *ice bolt*" << std::endl;
	}
	if (type == "cure")
	{
		for (int i = 0; i !=4; i++)
		{
			if (this->_inventory[i] != NULL ) 
			{
				if (this->_inventory[i]->getType() == "cure" ) 
				{
					ret = this->_inventory[i]->clone();	
					return (ret);
				}
			}
		}
		std::cout << "YOU still have not learned the mysterys of the" << \
			" spell of *cure*" << std::endl;
	}
	return (NULL);
}
