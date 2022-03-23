/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/28 18:06:03 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/08/05 17:42:10 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "info.class.hpp"
#include "contact.class.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>

void	set_up_table()
{
	std::cout << "     INDEX| FIRSTNAME|  LASTNAME|  NICKNAME|" << std::endl;
}

std::string	ft_format(std::string output)
{
	unsigned long strlen;

	strlen = output.size();
	if (strlen > 10)
		strlen = 10;
	output.insert(0, 10 - strlen, ' ');
	if (strlen == 10)
		output.insert(9, ".");
	output.resize(10);
	output.insert(10, "|");

	return (output);
}

int	main()
{
	int	index;
	int _index;
	int	i;
	i = 0;
	index = 0;
	_index = 1;

/*
**	data for Contact Class
*/
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	login;
	std::string	postal_address;
	std::string	email;
	std::string	address;
	std::string	phone_number;
	std::string	birthday;
	std::string	favorite_meal;
	std::string	underwaer_color;
	std::string	darkest_secret;

	info phonebook;
	phonebook.set_empty_contact();
	std::string	entered_value;
/*
**					Will run till user inputs EXIT
*/
	while (1)
	{
/*
**					Program tells user what are the input options
*/
		if (index != 8)
			std::cout << "OPTIONS: ADD a contact" << std::endl;
		else
			std::cout << "OPTION ADD NOT POSSIBLE!" << std::endl;
		std::cout << "OPTIONS: EXIT" << std::endl;
		if (index != 0)
			std::cout << "OPTIONS: SEARCH " << std::endl;
		std::getline (std::cin, entered_value);
/*
**					EXIT will exit the programm
*/

		if (!entered_value.find("EXIT") && entered_value.size() == 4)
			return (0);

/*
**					ADD will add a contact to phonebook
*/

		if (!entered_value.find("ADD") && entered_value.size() == 3 && index != 8)
		{
			std::cout << "enter your first name" << std::endl;
			std::getline (std::cin, first_name);
			std::cout << "enter your last name" << std::endl;
			std::getline (std::cin, last_name);
			std::cout << "enter your nick name" << std::endl;
			std::getline (std::cin, nickname);
			std::cout << "enter your login" << std::endl;
			std::getline (std::cin, login);
			std::cout << "enter youe postal address" << std::endl;
			std::getline (std::cin, postal_address);
			std::cout << "enter your email" << std::endl;
			std::getline (std::cin, email);
			std::cout << "enter your address" << std::endl;
			std::getline (std::cin, address);
			std::cout << "enter your phone number" << std::endl;
			std::getline (std::cin, phone_number);
			std::cout << "enter your birth day" << std::endl;
			std::getline (std::cin, birthday);
			std::cout << "enter your favorite meal" << std::endl;
			std::getline (std::cin, favorite_meal);
			std::cout << "enter your underwear collor" << std::endl;
			std::getline (std::cin, underwaer_color);
			std::cout << "enter your darkest secret" << std::endl;
			std::getline (std::cin, darkest_secret);
			if (first_name == "" && last_name == "" && nickname == "" && login == "" && postal_address == "" && email == "" && address == "" && phone_number == "" && birthday == "" && favorite_meal == "" && underwaer_color == ""&& darkest_secret == "")
				std::cout << "Enter contact was not added to the phonebook, because it is empty" << std::endl;
			else
			{
				phonebook.add_contact(index, _index, first_name, last_name, nickname, login, postal_address, email, address, phone_number, birthday, favorite_meal, underwaer_color, darkest_secret);
				_index++;
				index++;
			}
		}

/*
**				SEARCH will display enter contacts
*/

		if (!entered_value.find("SEARCH") && entered_value.size() == 6 && index != 0)
		{
			i = 0;
			set_up_table();
			while (i != 8)
			{	
				first_name =  phonebook._contact[i].get_first_name();
				last_name = phonebook._contact[i].get_last_name();
				nickname = phonebook._contact[i].get_nickname();
				favorite_meal = phonebook._contact[i].get_favorite_meal();
				underwaer_color = phonebook._contact[i].get_underwaer_color();
				darkest_secret = phonebook._contact[i].get_darkest_secret();
				birthday = phonebook._contact[i].get_birthday();
				phone_number = phonebook._contact[i].get_phone_number();
				address = phonebook._contact[i].get_address();
				email = phonebook._contact[i].get_email();
				postal_address = phonebook._contact[i].get_postal_address();
				login = phonebook._contact[i].get_login();
				if ((phonebook._contact[i].get_index() > 0) && (first_name != "" || last_name != "" || nickname != "" || login != "" || postal_address != "" || email != "" || address != "" || phone_number != "" || birthday != "" || favorite_meal != "" || underwaer_color != "" || darkest_secret != ""))
				{
					std::cout << "         " << phonebook._contact[i].get_index() << "|";
					std::cout << ft_format(first_name);
					std::cout << ft_format(last_name);
					std::cout << ft_format(nickname) << std::endl;
				}
				i++;
			}
			std::cout << "OPTIONS: Enter a index of a contact to get extra details of the index contact EXIT" << std::endl;
			std::cout << "OPTIONS: EXIT" << std::endl;
			std::cout << "OPTIONS: hit enter for more options" << std::endl;
			std::getline (std::cin, entered_value);
			if (entered_value == "EXIT" && entered_value.size() == 4)
				return (0);
			i = atoi(entered_value.c_str()) - 1;
			if (i >= 0 && i <= 7)
			{
				if (phonebook._contact[i].get_index() > 0)
				{
					std::cout << "INDEX           :" << phonebook._contact[i].get_index() << std::endl;
					std::cout << "FIRSTNAME       :" << phonebook._contact[i].get_first_name() << std::endl;
					std::cout << "LASTNAME        :" << phonebook._contact[i].get_last_name() << std::endl;
					std::cout << "NICKNAME        :" << phonebook._contact[i].get_nickname() << std::endl;
					std::cout << "LOGIN           :" << phonebook._contact[i].get_login() << std::endl;
					std::cout << "POSTAL ADDRESS  :" << phonebook._contact[i].get_postal_address() << std::endl;
					std::cout << "EMAIL           :" << phonebook._contact[i].get_email() << std::endl;
					std::cout << "ADDRESS         :" << phonebook._contact[i].get_address() << std::endl;
					std::cout << "PHONE NUMBER    :" << phonebook._contact[i].get_phone_number() << std::endl;
					std::cout << "BIRTHDAY        :" << phonebook._contact[i].get_birthday() << std::endl;
					std::cout << "FAVORITE MEAL   :" << phonebook._contact[i].get_favorite_meal() << std::endl;
					std::cout << "UNDERWAER COLOR :" << phonebook._contact[i].get_underwaer_color() << std::endl;
					std::cout << "DARKSET SECRET  :" << phonebook._contact[i].get_darkest_secret() << std::endl;
				}
				else
					std::cout << "No such contact has been created" << std::endl;
			}
			else
				std::cout << "Please enter a plain number from 1 to 8" << std::endl;
		}
	}
	return (0);
}
