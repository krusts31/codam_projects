/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/08 09:02:15 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/08/08 13:18:31 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieHorde.hpp"
#include <stdlib.h> 
#include <time.h> 

int	main()
{
	srand(time(0));
	int	N;
	N = 4;
	ZombieHorde ZH(N);
	ZH.announce(N);
	return (0);
}
