/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memrcpy_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/23 15:59:26 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/07/11 17:10:30 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_memrcpy(char *dest, const char *src, size_t x)
{
	while (x > 0)
	{
		*dest = *src;
		dest--;
		src--;
		x--;
	}
	return (dest);
}
