/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   info.class.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/04 20:46:32 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/08/04 20:47:10 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef	INFO_CLASS_H
# define INFO_CLASS_H
# include "contact.class.hpp"
# include <string>

class info {

public:
/*
**				CONSTRUCTOR AND DECONSTRUCOTR
*/
	info(void);
	~info(void);
	
/*
**				MEMBER FUNCTIONS
*/
	void add_contact(int index, int _index, std::string _first_name, std::string _last_name, std::string _nickname, std::string _login, 
		std::string _postal_address, std::string _email, std::string _address, std::string _phone_number,
		std::string _birthday, std::string _favorite_meal, std::string _underwear_color, 
		std::string _darkest_secret);
	void	set_empty_contact(void);

/*
**				GETTERS 
*/
	Contact get_all_contact(int index) const;
	Contact get_by_index(int index) const;
	Contact get_contact(int index) const;

/*
**				MEMBER ATRIBUTS
*/
	Contact	_contact[8];
};
#endif
