/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ZombieEvent.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/08 08:43:20 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/08/08 10:14:35 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"
#include <iostream>

const std::string ZombieEvent::names[12] = {"Joe", "Elon", "Rick", "Duff man", "Paul", "Homer", "Kartmen", "Dunken", "Alex", "Kandy", "Sue", "Elton"};

ZombieEvent::ZombieEvent()
{
	std::cout << "The zombie event has started. You can now raise THE DEAD" << std::endl;
	this->_type = "";
	return ;
}

ZombieEvent::~ZombieEvent()
{
	std::cout << "The zombie event is over. The zombies have been defeted" << std::endl;
	return ;
}

void	ZombieEvent::setZombieType(std::string type)
{
	this->_type = type;
}

Zombie	*ZombieEvent::randomChump(void)
{
	Zombie *zombie;

	zombie = new Zombie(this->_type, randomName());
	zombie->announce();
	return (zombie);
}

std::string	ZombieEvent::randomName()
{
	static int randNr;
	randNr = rand() % 11;
	return (names[randNr]);
}

