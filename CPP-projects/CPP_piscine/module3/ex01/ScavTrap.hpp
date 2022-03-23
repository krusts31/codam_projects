#ifndef ScavTrap_CLASS_H
# define ScavTrap_CLASS_H
# include <string>
# include <stdlib.h>

class ScavTrap
{
public:
/*
**	constructors
*/
	ScavTrap(std::string const & name);
	~ScavTrap();
	ScavTrap(ScavTrap const & src);
/*
**	operator overload
*/
	ScavTrap & operator=(ScavTrap const & src);

/*
**	Getters and setters
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
/*
**	Member functions
*/
	void		energyPack(unsigned int amount);
	void		rangedAttack(std::string const & target);
	void		meleeAttack(std::string const & target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	void		lionRidle(void);
	void		mapRidle(void);
	void		fishhookRidle(void);
	void		towleRidle(void);
	void		INOCRidle(void);
	void		challengeNewcomer(void);
private:
	ScavTrap();		//default constructor
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
