#include "Cat.hpp"
#include <fstream>
#include <iostream>
#include <string>

Cat::Cat()
{
	return ;
}

Cat::~Cat()
{
	return ;
}

void	Cat::readFile(std::string const &file)
{
	std::string	out;
	out = "";
	std::ifstream content(file);
	if (!content)
	{
		std::cerr << "cat: "<< file << " No such file or directory or premission denied" << std::endl;
		return ;
	}
	while (getline (content, out))
		std::cout << out << std::endl;
}

void	Cat::readConsole(std::string const &message)
{
	std::string	out;
	(void)message;
	while (1)
	{
		getline(std::cin, out);
		if (!std::cin.good())
			break ;
		std::cout << out << std::endl;
	}
}

void	Cat::catThis(std::string const &doo)
{
	bool	file;
	bool	console;
	int	index;

	file = true;
	console = false;
	void (Cat:: *actions[2])(std::string const &message)
	{
		&Cat::readFile,
		&Cat::readConsole
	};
	if (doo.empty())
	{
		console = true;
		file = false; 
	}
	index = (file) ? 0 :
		(console) ? 1:
		throw "";
	(this->*actions[index])(doo);
}
