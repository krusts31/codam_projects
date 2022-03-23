#ifndef NinjaTrap_CLASS_H
# define NinjaTrap_CLASS_H
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include <string>

class NinjaTrap : public ClapTrap
{
public:

	NinjaTrap(std::string const & name);
	~NinjaTrap();
	NinjaTrap(NinjaTrap const & src);
	NinjaTrap & operator=(NinjaTrap const & src);

	void			headBut(ClapTrap &attack);
	void			hug(ClapTrap &attact);
	void			klinch(ClapTrap &attack);
	void 			ninjaShoebox(NinjaTrap &attack);
	void 			ninjaShoebox(ClapTrap &attack);
	void 			ninjaShoebox(FragTrap &attack);
	void 			ninjaShoebox(ScavTrap &attack);
private:
	NinjaTrap();
};

#endif

