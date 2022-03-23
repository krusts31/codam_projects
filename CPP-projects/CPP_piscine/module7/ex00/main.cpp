#include <iostream>
#include <string>

template <typename T>
void		swap (T & a, T & x)
{
	T hold = a;
	a = x;
	x = hold;
}

template <typename X>
X 	min (X & a, X & z)
{
	if (a == z)
		return (z);
	else
		return (a < z ? a : z);
}

template <typename Z>
Z 	max (Z & a, Z & x)
{
	if (a == x)
		return (x);
	else
		return (a > x ? a : x);
}

template <typename X>
X	*min2 (X & a, X & z)
{
	if (a == z)
		return (&z);
	else
		return (a < z ? &a : &z);
}

template <typename Z>
Z	*max2 (Z & a, Z & x)
{
	if (a == x)
		return (&x);
	else
		return (a > x ? &a : &x);
}


int	main()
{
	/*
	**	Testing swap	
	*/

	int	a;
	int	x;
	std::string	name1;
	std::string	name2;
	char	b;
	char	z;
	float	f;
	float	f2;	

	f = 984.3123251327f;
	f2 = 42.4242f;
	b = 'b';
	z = 'z';
	name1 =	"Wubulaba dub dub!";
	name2 = "Well then, get your shit together. Get it all together. And put it in a backpack. All your shit. So it’s together.";
	a = 42;
	x = 8;
	std::cout << "***	***	***	Testing SWAP	***	***	***" << std::endl;
	std::cout << std::endl;
	std::cout << "***	***	***	Testing INT	***	***	***" << std::endl;
	std::cout << "The value of a: " << a << std::endl;
	std::cout << "The value of x: " << x << std::endl;
	swap(a, x);
	std::cout << "The value of a: " << a << std::endl;
	std::cout << "The value of x: " << x << std::endl;
	std::cout << "***	***	***	Testing STR	***	***	***" << std::endl;
	std::cout << "The value of name1: " << name1 << std::endl;
	std::cout << "The value of name2: " << name2 << std::endl;
	swap(name1, name2);
	std::cout << "The value of name1: " << name1 << std::endl;
	std::cout << "The value of name2: " << name2 << std::endl;
	std::cout << std::endl;
	std::cout << "***	***	***	***	***	***	***	***" << std::endl;
	std::cout << "***	***	***	Testing CHAR	***	***	***" << std::endl;
	std::cout << "The value of b: " << b << std::endl;
	std::cout << "The value of z: " << z << std::endl;
	swap(b, z);
	std::cout << "The value of b: " << b << std::endl;
	std::cout << "The value of z: " << z << std::endl;
	std::cout << std::endl;
	std::cout << "***	***	***	***	***	***	***	***" << std::endl;
	std::cout << "***	***	***	Testing FLOAT	***	***	***" << std::endl;
	std::cout << "The value of f: " << f << std::endl;
	std::cout << "The value of f2: " << f2 << std::endl;
	swap(f, f2);
	std::cout << "The value of f: " << f << std::endl;
	std::cout << "The value of f2: " << f2 << std::endl;
	std::cout << std::endl;
	std::cout << "***	***	***	***	***	***	***	***" << std::endl;
	std::cout << "***	***	***	Testing MIN	***	***	***" << std::endl;
	std::cout << std::endl;
	std::cout << "***	***	***	Testing INT	***	***	***" << std::endl;
	std::cout << "The value of a: " << a << std::endl;
	std::cout << "The value of x: " << x << std::endl;
	std::cout << "The min value is " << min(a, x) << std::endl;
	std::cout << "***	***	***	Testing STR	***	***	***" << std::endl;
	std::cout << "The value of name1: " << name1 << std::endl;
	std::cout << "The value of name2: " << name2 << std::endl;
	std::cout << "the min value is " << min(name1, name2) << std::endl;
	std::cout << std::endl;
	std::cout << "***	***	***	***	***	***	***	***" << std::endl;
	std::cout << "***	***	***	Testing CHAR	***	***	***" << std::endl;
	std::cout << "The value of b: " << b << std::endl;
	std::cout << "The value of z: " << z << std::endl;
	std::cout << "the min value is " << min(b, z) << std::endl;
	std::cout << "***	***	***	Testing FLOAT	***	***	***" << std::endl;
	std::cout << "The value of f: " << f << std::endl;
	std::cout << "The value of f2: " << f2 << std::endl;
	std::cout << "The min value is " << min(f, f2) << std::endl;
	std::cout << std::endl;
	std::cout << "***	***	***	***	***	***	***	***" << std::endl;
	std::cout << "***	***	***	Testing MAX	***	***	***" << std::endl;
	std::cout << std::endl;
	std::cout << "***	***	***	Testing INT	***	***	***" << std::endl;
	std::cout << "The value of a: " << a << std::endl;
	std::cout << "The value of x: " << x << std::endl;
	std::cout << "The max value is " << max(a, x) << std::endl;
	std::cout << "***	***	***	Testing STR	***	***	***" << std::endl;
	std::cout << "The value of name1: " << name1 << std::endl;
	std::cout << "The value of name2: " << name2 << std::endl;
	std::cout << "the max value is " << max(name1, name2) << std::endl;
	std::cout << std::endl;
	std::cout << "***	***	***	***	***	***	***	***" << std::endl;
	std::cout << "***	***	***	Testing CHAR	***	***	***" << std::endl;
	std::cout << "The value of b: " << b << std::endl;
	std::cout << "The value of z: " << z << std::endl;
	std::cout << "the max value is " << max(b, z) << std::endl;
	std::cout << "***	***	***	Testing FLOAT	***	***	***" << std::endl;
	std::cout << "The value of f: " << f << std::endl;
	std::cout << "The value of f2: " << f2 << std::endl;
	std::cout << "The max value is " << max(f, f2) << std::endl;
	std::cout << std::endl;
	std::cout << "***	***	***	***	***	***	***	***" << std::endl;
	std::cout << "***	***   Testing MAX with the same values  ***	***" << std::endl;
	int	l;
	int	m;
	l = 42;
	m = 42;
	std::cout << "The value of l: " << l << " memmory address: " << &l << std::endl;
	std::cout << "The value of m: " << m << " memmory address: " << &m << std::endl;
	std::cout << "The max value is " << max(l, m) << " memmory address(seccond arg m): " << max2(l, m) << std::endl;
	std::cout << "The min value is " << min(l, m) << " memmory address(seccond arg l): " << min2(m, l) << std::endl;
	std::cout << "***	***	***	***	***	***	***	***" << std::endl;
	return (0);
}
