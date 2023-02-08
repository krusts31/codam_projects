# ft_printf

##### To use the lib

```sh
git clone
make
gcc main.c ./libftprintf.a
```

##### Example
```C
#include "ft_printf.h"

int	main()
{
	int	ret;

  ret =	ft_printf("p0 % .3s\n", "cccc");
  ret =	ft_printf("pp %.50d\n", 10000);
  ret =	ft_printf("p1 %.4s\n", "cccc");
  ret =	ft_printf("p2 %.10s\n", "cccc");
  ret =	ft_printf("p3 %.4s\n", NULL);
  ft_printf("%d", ret);
  return (0);
}
```

##### conversions:

`dcspiuxX%`

##### flags:

`-0.*0-9`

##### my jurney:
1. I learned about creating maps function pointer array.
