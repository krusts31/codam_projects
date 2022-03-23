#include "Meseeks.hpp"
#include <iostream>

Meseeks::Meseeks() : Meseeks::Enemy("Meseeks", 20)
{
	std::cout << "* UUUUuu Can Do! *" << std::endl;
	return ;
}

Meseeks::~Meseeks()
{
	std::cout << "* PUFFFF! *" << std::endl;
	return ;
}

Meseeks & Meseeks::operator=(Meseeks const & src)
{
	if (this == &src)
		return (*this);
	settype(src.gettype());
	sethp(src.gethp());
	return (*this);
}

Meseeks::Meseeks(Meseeks const &src) : Meseeks::Enemy(src)
{
}
