#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <string>

int	main()
{
	Bureaucrat bureaucrat("Rupak Kumar Dutta", 100);
	Form formX("formX", 20, 30);
	Form formY("formY", 101, 101);
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Testing fromX" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << formX << std::endl;
	try
	{
		formX.beSigned(bureaucrat);
	}
	catch (std::exception const & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << formX << std::endl;
	std::cout <<  std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Testing fromY" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << formY << std::endl;
	try
	{
		formY.beSigned(bureaucrat);
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << formY << std::endl;
	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Testing fromZ" << std::endl;
	Form formZ("fromZ", 150, 150);
	std::cout << "----------------------------------" << std::endl;
	std::cout << formZ << std::endl;
	try
	{
		bureaucrat.signeForm(formZ);
	}
	catch (std::exception const & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << formZ << std::endl;
	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Testing fromA" << std::endl;
	Form formA("fromA", 10, 1);
	std::cout << "----------------------------------" << std::endl;
	std::cout << formA << std::endl;
	try
	{
		bureaucrat.signeForm(formA);
	}
	catch (std::exception const & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << formA << std::endl;
	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Try to creat impossible forms" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	
/*
**	try to create imposible forms
*/
	try
	{
		Form form1("C28", 160, 1);
		(void)form1;
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form form2("C28", -1, 30);
		(void)form2;
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form form3("C28", 20, 160);
		(void)form3;
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form form4("C28", 20, -12);
		(void)form4;
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
