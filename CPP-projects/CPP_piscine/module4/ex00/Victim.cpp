#include "Victim.hpp"

Victim::Victim()
{
	this->_name = "";
	return ;
}
Victim::Victim(std::string name)
{
	this->_name = name;
	std::cout << "Some random victim called " << this->_name << " just appeared!" << std::endl;
}
Victim::~Victim()
{
	std::cout << "Victim " << this->_name << " just died for no apparent reason!" << std::endl;
	return ;
}
Victim::Victim(Victim const & src)
{
	*this = src;
}

Victim	 &Victim::operator=(Victim const & src)
{
	this->_name = src._name;
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const Victim &src)
{
	out << "I'm " << src.getname() << " and I like otters!" << std::endl;
	return (out);
}


std::string	Victim::getname(void) const
{
	return (this->_name);
}
void	Victim::setname(std::string name)
{
	this->_name = name;
}

void	Victim::getPolymorphed(void) const
{
	std::cout << getname() << " has been turned into a cute little sheep!" << std::endl;
}
