#ifndef cat_CLASS_H
# define cat_CLASS_H
#include <string>
#include <fstream>
#include <iostream>

class Cat
{
public:
	Cat();
	~Cat();
	void	catThis(std::string	const &message);
private:
	void	readFile(std::string	const &file);
	void	readConsole(std::string	const &message);
};
#endif
