/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Pony.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/05 18:14:20 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/08/06 12:03:54 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <stdlib.h>
#include <iostream>
#include "Pony.hpp"

/*
**			Varibles
*/
const 	std::string Pony::color[10] = {"brown", "yellow", "pink", "orange", "blue", "green", "red", "black", "withe", "grey"};
const	std::string Pony::size[4] = {"small", "avrage", "large", "huge"};
/*
**			Constructor
*/
Pony::Pony(void)
{
	int	indexColor;
	int indexSize;
	indexColor = rand() % 9 + 1;
	indexSize = rand() % 3 + 1;
	setHunger(5);
	setSize(indexSize);
	setColor(indexColor);
	setAge(1);
	std::cout << getSize() << ", " << getColor() << " pony" << " was born!" << std::endl;
}
/*
**			Deconstrucor
*/
Pony::~Pony(void)
{
	std::cout << "A " << getSize() << ", " << getColor() << " Pony died at age "<< getAge() << std::endl;
	return ;
}
/*
**			Member functions
*/
void	Pony::ponyRun(std::string color, std::string size, int age)
{
	std::cout << "A " << color << ", " << size << " " << "pony" << " is runnning" << " at age " << age <<  std::endl;
	this->_age++;
	this->_hunger--;
}
void	Pony::ponyEat(std::string color, std::string size, int age)
{
	std::cout << "A " << color << ", " << size << " " << "pony" << " is eatting"  << " at age "<<  age << std::endl;
	this->_hunger = 5;
}
/*
**			Getters
*/
int			Pony::getHunger(void) const
{
	return (this->_hunger);
}
std::string	Pony::getSize(void) const
{
	return (this->_size);
}
std::string Pony::getColor(void) const
{
	return (this->_color);
}
int			Pony::getAge(void) const
{
	return (this->_age);
}
/*
**			Setters
*/
void	Pony::setHunger(int hunger)
{
	this->_hunger = hunger;
}
void	Pony::setAge(int age)
{
	this->_age = age;
}
void	Pony::setColor(int index)
{
	this->_color = this->color[index];
}
void	Pony::setSize(int index)
{
	this->_size = this->size[index];
}
