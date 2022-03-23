/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_uitoa.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/14 13:16:45 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/12/06 21:06:17 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static	char	*ft_uitoa_extension(char *ps, long n)
{
	while (n > 0)
	{
		ps--;
		*ps = n % 10 + '0';
		n = n / 10;
	}
	return (ps);
}

static	char	*ft_handel(long num)
{
	if (num == 0)
		return (ft_strdup("0"));
	if (num == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	return (NULL);
}

char			*ft_uitoa(long n)
{
	long	rest;
	int		length_of_n;
	char	*ret;
	char	*result;

	rest = n;
	if (n == 0 || n == LONG_MIN)
		return (ft_handel(n));
	if (n < 0)
		rest = UINT_MAX + (n + 1);
	length_of_n = ft_longlen(rest);
	ret = ft_calloc(length_of_n + 1, sizeof(char));
	if (ret == NULL)
		return (NULL);
	result = ret;
	ret = ft_uitoa_extension(ret + length_of_n, rest);
	return (result);
}
