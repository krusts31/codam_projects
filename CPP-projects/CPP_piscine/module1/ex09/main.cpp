#include "Logger.hpp"

int	main()
{
	Logger logme("test.txt");
	//Logger logme("\0");
	try
	{
		logme.log("logToConsole", "Hey I am alive");
		logme.log("logToFile", "Hey I am in a file ");
		logme.log("logToFile", "Hey I am in a file1");
		logme.log("xx", "Hey I am in a file1");
	}
	catch (char const *e)
	{
		std::cerr << e << std::endl;	
	}
	return (0);
}
