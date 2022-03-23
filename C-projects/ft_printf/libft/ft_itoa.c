/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts.student@codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/20 11:35:12 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/07/11 17:38:34 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoa_extension(char *ps, int n)
{
	while (n > 0)
	{
		ps--;
		*ps = n % 10 + '0';
		n = n / 10;
	}
	return (ps);
}

static char	*ft_handel(int num)
{
	if (num == 0)
		return (ft_strdup("0"));
	if (num == -2147483648)
		return (ft_strdup("-2147483648"));
	return (NULL);
}

char		*ft_itoa(int n)
{
	int		length_of_n;
	char	*ret;
	char	*result;

	if (n == -2147483648 || n == 0)
		return (ft_handel(n));
	length_of_n = ft_intlen(n);
	ret = ft_calloc(length_of_n + 1, sizeof(char));
	if (ret == NULL)
		return (NULL);
	result = ret;
	if (n < 0)
	{
		n = -n;
		*ret = '-';
	}
	ret = ft_itoa_extension(ret + length_of_n, n);
	return (result);
}
