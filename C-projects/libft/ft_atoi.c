/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/23 15:53:07 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/07/11 17:38:43 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

int	ft_atoi(const char *nptr)
{
	long int	res;
	int			negative;
	long int	max;

	negative = 1;
	res = 0;
	max = LONG_MAX;
	while (*nptr && (*nptr == ' ' || *nptr == '\n' || *nptr == '\t' ||
			*nptr == '\v' || *nptr == '\f' || *nptr == '\r'))
		nptr++;
	if (*nptr == '-')
		negative = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr && *nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + (*nptr - 48);
		if (max < 1 && negative < 0)
			return (0);
		else if (max < 1 && negative > 0)
			return (-1);
		max = max / 10;
		nptr++;
	}
	return ((int)res * negative);
}
