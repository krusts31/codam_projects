#include <iostream>
#include "Peon.hpp"
#include "Victim.hpp"
#include "Sorcerer.hpp"

int	main(void)
{
	Sorcerer	robert("Robert", "the Magnificent");
	Victim		Jimmy("Jimmy");
	Peon		joe("Joe");

	std::cout << std::endl << robert << std::endl << Jimmy << std::endl << joe << std::endl;

	robert.polymorph(Jimmy);
	std::cout << std::endl;
	robert.polymorph(joe);
	std::cout << std::endl;

	return (0);
}
