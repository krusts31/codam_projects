#ifndef HUMANB_CLASS_H
# define HUMANB_CLASS_H
# include <string>
# include "Weapon.hpp"
class HumanB 
{
public:
	HumanB(std::string name);
	~HumanB();
	void		setWeapon(Weapon &weapon);
	void		attack() const;
	void		setName(std::string name);
	std::string	getName() const;
private:
	std::string _name;
	Weapon *_weapon;
};

#endif
