/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/08 08:09:01 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/08/08 13:18:24 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie()
{
	return ;
}
Zombie::~Zombie()
{
	std::cout << getName() << " " << getType() << " was shot in the face" << std::endl;
	return ;
}

void		Zombie::setName(std::string name)
{
	this->_name = name;
}

void		Zombie::setType(std::string type)
{
	this->_type = type;
}

std::string	Zombie::getName(void) const
{
	return (this->_name);
}

std::string Zombie::getType(void) const
{
	return (this->_type);
}

void		Zombie::announce(void) const
{
	std::cout << getName() << " " << getType() << " Brainssssssss" << std::endl;
}
