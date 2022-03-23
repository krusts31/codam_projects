/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/23 15:55:04 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/07/11 17:34:43 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_finish(const char *src, size_t lenght, int x)
{
	char	*dest;
	int		y;
	int		size;

	size = ft_strlen(src) - lenght - x;
	dest = ft_calloc(size + 1, sizeof(char));
	if (dest == NULL)
		return (NULL);
	y = 0;
	src = src + x;
	while (size > 0)
	{
		dest[y] = *src;
		y++;
		src++;
		size--;
	}
	return (dest);
}

static char	*ft_search(const char *s1, const char *set, int x)
{
	const char	*goal;
	int			length;
	int			hit;
	size_t		size;

	size = 0;
	length = (int)(ft_strlen(s1) - 1);
	while (length > 0)
	{
		goal = set;
		hit = ft_compare(s1[length], goal);
		if (hit)
			size++;
		else
			return (ft_finish(s1, size, x));
		length--;
	}
	return (ft_strdup(s1));
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t		hit;
	const char	*holdsrc;
	size_t		x;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	x = 0;
	holdsrc = s1;
	while (*holdsrc != '\0')
	{
		hit = ft_compare(*holdsrc, set);
		if (hit)
			x++;
		else
			return (ft_search(s1, set, (int)x));
		holdsrc++;
	}
	return (ft_strdup(holdsrc));
}
