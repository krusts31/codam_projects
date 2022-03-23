#ifndef Railgun_CLASS_H
# define Railgun_CLASS_H
# include "AWeapon.hpp"

class Railgun : public AWeapon
{
public:
//construcotrs
	Railgun();
	virtual ~Railgun();
	Railgun(Railgun const & src);
//operator overloads
	Railgun & operator=(Railgun const & src);
//member functions
	void	attack() const;
};
#endif

