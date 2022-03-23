/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/05 18:12:14 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/08/06 12:03:51 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"
#include <iostream>
#include <stdlib.h> 
#include <time.h> 
#include <string>
void	ponyOnTheHeap(void)
{
	std::string	input;
	Pony *pony = new Pony();
	while (pony->getAge() != 30 || (input == "KILL" && input.size() == 4))
	{
		std::getline(std::cin, input);
		if (!std::cin.good())
		{
			break ;
		}
		if (pony->getHunger() != 0 && input == "RUN" && input.size() == 3)
			pony->ponyRun(pony->getColor(), pony->getSize(), pony->getAge());
		else
			std::cout << "Please feed the " << pony->getColor() << ", " << pony->getSize() << " pony" << std::endl;
		if (input == "FEED" && input.size() == 4)
			pony->ponyEat(pony->getColor(), pony->getSize(), pony->getAge());
		if (input == "KILL" && input.size() == 4)
			break;
	}
	delete(pony);
}
void	ponyOnTheStack(void)
{
	std::string	input;
	Pony pony;
	while (pony.getAge() != 30 || (input == "KILL" && input.size() == 4))
	{
		std::getline(std::cin, input);
		if (!std::cin.good())
		{
			std::cout << "A " << pony.getSize() << ", " << pony.getColor() << " Pony died at age "<< pony.getAge() << "with a hearth attack, he is in better place now" << std::endl;
			break ;
		}
		if (pony.getHunger() != 0 && input == "RUN" && input.size() == 3)
			pony.ponyRun(pony.getColor(), pony.getSize(), pony.getAge());
		else
			std::cout << "Please feed the " << pony.getColor() << ", " << pony.getSize() << " pony" << std::endl;
		if (input == "FEED" && input.size() == 4)
			pony.ponyEat(pony.getColor(), pony.getSize(), pony.getAge());
		if (input == "KILL" && input.size() == 4)
			break;
	}
}

int	main()
{
	srand(time(0));
	ponyOnTheHeap();
	ponyOnTheStack();
	return (0);
}
