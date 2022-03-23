/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_finish_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/23 16:03:30 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/06/23 13:58:01 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_skip(const char *s1, size_t x)
{
	char	*str1;

	str1 = (char *)s1;
	while (x > 0)
	{
		str1++;
		x--;
	}
	return (str1);
}

char		*ft_finish(const char *src, size_t lenght, size_t x)
{
	char	*dest;
	int		size;
	int		y;

	size = (int)(ft_strlen(src) - ((ft_strlen(src) - lenght) + x));
	if (size <= 0)
		return (NULL);
	dest = ft_calloc(size + 2, sizeof(char));
	if (dest == NULL)
		return (NULL);
	src = (const char *)ft_skip(src, x);
	y = 0;
	while (size + 1 > 0)
	{
		dest[y] = *src;
		y++;
		src++;
		size--;
	}
	dest[y] = '\0';
	return (dest);
}
