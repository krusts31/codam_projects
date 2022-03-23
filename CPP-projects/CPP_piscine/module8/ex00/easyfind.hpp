#ifndef	easyFind_H
# define easyFind_H
# include <iostream>
# include <algorithm>
# include <vector>

template< typename T >
void	easyFind( T container, int target)
{	
	typename T::const_iterator it;

	it = find(container.begin(), container.end(), target);
	if (it != container.end())
	{
		std::cout << "Element found " << std::endl;
		return ;
	}
	throw "Element not found!"; 
}

#endif
