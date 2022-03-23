/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Pony.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/05 18:13:59 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/08/06 11:21:02 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_CLASS
# define PONY_CLASS
# include <iostream>
# include <string>
class Pony
{

public:
/*
**			Constructor
*/
	Pony(void);
/*
**			Deconstrucot
*/
	~Pony(void);
/*
**			Member functions
*/
	void	ponyRun(std::string color, std::string size, int age);
	void	ponyEat(std::string color, std::string size, int age);
/*
**			Setters
*/	
	void	setColor(int color);
	void	setAge(int age);
	void	setSize(int size);
	void	setHunger(int hunger);
/*
**			Getters
*/
	std::string	getSize(void)	const;
	std::string getColor(void)	const;
	int			getHunger(void)	const;
	int			getAge(void)	const;
/*
**			Varibles
*/
private:
/*
**			Varibles
*/
	const static std::string color[10];
	const static std::string size[4];
	int			_hunger;
	std::string	_color;
	int			_age;
	std::string	_size;
};

#endif
