/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/23 15:57:32 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/07/11 17:36:09 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_unique(const char *s, int c)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = ft_strlen(s);
	while (s[x] == c)
		x++;
	return (y - x);
}

static char	**ft_init_mem(char const *s, char c, char **ptr)
{
	size_t	a;
	size_t	b;
	size_t	x;

	x = 0;
	b = 0;
	a = 0;
	while (s[a] != '\0')
	{
		while (s[a] != c && s[a] != '\0')
		{
			ptr[b][x] = s[a];
			x++;
			a++;
		}
		if (x > 0 && ptr[b] != NULL)
		{
			b++;
			x = 0;
		}
		else if (s[a] != '\0')
			a++;
	}
	return (ptr);
}

static char	**ft_malloc1dim(char const *s, char c)
{
	int		x;
	int		hit;
	char	**dim1;

	hit = 0;
	x = 0;
	while (s[x] != '\0')
	{
		if ((s[x] == c && s[x + 1] != c) || (s[x] != c && s[x + 1] == '\0'))
			hit++;
		x++;
	}
	dim1 = ft_calloc((hit + 1), sizeof(*dim1));
	if (dim1 == NULL)
		return (NULL);
	return (dim1);
}

static char	**ft_malloc2dim(char const *s, char c, char **ptr)
{
	int	x;
	int	y;
	int	z;

	z = 0;
	y = 0;
	x = 0;
	while (s[x] != '\0')
	{
		if (s[x] != c)
			y++;
		if ((s[x] == c && s[x + 1] != c && y > 0) ||
				(s[x] != c && s[x + 1] == '\0'))
		{
			ptr[z] = ft_calloc(sizeof(char), (y + 1));
			if (ptr[z] == NULL)
				return (ft_free_2dim_array(&ptr));
			z++;
			y = 0;
		}
		x++;
	}
	return (ptr);
}

char		**ft_split(char const *s, char c)
{
	char	**ptr;

	if (s == NULL)
		return (NULL);
	if (c == '\0')
		return (ft_calloc(1, sizeof(char *)));
	if (!ft_unique(s, c))
		return (ft_calloc(1, sizeof(char *)));
	ptr = ft_malloc1dim(s, c);
	if (ptr == NULL)
		return (NULL);
	ptr = ft_malloc2dim(s, c, ptr);
	if (ptr == NULL)
		return (NULL);
	ptr = ft_init_mem(s, c, ptr);
	return (ptr);
}
