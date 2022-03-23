/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/23 15:57:05 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/07/11 17:35:53 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	x;
	size_t	y;

	y = 0;
	x = ft_strlen(s);
	ptr = ft_calloc(x + 1, sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (s[y])
	{
		ptr[y] = s[y];
		y++;
	}
	return (ptr);
}
