#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include <iostream>
#include <string>
#include <stdlib.h> 
#include <time.h> 

int	main()
{
	srand(time(0));
	Intern	someRandomIntern;
	Form	*rrf;
	Form	*rrf1;
	Form	*rrf2;
	Form	*rrf3;

	try
	{
		rrf = someRandomIntern.makeForm("shrubbery creation", "Oak");
		rrf1 = someRandomIntern.makeForm("robotomy request", "Bender");
		rrf2 = someRandomIntern.makeForm("presidential pardon", "No more scuters on bike paths");
		rrf3 = someRandomIntern.makeForm("LOL", "xd");
		(void) rrf3;
	}
	catch (char const *e)
	{
		std::cout << e << std::endl;
	}
	Bureaucrat bureaucrat("Week Beuro", 100);
	Bureaucrat Bigbureaucrat("Strong Beuro", 1);
	Bureaucrat Midbureaucrat("Avarge Beuro",50);
	std::cout << "----------------------------------" << std::endl;
	std::cout << "TESTING ShrubberyCreationForm" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << *rrf << std::endl;
	try
	{
		std::cout << "TESTING IF YOU CAN SIGNE A FORM" << std::endl;
		bureaucrat.signeForm(*rrf);
		bureaucrat.executeForm(*rrf);
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "TESTING IF YOU CAN SIGNE A FORM" << std::endl;
		Bigbureaucrat.signeForm(*rrf);
		Bigbureaucrat.executeForm(*rrf);
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << *rrf << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Testing RobotomyRequestForm" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << *rrf1 << std::endl;
	try
	{
		std::cout << "TESTING IF YOU CAN SIGNE A FORM" << std::endl;
		bureaucrat.signeForm(*rrf1);
		bureaucrat.executeForm(*rrf1);
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Midbureaucrat.signeForm(*rrf1);
		Midbureaucrat.executeForm(*rrf1);
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "TESTING IF YOU CAN SIGNE A FORM" << std::endl;
		Bigbureaucrat.signeForm(*rrf1);
		Bigbureaucrat.executeForm(*rrf1);
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << *rrf1 << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "TESTING PresidentialPardonForm" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << *rrf2 << std::endl;
	try
	{
		std::cout << "TESTING IF YOU CAN SIGNE A FORM" << std::endl;
		bureaucrat.signeForm(*rrf2);
		bureaucrat.executeForm(*rrf2);
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "TESTING IF YOU CAN SIGNE A FORM" << std::endl;
		Bigbureaucrat.signeForm(*rrf2);
		Bigbureaucrat.executeForm(*rrf2);
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << *rrf2 << std::endl;

	delete(rrf);
	delete(rrf1);
	delete(rrf2);
	return (0);
}
