#ifndef PowerFist_CLASS_H
# define PowerFist_CLASS_H
# include "AWeapon.hpp"

class PowerFist : public AWeapon
{
public:
//constructors
	PowerFist();
	virtual ~PowerFist();
	PowerFist(PowerFist const & src);
//operator overloads
	PowerFist & operator=(PowerFist const & src);
//member functions
	void	attack(void) const;
};
#endif

