#ifndef AWeapon_CLASS_H
# define AWeapon_CLASS_H
# include <string>

class AWeapon
{
public:
//construcotrs
	AWeapon(std::string const & name, int apcost, int damage);
	virtual ~AWeapon();
	AWeapon(AWeapon const & src);

//operator overloads
	AWeapon & operator=(AWeapon const & src);
//member functions
	std::string	getname(void)		const;
	void		setname(std::string name);
	int		getdamage(void)		const;
	void		setdamage(unsigned int damage);
	int		getAPcost(void)		const;
	void		setAPcost(unsigned int APcost);
	virtual	void	attack(void) const = 0;
protected:
	AWeapon();
	std::string	_name;
	int		_damage;
	int		_APcost;
};
#endif
