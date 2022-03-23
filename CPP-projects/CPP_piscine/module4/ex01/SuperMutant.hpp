#ifndef SuperMutant_CLASS_H
# define SuperMutant_CLASS_H
# include "Enemy.hpp"

class SuperMutant : public Enemy
{
public:
//constructors
	SuperMutant();
	virtual ~SuperMutant();
	SuperMutant(SuperMutant const & src);
//operator overloads
	SuperMutant & operator=(SuperMutant const & src);
//member functiones
	void		attack(void) const;
	void		takeDamage(int damage);
};
#endif
