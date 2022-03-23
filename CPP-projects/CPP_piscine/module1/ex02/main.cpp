/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/08 09:02:15 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/08/08 10:14:42 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"
#include <iostream>
#include <stdlib.h> 
#include <time.h> 

int	main()
{
	srand(time(0));
	std::string input;
	int index;
	ZombieEvent ZE;
	ZE.setZombieType("default");
	Zombie *test[100000];
	index = 0;

	while (1)
	{
		getline(std::cin, input);
		if (!std::cin.good())
		{
			std::cout << "File descriptore was cosed by typing ctr + d plese restart the program" << std::endl;
			break;
		}
		else if (input == "type" && input.size() == 4)
		{
			getline(std::cin, input);
			if (!std::cin.good())
			{
				std::cout << "File descriptore was cosed by typing ctr + d plese restart the program" << std::endl;
				break;
			}
			ZE.setZombieType(input);
		}
		else if (input == "")
		{
			test[index] = ZE.randomChump();
			index++;
		}
		else if ((input == "KILL" || input == "kill") && input.size() == 4)
			break;
		else
			std::cout << "Can't create zombies" << std::endl;
		if (index > 999998)
			break;
	}
	if (index > 0)
	{
		while (index != -1)
		{
			delete (test[index]);
			index--;
		}
	}
	return (0);
}
