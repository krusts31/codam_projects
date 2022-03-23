#ifndef PlasmaRifle_CLASS_H
# define PlasmaRifle_CLASS_H
# include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
public:
//construcotrs
	PlasmaRifle();
	virtual ~PlasmaRifle();
	PlasmaRifle(PlasmaRifle const & src);
//operator overloads
	PlasmaRifle & operator=(PlasmaRifle const & src);
//member functions
	void	attack() const;
};
#endif
