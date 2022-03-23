#ifndef AMATERIA_H
# define AMATERIA_H
# include <string>
# include "ICharacter.hpp"
class	AMateria
{
protected:
	unsigned int 	_xp;
	std::string	_type;
	AMateria();
public:
//constructors
	AMateria(std::string const & type);
	AMateria(AMateria const & src);
	virtual ~AMateria();
//member functions
	std::string const &	getType() const;	//Returns the materia type
	unsigned int		getXP() const;		//Returns the Materia's XP

	virtual			AMateria* clone() const = 0;
	virtual void		use(ICharacter &target) = 0;
	void			addXP();
//operator overload
	AMateria &operator=(AMateria const & src);
};
#endif
