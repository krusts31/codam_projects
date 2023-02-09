/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split_check_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/23 15:57:24 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/07/10 19:05:53 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_free_2dim_array(char ***ptr)
{
	size_t	x;

	x = 0;
	while ((*ptr)[x])
	{
		free((*ptr[x]));
		*ptr[x] = NULL;
		x++;
	}
	free(*ptr);
	*ptr = NULL;
	return (NULL);
}
