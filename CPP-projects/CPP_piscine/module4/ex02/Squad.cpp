#include "Squad.hpp"
#include <iostream>
Squad::Squad()
{
	return ;
}

Squad::~Squad()
{
	deleteMar();
	return ;
}

Squad::Squad(Squad const & src)
{
	*this = src;
}

Squad & Squad::operator=(Squad const & src)
{
	int	index;
	ISpaceMarine	*man;
	index = 0;
	if (this != &src)
	{
		deleteMar();
		while (index != src.getCount())
		{
			man = src.getUnit(index);
			man = man->clone();
			push(man);
			index++;
		}
	}
	return (*this);
}

ISpaceMarine	*Squad::getUnit(int N) const
{
	t_container	*forUse;
	int		index;

	if (N < 0)
		return (NULL);
	forUse = this->_marines;
	index = 0;
	while (forUse != NULL)
	{
		if (index == N)
			return (forUse->unit);
		forUse = forUse->next;
		index++;
	}
	return (NULL);
}

int	Squad::getCount() const
{
	t_container	*forUse;
	int		count;

	forUse = this->_marines;
	count = 0;
	while (forUse != NULL)
	{	
		forUse = forUse->next;
		count++;
	}
	return (count);
}

int	Squad::push(ISpaceMarine *unit)
{
	t_container	*forUse;

	forUse = this->_marines;
	if (unit != NULL && Original(unit, forUse) == true)
	{
		if (this->_marines != NULL)
		{
			while (forUse->next)
				forUse = forUse->next;
			forUse->next = new t_container;
			forUse->next->unit = unit;
			forUse->next->next = NULL;
		}
		else
		{
			this->_marines = new t_container;
			this->_marines->unit = unit;
			this->_marines->next = NULL;
		}
	}
	return (getCount());
}

bool	Squad::Original(ISpaceMarine *unit, t_container *forUse) const
{
	if (forUse == NULL)
		return (true);
	else if (unit == forUse->unit)
		return (false);
	else
		return (Original(unit, forUse->next));
}

void	Squad::deleteMar()
{
	t_container	*tmp;

	while (this->_marines)
	{
		delete (this->_marines->unit);
		tmp = this->_marines->next;
		delete (this->_marines);
		this->_marines = tmp;
	}
	this->_marines = NULL;
	return ;
}
