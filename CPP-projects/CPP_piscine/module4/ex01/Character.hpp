#ifndef Character_CLASS_H
# define Character_CLASS_H
# include <string>
# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character
{
public:
//construcotrs
	Character(std::string const & name);
	~Character();
	Character(Character const & src);
//operator overloads
	Character & operator=(Character const & src);
//member functions
	AWeapon		*getweapon(void)	const;
	int		getAP(void)		const;
	std::string	getname(void)		const;
	void		setweapon(AWeapon *weapon);
	void		setAP(unsigned int AP);
	void		setname(std::string name);
	void		recoverAP(void);
	void		attack(Enemy *enemy);
	void		equip(AWeapon *weapon);
private:
	Character();
	std::string	_name;
	int		_AP;
	AWeapon	*	_weapon;
};

std::ostream &operator<<(std::ostream &out, Character const &src);

#endif
