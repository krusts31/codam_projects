#ifndef FragTrap_CLASS_H
# define FragTrap_CLASS_H
# include "ClapTrap.hpp"
# include <string>

class FragTrap : public ClapTrap
{
public:

/*
**	Construcotrs
*/
	FragTrap();
	~FragTrap();
	FragTrap(FragTrap const & src);
/*
**	Operator overloads
*/
	FragTrap & operator=(FragTrap const & src);
/*
**	member functions
*/
	void			energyPack(unsigned int amount);
	void			vaulthunter_dot_exe(std::string const & target);
	void			headBut(std::string const & target);
	void			hug(std::string const & target);
	void			klinch(std::string const & target);
};

#endif
