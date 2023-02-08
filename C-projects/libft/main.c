#include "libft.h"
#include <unistd.h>

int	main()
{
	char	*hello = "Hello ";
	char	*world = "World!";
	char	*hello_world;

	hello_world = ft_strjoin(hello, world);
	if (!hello_world)
		return (1);
	write(1, hello_world, ft_strlen(hello_world));
	return (0);
}
