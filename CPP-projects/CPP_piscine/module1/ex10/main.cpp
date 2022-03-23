#include "Cat.hpp"
#include <iostream>
#include <sys/stat.h>

int	main(int argc, char **argv)
{
	Cat	cat;
	int	index;
	index = 1;
	if (argc == 1)
	{
		cat.catThis("");
		return (0);
	}
	struct stat buf;
	stat(argv[1], &buf);
	if( buf.st_mode & S_IFDIR )
	{
		std::cout << "ft_Cat: " << argv[1] << ": is a directory" << std::endl;
		return (-1);
	}

	while(argc > 1)
	{
		cat.catThis(argv[index]);
		argc--;
		index++;
	}
	return (0);
}
