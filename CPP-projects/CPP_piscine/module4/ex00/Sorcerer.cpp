#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string name, std::string title)
{
	this->_name = name;
	this->_title = title;
	std::cout << this->_name <<", " << this->_title << ", is born!" << std::endl;
	return ;
}
Sorcerer::Sorcerer()
{
	this->_name = "Gandalf";
	this->_title = "THE default";
	std::cout << this->_name <<", " << this->_title << ",  is born!" << std::endl;
	return ;
}
Sorcerer::~Sorcerer()
{
	std::cout << this->_name << ", " << this->_title << ", is dead. Consequences will never be the same!" << std::endl;
	return ;
}
Sorcerer::Sorcerer(Sorcerer const & src)
{
	*this = src;
	return ;
}
Sorcerer & Sorcerer::operator=(Sorcerer const & src)
{
	this->_name = src._name;
	this->_title = src._title;
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Sorcerer &src)
{
    out << "I am " << src.getName() << ", " << src.getTitle() << ", and I like ponies ! " << std::endl;
    return (out);
}

std::string	Sorcerer::getName(void) const
{
	return (this->_name);
}

void	Sorcerer::setName(std::string name)
{
	this->_name = name;
}

std::string	Sorcerer::getTitle(void) const
{
	return (this->_title);
}

void	Sorcerer::setTitle(std::string title)
{
	this->_title = title;
}
void	Sorcerer::polymorph(Victim const & victim) const
{
	return (victim.getPolymorphed());	
}
