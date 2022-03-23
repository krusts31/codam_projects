/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/23 16:00:04 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/07/11 17:38:14 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*src;
	size_t				x;

	x = 0;
	src = s;
	while (x < n)
	{
		if (src[x] == (unsigned char)c)
			return ((unsigned char *)s + x);
		x++;
	}
	return (NULL);
}
