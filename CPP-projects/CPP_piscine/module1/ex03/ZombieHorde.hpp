/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ZombieHorde.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/08 10:39:42 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/08/08 13:18:26 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_EVENT_CLASS_H
# define ZOMBIE_EVENT_CLASS_H
# include <string>
# include "Zombie.hpp"

class ZombieHorde
{
	public:
		ZombieHorde(int N);
		~ZombieHorde();
		void	announce(int N) const;
		void	newHord(int N);
		Zombie	*ZombieH;
};

#endif
