/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/23 15:56:55 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/07/11 17:35:45 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*ptr;
	char	*ret;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	ptr = ft_calloc(len + 1, sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ret = ptr;
	ptr = ft_memcpy(ptr, s1, ft_strlen(s1));
	ptr = ft_memcpy(ptr + ft_strlen(s1), s2, ft_strlen(s2));
	return (ret);
}
