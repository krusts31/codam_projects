/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   info.class.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/03 15:31:35 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/08/05 17:28:43 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "info.class.hpp"

void	info::add_contact(int index, int _index, std::string _first_name, std::string _last_name, std::string _nickname, std::string _login,
	std::string _postal_address, std::string _email, std::string _address, std::string _phone_number,
	std::string _birthday, std::string _favorite_meal, std::string _underwear_color,
	std::string _darkest_secret)
{
	_contact[index].set_index(_index);
	_contact[index].set_first_name(_first_name);
	_contact[index].set_last_name(_last_name);
	_contact[index].set_nickname(_nickname);
	_contact[index].set_login(_login);
	_contact[index].set_postal_address(_postal_address);
	_contact[index].set_email(_email);
	_contact[index].set_address(_address);
	_contact[index].set_phone_number(_phone_number);
	_contact[index].set_birthday(_birthday);
	_contact[index].set_favorite_meal(_favorite_meal);
	_contact[index].set_underwaer_color(_underwear_color);
	_contact[index].set_darkest_secret(_darkest_secret);
}

void	info::set_empty_contact()
{
	int	index;

	index = 0;
	while (index > 8)
	{
		add_contact(index , 0, "", "", "", "", "", "", "", "", "", "", "", "");
		index++;
	}
}

info::info()
{
	return ;
}

info::~info()
{
	return ;
}

Contact info::get_all_contact(int index) const
{
		return (this->_contact[index]);
}

Contact info::get_by_index(int index) const
{
		return (this->_contact[index]);
}
