#ifndef MateriaSource_CLASS_H
# define MateriaSource_CLASS_H
# include "Ice.hpp"
# include "Cure.hpp"
# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
public:
//construcotr
	MateriaSource();
	virtual ~MateriaSource();
	MateriaSource(MateriaSource const & src);
//operator overloads
	MateriaSource & operator=(MateriaSource const & src);
//member functions
	void 		learnMateria(AMateria *src);
	AMateria	*createMateria(std::string const & type);
private:
	AMateria	*_inventory[4];
	int		_index;
};
#endif

