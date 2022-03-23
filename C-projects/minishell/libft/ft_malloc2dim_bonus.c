/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_malloc2dim_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/23 16:00:22 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/05/23 16:00:24 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_malloc2dim(char const *s, char c, char **ptr)
{
	int	x;
	int	y;
	int	z;

	z = 0;
	y = 0;
	x = 0;
	while (s[x] != '\0')
	{
		if (s[x] != c)
			y++;
		x++;
		if ((s[x] == c && s[x + 1] != c && y > 0) || (s[x] == '\0' && y > 0))
		{
			ptr[z] = ft_calloc(sizeof(*(ptr[z])), (y + 1));
			if (ptr[z] == NULL)
				ft_spilt_check(&ptr);
			z++;
			y = 0;
		}
	}
	return (ptr);
}
