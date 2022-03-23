#include <iostream>
#include <string>
#include "Human.hpp"

Human::Human()
{
	std::cout << "Human class has been created" << std::endl;
	return ;
}
Human::~Human()
{
	std::cout << "Human class has been deconstructed" << std::endl;
	return ;
}
std::string	Human::identify() const
{
	return (this->_brain.identify());
}
const Brain	&Human::getBrain() const
{
	return (this->_brain);
}
