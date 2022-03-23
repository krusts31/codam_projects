#include "Human.hpp"
#include <iostream>

int main(void)
{
	Human h;

	try
	{
		h.action("meleeAttack", "You");
		h.action("rangedAttack", "You");
		h.action("intimidatingShout", "YOU");
		h.action("Whaaat?", "You");
	}
	catch(char const *e)
	{
		std::cerr << "human: exception: " << e << std::endl;
	}
	return (0);
}
