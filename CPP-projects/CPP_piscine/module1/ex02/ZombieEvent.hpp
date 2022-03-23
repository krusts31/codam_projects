/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ZombieEvent.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/08 08:35:54 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/08/08 10:11:59 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_EVENT_CLASS_H
# define ZOMBIE_EVENT_CLASS_H
# include "Zombie.hpp"
# include <stdlib.h>

class ZombieEvent
{
	public:
		ZombieEvent();
		~ZombieEvent();

		void	setZombieType(std::string type);
		Zombie	*randomChump(void);
		const static std::string names[12];
		std::string	randomName(void);

	private:
		std::string	_type;
};

#endif
