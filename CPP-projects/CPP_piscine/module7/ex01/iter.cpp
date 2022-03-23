#include <iostream>
#include <string>

template <typename T>
void	iter(T *arr, size_t len, void (*f)(T const &))
{
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
}
template <typename X>
void	print(X const &a)
{
	std::cout << a << std::endl;
}

int	main()
{
	int arr[3] = {1, 2, 3};
	float arrF[3] = {1.234f, 2.222214f, 3.12313f};
	std::string banzai[4] = {"wat", "is", "that", "jo"};
	const char wad[5] = {'c', '4', '.', '!', '2'};
	iter(arr, 3, print);
	iter(banzai, 4, print);
	iter(wad, 5, print);
	iter(arrF, 3, print);
	return (0);
}
