/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/23 15:54:50 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/07/11 17:34:37 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	x;

	if (s == NULL)
		return (NULL);
	x = ft_strlen((char *)s);
	if (start >= ft_strlen((char *)s))
		return (ft_strdup(""));
	if (x - start < len)
		len = x - start;
	ptr = ft_calloc(len + 1, sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ptr = ft_memmove(ptr, s + start, len);
	return (ptr);
}
