#ifndef AssaultTerminator_CLASS_H
# define AssaultTerminator_CLASS_H
# include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine
{
public:
//construcotrs
	AssaultTerminator(void);
	virtual ~AssaultTerminator(void);
	AssaultTerminator(AssaultTerminator const & src);
//member functions
	void	battleCry(void)				const;
	void	meleeAttack(void)			const;
	void	rangedAttack(void)			const;
	AssaultTerminator	*clone(void)		const;
//operator overloads
	AssaultTerminator & operator=(AssaultTerminator const & src);
};
#endif





