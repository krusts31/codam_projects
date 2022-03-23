#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

int	main()
{
	try
	{
		Bureaucrat bureaucrat("Rupak Kumar Dutta", 1);
		std::cout << "---------------------------------------------------" << std::endl;
		std::cout << bureaucrat << std::endl;
		std::cout << "** " << "testing if I can increment grade up to 0" << std::endl;
		
//		bureaucrat.gradeUp();
		bureaucrat.gradeDown();
		bureaucrat.gradeDown();
		std::cout << "** " << "testing if I can increment grade down works" << std::endl;
		std::cout << bureaucrat << std::endl;
		std::cout << "---------------------------------------------------" << std::endl;
		std::cout << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bureaucrat1("Justice Santhosh Hegde", 150);
		std::cout << "---------------------------------------------------" << std::endl;
		std::cout << bureaucrat1 << std::endl;
		std::cout << "** " << "testing if I can increment grade below to 150" << std::endl;
//		bureaucrat1.gradeDown();
		bureaucrat1.gradeUp();
		bureaucrat1.gradeUp();
		std::cout << "** " << "testing if I can increment grade up works" << std::endl;
		std::cout << bureaucrat1 << std::endl;
		std::cout << "---------------------------------------------------" << std::endl;
		std::cout << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bureaucrat2("Uday Veer Singh", -1);
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bureaucrat3("Justice Santhosh Hegde", 160);
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
