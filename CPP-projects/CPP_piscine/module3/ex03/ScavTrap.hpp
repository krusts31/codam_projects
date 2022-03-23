#ifndef ScavTrap_CLASS_H
# define ScavTrap_CLASS_H
#include "ClapTrap.hpp"
#include <stdlib.h>

class ScavTrap : public ClapTrap
{
public:
	ScavTrap(std::string const & name);
	~ScavTrap();
	ScavTrap(ScavTrap const & src);
	ScavTrap & operator=(ScavTrap const & src);

	void		lionRidle(void);
	void		mapRidle(void);
	void		fishhookRidle(void);
	void		towleRidle(void);
	void		INOCRidle(void);
	void		challengeNewcomer(void);
private:
	ScavTrap();
};
#endif
