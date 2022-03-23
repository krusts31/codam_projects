#ifndef HUMANA_CLASS_H
# define HUMANA_CLASS_H
#include <string>
#include "Weapon.hpp"

class HumanA 
{
public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void		attack() const;
	void		setName(std::string name);
	std::string	getName() const;

private:
	std::string _name;
	Weapon &_weapon;
};
#endif
