/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/19 22:41:30 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/07/11 17:35:34 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	j;

	if (src == NULL && dst == NULL)
		return (0);
	j = 0;
	srclen = ft_strlen(src);
	if (size == 0)
		return (srclen);
	else
		size = size - 1;
	while (src[j] != '\0' && size > 0)
	{
		dst[j] = src[j];
		j++;
		size--;
	}
	dst[j] = '\0';
	return (srclen);
}
