/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_long_len.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/14 13:58:14 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/11/14 14:48:21 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

int	ft_longlen(long nr)
{
	int	ret;

	ret = 0;
	if (nr == 0)
		return (1);
	if (nr == LONG_MIN)
		return (0);
	if (nr < 0)
	{
		nr = -nr;
		ret++;
	}
	while (nr >= 1)
	{
		ret++;
		nr = nr / 10;
	}
	return (ret);
}
