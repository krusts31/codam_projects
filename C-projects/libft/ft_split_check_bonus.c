/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split_check_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/23 15:57:24 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/05/23 15:57:26 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_spilt_check(char ***ptr)
{
	int	x;

	x = 0;
	while ((*ptr)[x])
	{
		free((*ptr[x]));
		x++;
	}
	free(*ptr);
	return (NULL);
}
