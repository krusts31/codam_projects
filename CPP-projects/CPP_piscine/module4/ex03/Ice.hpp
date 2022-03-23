#ifndef Ice_CLASS_H
# define Ice_CLASS_H
# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <iostream>
class Ice : public AMateria
{
public:
//construcotrs
	Ice();
	virtual ~Ice();
	Ice(Ice const & src);
//operator overlods
	Ice & operator=(Ice const & src);
//member functions
	AMateria	*clone() const;
	void		use(ICharacter& target);
};
#endif
