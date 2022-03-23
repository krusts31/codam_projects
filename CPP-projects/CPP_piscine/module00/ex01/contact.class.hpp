/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   contact.class.hpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/03 20:23:59 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/08/04 20:47:05 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H
#include <string>

class Contact {

public:
	std::string		get_last_name(void) const;
	std::string		get_first_name(void) const;
	std::string		get_nickname(void) const;
	std::string     get_login(void) const;
	std::string     get_postal_address(void) const;
	std::string     get_email(void) const;
	std::string     get_address(void) const;
	std::string     get_phone_number(void) const;
	std::string     get_birthday(void) const;
	std::string     get_favorite_meal(void) const;
	std::string     get_underwaer_color(void) const;
	std::string     get_darkest_secret(void) const;
	int				get_index(void) const;

	void	set_index(int _index);
	void	set_first_name(std::string _fist_name);
	void	set_last_name(std::string _last_name);
	void	set_nickname(std::string _nickname);
	void	set_login(std::string _login);
	void	set_postal_address(std::string __postal_address);
	void	set_email(std::string _email);
	void	set_address(std::string	address);
	void	set_phone_number(std::string	phone_number);
	void	set_birthday(std::string _birtyay);
	void	set_favorite_meal(std::string _favorite_meal);
	void	set_underwaer_color(std::string _underwear_color);
	void	set_darkest_secret(std::string	darkest_secret);
	Contact(void);
	~Contact(void);

private:
	int			_index;
	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _login;
	std::string _postal_address;
	std::string _address;
	std::string _email;
	std::string _phone_number;
	std::string _birthday;
	std::string _favorite_meal;
	std::string _underwear_color;
	std::string _darkest_secret;
};
#endif
