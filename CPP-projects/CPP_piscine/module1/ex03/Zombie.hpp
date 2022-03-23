/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/08 07:58:28 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/08/08 12:36:27 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_CLASS_H
# define ZOMBIE_CLASS_H
# include <string>

class Zombie
{
	public:

		Zombie();
		~Zombie();
		void		setName(std::string name);
		void		setType(std::string type);
		std::string	getName(void) const;
		std::string	 getType(void) const;
		void		announce(void) const;

	private:

		std::string _name;
		std::string _type;	

};

#endif
