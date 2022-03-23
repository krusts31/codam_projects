#include "easyfind.hpp"
#include <list>
#include <iostream>
#include <vector>
#include <exception>

/*#####	STL #####
**	Algorithms
**	Containers
**	Functions
**	Iterators
*/	

int	main()
{
	int		find = 72;
	std::vector<int>	g1;

	std::list<int>		lst;

	lst.push_back(1);
	lst.push_back(17);
	lst.push_back(42);
	lst.push_back(50);
	lst.push_back(72);

	for (int i = 0; i <= 100; i = i + 10)
		g1.push_back(i);
	try {
		easyFind(g1, find);
	}
	catch (const char *e)
	{
		std::cout << e << std::endl; 
	}
	try {
		easyFind(lst, find);
	}
	catch (const char *e)
	{
		std::cout << e << std::endl; 
	}
	return (0);
}
