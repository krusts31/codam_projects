#ifndef Logger_CLASS_H
# define Logger_CLASS_H
#include <string>
#include <iostream>
#include <fstream>

class Logger
{
public:
	Logger(std::string	 const &logfile);
	~Logger();

	void			log(std::string const & dest, std::string const & message);

private:
	void			logToConsole(std::string const &logMe);
	void			logToFile(std::string const &logMe);
	std::string		makeLogEntry(std::string const &logMe);
	
	std::ofstream		_olog;
};

#endif
