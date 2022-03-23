#ifndef Sorcerer_CLASS_H
# define Sorcerer_CLASS_H
#include "Victim.hpp"
class Sorcerer
{
public:
//construcotrs
	Sorcerer(std::string name, std::string title);
	~Sorcerer();
	Sorcerer(Sorcerer const & src);
//operator overloads
	Sorcerer & operator=(Sorcerer const & src);
//member functions
	std::string	getName(void)			const;
	void		setName(std::string name);
	std::string	getTitle(void)			const;
	void		setTitle(std::string title);
	void		polymorph(Victim const & victim)const;
private:
	Sorcerer();
	std::string	_name;
	std::string	_title;
};

std::ostream         &operator<< (std::ostream &out, const Sorcerer &src);

#endif
