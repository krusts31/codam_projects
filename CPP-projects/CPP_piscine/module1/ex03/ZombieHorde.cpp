/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ZombieHorde.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/08 08:43:20 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/08/08 13:18:29 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"
#include <string>
#include <iostream>
#include <stdlib.h>

ZombieHorde::ZombieHorde(int N)
{
	std::cout << "The Zombie hord makes it self know" << std::endl;
	ZombieH = new Zombie[N];
	newHord(N);
	return ;
}

ZombieHorde::~ZombieHorde()
{
	std::cout << "The zombie hord has been defeted" << std::endl;
	delete[] this->ZombieH;
	return ;
}

void	ZombieHorde::newHord(int N)
{
	int randNr;
	std::string names[12] = {"Joe", "Elon", "Rick", "Duff man", "Paul", "Homer", "Kartmen", "Dunken", "Alex", "Kandy", "Sue", "Elton"};
	N--;
	while (N > -1)
	{
		randNr = rand() % 11 + 1;
		this->ZombieH[N].setName(names[randNr]);
		this->ZombieH[N].setType("(hord)");
		N--;
	}
}

void	ZombieHorde::announce(int N) const
{
	N--;
	while (N > -1)
	{
		ZombieH[N].announce();
		N--;
	}
}
