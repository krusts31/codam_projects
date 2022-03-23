#include "Enemy.hpp"
#include <iostream>

Enemy::Enemy(std::string const & type, int hp)
{
	settype(type);
	sethp(hp);
	return ;
}

Enemy::Enemy()
{
	settype("DEFAULT");
	sethp(1);
	return ;
}

Enemy::~Enemy()
{
	return ;
}

Enemy & Enemy::operator=(Enemy const & src)
{
	sethp(src.gethp());
	settype(src.gettype());
	return (*this);
}

Enemy::Enemy(Enemy const & src)
{
	*this = src;
}

void	Enemy::takeDamage(int damage)
{
	if (gethp() - damage <= 0)
	{
		sethp(0);
	}
	else
		sethp(gethp() - damage);
	return ;
}

int		Enemy::gethp(void) const
{
	return (this->_HP);
}

void	Enemy::sethp(unsigned int hp)
{
	this->_HP = hp;
}

std::string	Enemy::gettype(void) const
{
	return (this->_type);
}

void	Enemy::settype(std::string type)
{
	this->_type = type;
}
