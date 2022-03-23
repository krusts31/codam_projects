#ifndef BRAIN_CLASS_H
# define BRAIN_CLASS_H
# include <iostream>
# include <string>

class Brain
{
	public:
		Brain();
		~Brain();
		std::string	identify(void) const;
};
#endif
