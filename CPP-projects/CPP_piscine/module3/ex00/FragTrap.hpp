#ifndef FragTrap_CLASS_H
# define FragTrap_CLASS_H
# include <string>

class FragTrap
{
public:

	FragTrap();
	~FragTrap();
	FragTrap(FragTrap const & src);
	FragTrap & operator=(FragTrap const & src);		

	void			rangedAttack(std::string const & target);
	void			meleeAttack(std::string const & target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	void			vaulthunter_dot_exe(std::string const & target);
	void			headBut(std::string const & target);
	void			hug(std::string const & target);
	void			klinch(std::string const & target);
	void			energyPack(unsigned int amount);

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

private:

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
