#ifndef Peon_CLASS_H
# define Peon_CLASS_H
# include "Victim.hpp"
class Peon : public Victim
{
public:
//construcotrs
	Peon(void);
	Peon(std::string name);
	virtual ~Peon();
	Peon(Peon const & src);
//operator overloads
	Peon & operator=(Peon const & src);
//member functions
	void	getPolymorphed(void) const;
};
#endif
