#include <iostream>
#include <vector>
#include "span.hpp"

int main()
{
	unsigned int	size;
	srand(time(NULL));

	span sp(10);
	try
	{
		sp.addNumber(-2147483646);
		sp.addNumber(0);
		sp.addNumber(2147483647);
		sp.display_vector();
		std::cout << "The shortest span: "<< sp.shortestSpan() << std::endl;
		std::cout << "The longest span: "<<sp.longestSpan() << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}
	size = 10;
	span	sp1(size);

	try 
	{
		for (unsigned int i = 0; i < size; i++)
			sp1.addNumber(rand() % 500);
	
		sp1.display_vector();

		std::cout << "The shortest span: "<< sp1.shortestSpan() << std::endl;
		std::cout << "The longest span: "<< sp1.longestSpan() << std::endl;

std::cout << "***********************************************" << std::endl;
std::cout << "***********************************************" << std::endl;
std::cout << "		Class testing				" << std::endl;
std::cout << "***********************************************" << std::endl;
std::cout << "***********************************************" << std::endl;

		sp = sp1;
	
		sp.display_vector();

		span	sp2(sp1);
		sp2.display_vector();
		for (unsigned int i = 0; i < size; i++)
			sp2.addNumber(rand() % 500);
		sp2.display_vector();
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	span sp3(2);
	try
	{
		sp3.addNumber(5);
		std::cout << "The shortest span: "<< sp3.shortestSpan() << std::endl;
		std::cout << "The longest span: "<<sp3.longestSpan() << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::vector<int>	hold(1);
	span sp5(5);
	std::cout << "testing addnumber with iterators" << std::endl;

	try
	{
		for (unsigned int i = 0; i < 3; i++)
			hold.push_back(rand() % 100);
		sp5.addNumber(hold.begin(), hold.end());
		sp5.display_vector();
//		for (unsigned int i = 0; i < 3; i++)
//			hold.push_back(rand() % 100);
///		sp5.addNumber(hold.begin(), hold.end());
		sp5.display_vector();
		std::cout << "The shortest span: "<< sp5.shortestSpan() << std::endl;
		std::cout << "The longest span: "<<sp5.longestSpan() << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
