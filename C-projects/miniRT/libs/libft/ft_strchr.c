/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/23 15:57:13 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/07/11 17:36:02 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *str, int c)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
	{
		if (str[count] == (char)c)
			return ((char *)str + count);
		count++;
	}
	if (str[count] == (char)c)
		return ((char *)str + count);
	return (0);
}
