#include "base.hpp"

Base	*generate(void)
{
	int	nr;

	nr = rand() % 3;
	if (nr == 0)
		return (new A());
	if (nr == 1)
		return (new B());
	if (nr == 2)
		return (new C());
	return (NULL);
}

void	identify_from_pointer(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void identify_from_reference(Base &p)
{
		if(dynamic_cast<A*>(&p))
			std::cout << "A" << std::endl;
		else if(dynamic_cast<B*>(&p))
			std::cout << "A" << std::endl;
		else if (dynamic_cast<C*>(&p))
			std::cout << "A" << std::endl;
}

int	main()
{
	srand(time(0));
	Base	*test;
	Base	*test1;
	Base	*test2;
	Base	*test3;
	Base	*test4;

	test = generate();
	test1 = generate();
	test2 = generate();
	test3 = generate();
	test4 = generate();

	identify_from_pointer(test);
	identify_from_pointer(test1);
	identify_from_pointer(test2);
	identify_from_pointer(test3);
	identify_from_pointer(test4);
	identify_from_reference(*test);
	identify_from_reference(*test1);
	identify_from_reference(*test2);
	identify_from_reference(*test3);
	identify_from_reference(*test4);
	delete (test);
	delete (test1);
	delete (test2);
	delete (test3);
	delete (test4);
	return (0);
}
