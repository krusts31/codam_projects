/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_initmem_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/23 16:03:20 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/06/03 14:38:30 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_init_mem(char const *s, char c, char **ptr)
{
	size_t	a;
	size_t	b;
	size_t	x;

	x = 0;
	b = 0;
	a = 0;
	while (s[a] != '\0')
	{
		while (s[a] != c && s[a] != '\0')
		{
			ptr[b][x] = s[a];
			x++;
			a++;
		}
		if (x > 0)
		{
			b++;
			x = 0;
		}
		else
			a++;
	}
	return (ptr);
}
