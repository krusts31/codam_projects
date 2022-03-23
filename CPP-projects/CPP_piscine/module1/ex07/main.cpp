#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Please pass 3 parameters" << std::endl;
		return (-1);
	}
	struct stat buf;
	stat(argv[1], &buf);

	std::string	heyStack = argv[2];
	std::string	needle = argv[3];
	std::ifstream	content(argv[1]);
	std::string	newLine;
	std::string	line;
	size_t		pos;

	if (!content || !content.is_open() )
	{
		std::cout << "Failed to open file : [" << argv[1] << "]" << std::endl;
		return (-1);
	}
	if( buf.st_mode & S_IFDIR )
	{
		std::cout << "<" << argv[1] << "> is a directory please pass a file!" << std::endl;
		return (-1);
	}
	if (heyStack == needle)
	{
		std::cout << "<" << argv[2] << "> == <" << argv[3] << "> what the point of that?!" << std::endl;
		return (-1);
	}
	std::string	r = ".replacement";
	std::string	newName = argv[1] + r;
	std::ofstream	fileName(newName.c_str());
	line = "";
	int	k;
	while (getline(content, line))
	{
		k = 0;
		while ((pos = line.find(heyStack, k)) != std::string::npos)
		{
			line.replace(pos, heyStack.length(), needle);
			k = pos + needle.length();
		}
		fileName << line;
		if (!content.eof())
			fileName << std::endl;
	}
	content.close();
        fileName.close();
	return (0);
}
