#ifndef HUMAN_CLASS_H
# define HUMAN_CLASS_H
# include "Brain.hpp"
# include <string>

class Human
{
	public:
		Human();
		~Human();
		const Brain	&getBrain() const;
		std::string	identify() const;	
	private:
		const Brain _brain;
};
#endif
