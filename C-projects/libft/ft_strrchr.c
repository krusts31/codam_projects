/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/23 15:55:30 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/07/11 17:34:54 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	count;

	count = ft_strlen(str);
	while (count >= 0)
	{
		if (str[count] == (char)c)
			return ((char *)str + count);
		if (count == 0)
			return (0);
		count--;
	}
	return (0);
}
