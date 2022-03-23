/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ex01.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/06 12:05:36 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/08/06 12:40:47 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void memoryLeak()
{
	std::string* panther = new std::string("String panther");
	std::cout << *panther << std::endl;
	delete(panther);
}
