/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ex04.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/08 13:19:26 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/08/08 13:58:38 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Stu
{
	private:
		std::string _name;
	public:
		Stu(std::string const& name) : _name(name)
		{}
		~Stu()
		{}
		std::string	&getNameRef()
		{
			return (this->_name);
		}
		
		std::string	*getNamePtr()
		{
			return &(this->_name);
		}
};

int	main()
{
	Stu	alex("HI THIS IS BRAIN");
	std::cout << alex.getNameRef() << " " << *(alex.getNamePtr()) << std::endl;
	return (0);
}
