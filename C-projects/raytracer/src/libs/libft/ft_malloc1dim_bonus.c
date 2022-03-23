/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_malloc1dim_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/23 16:00:30 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/06/23 13:54:57 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_malloc1dim(char const *s, char c)
{
	int		x;
	int		hit;
	char	**dim1;

	hit = 0;
	x = 0;
	while (s[x] != '\0')
	{
		if ((s[x] == c && s[x + 1] != c) || (s[x] != c && s[x + 1] == '\0'))
			hit++;
		x++;
	}
	dim1 = ft_calloc((hit + 1), sizeof(*dim1));
	if (dim1 == NULL)
		return (NULL);
	dim1[hit] = NULL;
	return (dim1);
}
