/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   contact.class.cpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/03 20:24:13 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/08/05 17:28:32 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "contact.class.hpp"

/*
**				CONSTRUCTORS
*/

Contact::Contact(void)
{
	return ;
}
Contact::~Contact(void)
{
	return ;
}

/*
**				SETTERS
*/

void	Contact::set_index(int _index)
{
	this->_index = _index;
}
void	Contact::set_first_name(std::string _first_name)
{
	this->_first_name = _first_name;
}
void	Contact::set_last_name(std::string _last_name)
{
	this->_last_name = _last_name;
}
void	Contact::set_nickname(std::string _nickname)
{
	this->_nickname = _nickname;
}
void	Contact::set_login(std::string _login)
{
	this->_login = _login;
}
void	Contact::set_postal_address(std::string _postal_address)
{
	this->_postal_address = _postal_address;
}
void	Contact::set_email(std::string _email)
{
	this->_email = _email;
}
void	Contact::set_address(std::string _address)
{
	this->_address = _address;
}
void	Contact::set_phone_number(std::string _phone_number)
{
	this->_phone_number = _phone_number;
}
void	Contact::set_birthday(std::string _birthday)
{
	this->_birthday = _birthday;
}
void	Contact::set_favorite_meal(std::string _favorite_meal)
{
	this->_favorite_meal = _favorite_meal;
}
void	Contact::set_underwaer_color(std::string _underwear_color)
{
	this->_underwear_color = _underwear_color;
}
void	Contact::set_darkest_secret(std::string _darkest_secret)
{
	this->_darkest_secret = _darkest_secret;
}

/*
**			GETTERS
*/

int	Contact::get_index() const
{
	return (this->_index);
}
std::string	Contact::get_first_name(void) const
{
	return (this->_first_name);
}
std::string	Contact::get_last_name(void) const
{
	return (this->_last_name);
}
std::string	Contact::get_nickname(void) const
{
	return (this->_nickname);
}
std::string	Contact::get_login(void) const
{
	return (this->_login);
}
std::string	Contact::get_postal_address(void) const
{
	return (this->_postal_address);
}
std::string	Contact::get_email(void) const
{
	return (this->_email);
}
std::string	Contact::get_address(void) const
{
	return (this->_address);
}
std::string	Contact::get_phone_number(void) const
{
	return (this->_phone_number);
}
std::string	Contact::get_birthday(void) const
{
	return (this->_birthday);
}
std::string	Contact::get_favorite_meal(void) const
{
	return (this->_favorite_meal);
}
std::string	Contact::get_underwaer_color(void) const
{
	return (this->_underwear_color);
}
std::string	Contact::get_darkest_secret(void) const
{
	return (this->_darkest_secret);
}

