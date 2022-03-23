#ifndef Victim_CLASS_H
# define Victim_CLASS_H
# include <string>
# include <iostream>
class Victim
{
public:
//constructors
	Victim(std::string name);
	virtual ~Victim();
	Victim(Victim const & src);
//operator overloads
	Victim &operator=(Victim const & src);
//member functions
	virtual void		getPolymorphed(void)	const;
	std::string	getname(void)		const;
	void		setname(std::string name);

protected:
	Victim(void);
	std::string	_name;
};
#endif
std::ostream         &operator<<(std::ostream &out, const Victim &src);
