#ifndef ClapTrap_CLASS_H
# define ClapTrap_CLASS_H
# include <string>
class ClapTrap
{
public:

/*
**	construcotrs
*/

	ClapTrap();
	~ClapTrap();
	ClapTrap(ClapTrap const & src);

/*
**	operator overloads
*/

	ClapTrap & operator=(ClapTrap const & src);

/*
**	Member functions
*/
	void			rangedAttack(std::string const & target);
	void			meleeAttack(std::string const & target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	void			energyPack(unsigned int amount);
/*
**	getters and setters 
*/
	unsigned int		gethp(void)				const;
	void			sethp(unsigned int hp);
	unsigned int		getmaxHp(void)				const;
	void			setmaxHp(unsigned int maxHp);
	unsigned int		geteP(void)				const;
	void			seteP(unsigned int eP);
	unsigned int		getmaxEp(void)				const;
	void			setmaxEp(unsigned int maxEp);
	unsigned int		getlevle(void)				const;
	void			setlevle(unsigned int levle);
	unsigned int		getmeleeDamage(void)			const;
	void			setmeleeDamage(unsigned int meleeDamage);
	unsigned int		getrangeAttackDamage(void)		const;
	void			setrangeAttackDamage(unsigned int rangeAttackDamage);
	unsigned int		getarmour(void)				const;
	void			setarmour(unsigned int armour);
	std::string		getname(void)				const;
	void			setname(std::string name);

protected:
/*
**	Varibles
*/
	unsigned int		_hP;
	unsigned int		_maxHP;
	unsigned int		_eP;
	unsigned int		_maxEP;
	unsigned int		_levle;
	unsigned int		_meleeDamage;
	unsigned int		_rangeAttackDamage;
	unsigned int		_armour;
	std::string		_name;
};

#endif
