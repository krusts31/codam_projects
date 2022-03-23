#include "Serialize.hpp"

void	gen_random_alphanum(char *s, const int len)
{
	static const char alphanum[] =
	"0123456789"
	"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	"abcdefghijklmnopqrstuvwxyz";

	for (int i = 0; i < len; ++i)
	{
		s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
	}
}

void	gen_random_alpha(char *s, const int len)
{
	
	static const char alpha[] =
	"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	"abcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i < len; ++i)
	{
		s[i] = alpha[rand() % (sizeof(alpha) - 1)];
	}
}

void	gen_int(int	&num)
{
	int	flip;

	flip = rand() % 2;
	num = rand() % 2147483647; 
	if (flip == 0)
	{
		num = -num;
		num--;
	}
}

void	*serialize(void)
{
	char	*data = new(std::nothrow) char[16 + sizeof(int)];

	if (!data)
		throw ("Failed to allocate memory!");
	gen_random_alphanum(data, 8);
	gen_int(*reinterpret_cast<int *>(data + 8));
	gen_random_alpha(data + 8 + sizeof(int), 8);
	return (data);
}

Data	*deserialize(void *raw)
{
	Data *data = new Data();
	if (!data)
		throw ("Failed to allocate memory!");
	char *c = reinterpret_cast<char *>(raw);

	data->s1 = std::string(c, 8);
	data->n = *reinterpret_cast<int *>(c + 8);
	data->s2 = std::string(c + 8 + sizeof(int), 8);

	return (data);
}

int	main()
{
	void	*ptr;
	Data	*data;
	srand(time(0));

	try
	{
		ptr = serialize();
		std::cout << "this is the serialized value: " << ptr << std::endl;
		data = deserialize(ptr);
		std::cout << "this us the deseialized first string: " << data->s1 << std::endl;
		std::cout << "this us the deseialized number: " << data->n << std::endl;
		std::cout << "this us the deseialized string: " << data->s2 << std::endl;
		delete data;	
	}
	catch(std::exception const &e)
	{
		std::cout << e.what() << std::endl;
		return (-1);
	}
	return (0);
}
