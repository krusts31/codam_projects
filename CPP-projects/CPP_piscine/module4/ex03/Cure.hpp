#ifndef Cure_CLASS_H
# define Cure_CLASS_H
# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <iostream>
class Cure : public AMateria
{
public:
//construcotrs
	Cure();
	virtual ~Cure();
	Cure(Cure const & src);
//operator overloads
	Cure & operator=(Cure const & src);
//member functions
	AMateria*       clone() const;
	void            use(ICharacter& target);
};
#endif
