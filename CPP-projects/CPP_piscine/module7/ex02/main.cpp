#include "Array.hpp"
#include <string>
#include <iostream>

int	main()
{
	Array<int>		arrempty;
	std::cout << "**********************************" << std::endl;
	std::cout << "Testing empty array" << std::endl;
	std::cout << "1.	The sieze of empty arr: " << arrempty.size() << std::endl;
	std::cout << "2.	Accsesing out of bound memory. arrempty[1]: " << std::endl;
	try 
	{
		std::cout << arrempty[1] << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "**********************************" << std::endl;
	
	Array<int>		arrInt(5);
	std::cout << "**********************************" << std::endl;
	std::cout << "Testing 	int array(5)" << std::endl;
	std::cout << "1.	The sieze of empty arrInt(5): " << arrInt.size() << std::endl;
	std::cout << "2.	Accsesing out of bound memory. arrFloat[5]: " << std::endl;
	try 
	{
		for (int i = 0; i != 5; i++)
		{
			std::cout << "this is arrInt[" << i << "] vlaue: " << arrInt[i] << std::endl;
		}
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "**********************************" << std::endl;
	Array<float>		arrFloat(42);
	std::cout << "**********************************" << std::endl;
	std::cout << "Testing floatarr(42)" << std::endl;
	std::cout << "1.	The sieze of arrFloat(42): " << arrFloat.size() << std::endl;
	std::cout << "2.	Accsesing out of bound memory. arrFloat[42]: " << std::endl;
	try 
	{
		for (float i = 0; i != 43; i++)
		{
			arrFloat[i] = i;
			std::cout << "this is arrFloat[" << i << "] vlaue: " << arrFloat[i] << std::endl;
		}
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "**********************************" << std::endl;
	Array<char>		arrChar(5);
	std::cout << "**********************************" << std::endl;
	std::cout << "Testing char array" << std::endl;
	std::cout << "1.	The size of arrChar(5): " << arrChar.size() << std::endl;
	std::cout << "2.	Accsesing out of bound memory. arrChar[5]: " << std::endl;
	try 
	{
		for (float i = 0; i != 5; i++)
		{
			arrChar[i] = (char)i + 32;
			if (i + 32 >= 127)
				std::cout << "Char is not printable" << std::endl;
			else
				std::cout << "this is arrChar[" << i << "] vlaue: " << arrChar[i] << std::endl;
		}
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "**********************************" << std::endl;
	Array<std::string>	arrString(5);
	std::cout << "**********************************" << std::endl;
	std::cout << "Testing string array" << std::endl;
	std::cout << "1.	The sieze of empty arrString(5): " << arrString.size() << std::endl;
	std::cout << "2.	Accsesing out of bound memory. arr2d[5]: " << std::endl;
	try 
	{
		std::string	aa[4] = {"hello", "zaz", "wpww", "tik"};
		for (int i = 0; i != 4; i++)
		{
			arrString[i] = aa[i];
		}
		for (float i = 0; i != 5; i++)
		{
			std::cout << "this is arrString[" << i << "] vlaue: " << arrString[i] << std::endl;
		}
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "**********************************" << std::endl;
	Array<int*>		arr2d(4);
	Array<int*>		arr2dcpy(6);
	std::cout << "Testing string array" << std::endl;
	std::cout << "1.	The sieze of empty arr2d(4): " << arr2d.size() << std::endl;
	std::cout << "2.	Accsesing out of bound memory. arr2dcpy = arr2d: " << std::endl;
	try 
	{
		int damn[2] = {1, 1 + 100};
		int damn1[2] = {2, 2 + 100};
		int damn2[2] = {3, 3 + 100};
		int damn3[2] = {4, 4 + 100};
		arr2d[0] = damn;
		arr2d[1] = damn1;
		arr2d[2] = damn2;
		arr2d[3] = damn3;
		for (int l = 0; l != 3; l++)
		{
			for (int a = 0; a != 2; a++)
			{
				std::cout << "this is arr2d[" << l << "] vlaue[" << a << "]: " << arr2d[l][a] << std::endl;
			}
		}
		arr2dcpy = arr2d;
		for (int i = 0; i != 6; i++)
		{
			for (int a = 0; a != 2; a++)
			{
				std::cout << "this is arr2dcpy[" << i << "] vlaue[" << a << "]: " << arr2dcpy[i][a] << std::endl;
			}
		}
		std::cout << "HELLO!" << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "**********************************" << std::endl;
	Array<std::string>		arrstring(5);
	std::cout << "Testing string array" << std::endl;
	std::cout << "1.	The sieze of empty arrstring(5): " << arr2d.size() << std::endl;
	std::cout << "2.	Accsesing out of bound memory. arrstringcpy(arrstring) " << std::endl;
	try 
	{
		std::string	test = "Hellow World";
		for (float i = 0; i != 5; i++)
		{
			arrstring[i] = test;
			std::cout << arrstring[i] << std::endl;
		}
		Array<std::string>		arrstringcpy(arrstring);
		
		for (float i = 0; i != 6; i++)
		{
			std::cout << arrstringcpy[i] << std::endl;
		}
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
