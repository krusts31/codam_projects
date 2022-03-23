#include <string>
#include <ctype.h>
#include <sstream>
#include <iostream>
#include <stdlib.h> 

int	main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cout << "PLEASE PASS ONR ARGUMENT" << std::endl;
		return (0);
	}

	bool	yes;
	char	alpha;
	int	number;
	float	Float;
	double	Double;
	std::size_t found;

	yes = true;
	std::stringstream	ss;
	std::string		s;
	std::string		input;
	input = argv[1];
	if (!input.empty())
	{
		Float = atof(argv[1]);
		Float = static_cast<float>(Float);
		ss << Float;
		s = ss.str();
		found = s.find(".");
		s = s.substr(0, found);
		unsigned long	index;

		index = 0;
		number = atoi(s.c_str());
		if (isprint(*argv[1]) && 1 == input.length() && !isdigit(*argv[1]))
		{
			alpha = static_cast<char>(*argv[1]);
			std::cout << "char: " << alpha << std::endl;
		}
		else
		{
			if (number < 127 && number >= 32)
				std::cout << "Char: "<< (char)(number) << std::endl;
			else
				std::cout << "char: value is not printable" << std::endl;
		}
	}
	else
		std::cout << "char: value is not printable" << std::endl;
	if (input.length() <= 11 && (input.find_first_not_of("-0123456789") == std::string::npos))
	{
		long	hold;
		hold = atol(argv[1]);
		if (hold < -2147483648 || hold > 2147483647)
		{
			yes = false;
			Double = static_cast<double>(hold);
			std::cout << "Double: "<< Double << std::endl;
			std::cout << "Int: converiosn not possible" << std::endl;
		}
		else 
		{
			number = atoi(argv[1]);
			std::cout << "int: " << number << std::endl;
		}
	}
	else
		std::cout << "int: conversion ot possible" << std::endl;
	if (((input.find_first_not_of("f-.1234567890") == std::string::npos) || (input == "-inf" || input == "+inf" || input == "nan" \
		|| input == "nanf" || input == "+inff" || input == "-inff")) && yes)
	{
		if (input.length() <= 11 && (input.find_first_not_of("-0123456789") == std::string::npos))
		{
				Float = atof(argv[1]);
				Double = static_cast<double>(Float);
				std::cout << "Double: " << Double << ".0"<< std::endl;
		}
		else
		{
			if (input == "+inf" || input == "+inff")
				std::cout << "Float: +inf" << std::endl;
			else if (input == "nan" || input == "nanf")
				std::cout << "Float: nan" << std::endl;
			else if (input == "-inf" || input == "-inff")
				std::cout << "Float: -inf" << std::endl;
			else
			{
				Float = atof(argv[1]);
				Double = static_cast<double>(Float);
				ss << Double;
				s = ss.str();
				if (s == "0")
					std::cout << "Double: 0.0" << std::endl;
				found = s.find(".");
				if (found != std::string::npos)
					std::cout << "Double: " << Double << std::endl;
				else
					std::cout << "Double: " << Double << ".0" << std::endl;
			}
		}
	}
	else
	{
		if (yes)
			std::cout << "Double: not possible to convert" << std::endl; 
	}
	if ((input.find_first_not_of("f.-0123456789") == std::string::npos) || ((input == "-inff") || input == "+inff" || input == "nanf" \
		|| input == "nan" || input == "+inf" || input == "-inf"))
	{
		if (input.length() <= 11 && (input.find_first_not_of("-0123456789") == std::string::npos))
		{
			Float = atof(argv[1]);
			Float = static_cast<float>(Float);
			std::cout << "Float: " << Float << ".0f" <<  std::endl;
		}
		else
		{
			if (input == "+inf" || input == "+inff")
				std::cout << "Float: +inff" << std::endl;
			else if (input == "nan" || input == "nanf")
				std::cout << "Float: nanf" << std::endl;
			else if (input == "-inf" || input == "-inff")
				std::cout << "Float: -inff" << std::endl;
			else
			{
				Float = atof(argv[1]);
				Float = static_cast<float>(Float);
				ss << Float;
				s = ss.str();
				if (s == ("00"))
					std::cout << "Float: 0.0f" << std::endl;
				else
				{
					found = s.find(".");
					if (found != std::string::npos)
						std::cout << "Float: " << Float << "f" <<  std::endl;
					else
						std::cout << "Float: " << Float << ".0f" <<  std::endl;
				}
			}
		}
	}
	else
		std::cout << "Float: not possible to convert" << std::endl;
	return (0);
}
