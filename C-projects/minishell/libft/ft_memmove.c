/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/23 15:59:34 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/07/11 17:10:13 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int			x;
	char		*desa;
	const char	*gala;

	x = (int)n - 1;
	desa = dest;
	gala = src;
	if (dest < src)
		ft_memcpy(dest, src, n);
	else if (dest > src)
	{
		while (x > 0)
		{
			desa++;
			gala++;
			x--;
		}
		ft_memrcpy(desa, gala, n);
	}
	else if (dest == NULL || src == NULL)
		return (NULL);
	return ((void *)dest);
}
