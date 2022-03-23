#ifndef Squad_CLASS_H
# define Squad_CLASS_H
# include <stddef.h>
# include "ISquad.hpp"
# include "TacticalMarine.hpp"
# include "AssaultTerminator.hpp"

class Squad : public ISquad
{
public:
	typedef struct		s_container
	{
		ISpaceMarine		*unit;
		struct s_container	*next;
	}			t_container;
//construcotrs
	Squad(void);
	virtual ~Squad(void);
	Squad(Squad const & src);
//member functions
	bool			Original(ISpaceMarine *unit, t_container * forUse)	const;
	void			deleteMar(void);
	virtual int		push(ISpaceMarine	*marine);
	virtual	int		getCount(void)						const;
	virtual ISpaceMarine	*getUnit(int N)						const;
//operator overloads
	Squad & operator=(Squad const & src);
private:

	t_container	*_marines;
};
#endif







