#include <iostream>
#include "mutantStack.hpp"

int	main()
{
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "top element in the stac:" <<  mstack.top() << std::endl;

	mstack.pop();

	std::cout << "stack size: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);	
	mstack.push(0);


	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;

	while(it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << std::endl;

	std::cout << "**************************************************************" << std::endl;
	std::cout << "***************TESTING ASSIGMENT OPERATOR*********************" << std::endl;
	std::cout << "**************************************************************" << std::endl;
	MutantStack<int>	mstack2;

	mstack2 = mstack;

	it = mstack2.begin();
	ite = mstack2.end();
	while(it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << std::endl;
	MutantStack<int>::reverse_iterator itr = mstack.rbegin();
	MutantStack<int>::reverse_iterator iter = mstack.rend();
	while(itr != iter)
	{
		--iter;
		std::cout << *iter << std::endl;
	}
	std::cout << std::endl;
	MutantStack<int>::const_iterator itc = mstack.begin();
	MutantStack<int>::const_iterator itrc = mstack.end();
	while(itc != itrc)
	{
		std::cout << *itc << std::endl;
		itc++;
	}
	std::cout << "**************************************************************" << std::endl;
	std::cout << "***************TESTING COPY CONSTRUCTOR**********************" << std::endl;
	std::cout << "**************************************************************" << std::endl;

	MutantStack<int>	mstack3(mstack2);
	MutantStack<int>::iterator it2 = mstack3.begin();
	MutantStack<int>::iterator itr2 = mstack3.end();
	while(it2 != itr2)
	{
		std::cout << *it2 << std::endl;
		it2++;
	}
	return (0);	
}
