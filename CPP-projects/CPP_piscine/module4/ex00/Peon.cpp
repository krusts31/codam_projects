#include "Peon.hpp"
Peon::Peon() : Peon::Victim("Default")
{
	std::cout << "Zog Zog" << std::endl;
	return ;
}
Peon::Peon(std::string name) : Peon::Victim(name)
{
	std::cout << "Zog zog." << std::endl;
	return ;
}
Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
	return ;
}
Peon & Peon::operator=(Peon const & src)
{
	this->_name = src._name;
	return *this;
}
Peon::Peon(const Peon &src) : Peon::Victim()
{
	*this = src;
	return ;
}

void 	Peon::getPolymorphed(void) const
{
	std::cout << this->_name << " has been turned into a pink pony !" << std::endl;
	return ;
}

