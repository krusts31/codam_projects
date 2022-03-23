#include "Logger.hpp"
#include <iostream>
#include <string>
#include <fstream>
# include <iomanip>
# include <chrono>
# include <sstream>

Logger::Logger(std::string const &logfile)
{
	this->_olog.open(logfile, std::ios::app);
	if (this->_olog.fail())
        {
            std::cout << "Error creating file! :(" << std::endl;
            exit(1);
        }
	return ;
}
Logger::~Logger()
{
	if (this->_olog.is_open())
		this->_olog.close();
	return ;
}

void		Logger::logToConsole(std::string const &logMe)
{
	std::cout << this->makeLogEntry(logMe) << std::endl;
}

void		Logger::logToFile(std::string const &logMe)
{
	if (!this->_olog.is_open() || !this->_olog.good())
		throw "Can't write to file";
	_olog << this->makeLogEntry(logMe) << std::endl;
}

std::string	Logger::makeLogEntry(std::string	const &logMe)
{
	std::stringstream 	out;
	std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
	std::time_t time_now = std::chrono::system_clock::to_time_t(now);

	tm utc_tm = *localtime(&time_now);
		out << std::setfill('0') << "[" << (utc_tm.tm_year + 1900) << "/"
			<< std::setw(2) << utc_tm.tm_mon << "/"
			<< std::setw(2) << utc_tm.tm_mday << ":"
			<< std::setw(2) << utc_tm.tm_hour << "h"
			<< std::setw(2) << utc_tm.tm_min << "m"
			<< std::setw(2) << utc_tm.tm_sec << "s] ";
	out << logMe;
	return (out.str());
}

void		Logger::log(std::string const & dest, std::string const & message)
{
	int	index;

	void	(Logger:: *const actions[2])(std::string const &logMe) =
	{
		&Logger::logToConsole,
		&Logger::logToFile
	};

	index = ("logToConsole" == dest) ? 0 :
		("logToFile" == dest) ? 1 :
		throw "try: logToFile logToConsole";
	(this->*actions[index])(message);
}
