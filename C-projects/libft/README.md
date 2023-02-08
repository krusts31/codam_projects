# libft

##### To use the lib

```sh
git clone
make
gcc main.c ./libft.a
```

##### Example
```C
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
```

### My journey

My very first library! This is also the first project I ever did at Codam.

I failed 13 times on this project! That's why I love 42, you can just retry and try again till you succeed. What I about:

1. I learned about the basics of Makefile.
2. The coding format standards.
3. How to handle user input.
4. I learned about interesting things in C like:

> INT OVERFLOWS
>
> DEREFERENCING NULL
> 
> MEMORY LEAKS
> 
> HEAP VS STACK
> 
> OUT-OF-BOUNDS MEMORY ACCESS

5. Learned about `\0` strings.
6. When to use memmove vs memcpy.
7. How to compile `.c` file into `.o` files.
8. How to link all the `.o` files into `.a` file.
9. The benefits of compiling with -Wall -Werror -Wextra..
10. Learned the basics of `gdb`, `lldb` and about `-g` and `-fsanitize=address`.
11. Learned about unnecessary header inclusion.
12. The basics of linked lists.
13. When to use header guards.
