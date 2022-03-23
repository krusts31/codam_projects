#ifndef Character_CLASS_H
# define Character_CLASS_H
# include <string>
# include "Ice.hpp"
# include "Cure.hpp"
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter
{
public:
//construcots
	Character(const std::string	&name);
	virtual ~Character();
	Character(Character const & src);
//operator overloads
	Character & operator=(Character const & src);
//member functions
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
	std::string const & getName() const;
private:
	Character();
	AMateria	*_inventory[4];
	std::string	_name;
	int		_index;
};
#endif
