#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Form.hpp"
#include <iostream>
#include <string>
#include <stdlib.h> 
#include <time.h> 

int	main()
{
	srand(time(0));
	Bureaucrat bureaucrat("Week Beuro", 100);
	Bureaucrat Bigbureaucrat("Strong Beuro", 1);
	Bureaucrat Midbureaucrat("Avarge Beuro",50);
	Form *formS = new ShrubberyCreationForm("Tree act 48");
	Form *formR = new RobotomyRequestForm("XCOM");
	Form *formP = new PresidentialPardonForm("Legalaiz IT 420");
	std::cout << "----------------------------------" << std::endl;
	std::cout << "TESTING ShrubberyCreationForm" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << *formS << std::endl;
	try
	{
		std::cout << "TESTING IF YOU CAN SIGNE A FORM" << std::endl;
		bureaucrat.signeForm(*formS);
		bureaucrat.executeForm(*formS);
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "TESTING IF YOU CAN SIGNE A FORM" << std::endl;
		Bigbureaucrat.signeForm(*formS);
		Bigbureaucrat.executeForm(*formS);
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << *formS << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Testing RobotomyRequestForm" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << *formR << std::endl;
	try
	{
		std::cout << "TESTING IF YOU CAN SIGNE A FORM" << std::endl;
		bureaucrat.signeForm(*formR);
		bureaucrat.executeForm(*formR);
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Midbureaucrat.signeForm(*formR);
		Midbureaucrat.executeForm(*formR);
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "TESTING IF YOU CAN SIGNE A FORM" << std::endl;
		Bigbureaucrat.signeForm(*formR);
		Bigbureaucrat.executeForm(*formR);
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << *formR << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "TESTING PresidentialPardonForm" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << *formP << std::endl;
	try
	{
		std::cout << "TESTING IF YOU CAN SIGNE A FORM" << std::endl;
		bureaucrat.signeForm(*formP);
		bureaucrat.executeForm(*formP);
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "TESTING IF YOU CAN SIGNE A FORM" << std::endl;
		Bigbureaucrat.signeForm(*formP);
		Bigbureaucrat.executeForm(*formP);
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << *formP << std::endl;

	delete(formS);
	delete(formR);
	delete(formP);
	return (0);
}
