#ifndef TacticalMarine_CLASS_H
# define TacticalMarine_CLASS_H
# include "ISpaceMarine.hpp"
class TacticalMarine : public ISpaceMarine
{
public:
//construcotrs
	TacticalMarine(void);
	virtual ~TacticalMarine(void);
	TacticalMarine(TacticalMarine const & src);
//member functions
	TacticalMarine	*clone(void)		const; 
	void		battleCry(void)		const;
	void		rangedAttack(void)	const;
	void		meleeAttack(void)	const;
//operator overloads
	TacticalMarine & operator=(TacticalMarine const & src);
};
#endif
