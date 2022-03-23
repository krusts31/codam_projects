#include <iostream>
#include <string>
#include <sstream>
#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain class has been created" << std::endl;
	return ;
}
Brain::~Brain()
{
	std::cout << "Brain class has been deconstructed" << std::endl;
	return;
}
std::string	Brain::identify() const
{
	std::stringstream oss;
	oss << (void*)this;
	return (oss.str());
}
