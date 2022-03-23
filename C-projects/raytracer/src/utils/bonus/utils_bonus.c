/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_bonus.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:20:48 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/04/30 12:20:48 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parcer_bonus.h"

#include <limits.h>

size_t	ft_isfloat(char fl)
{
	return (ft_isdigit(fl) || fl == '.' || fl == '-');
}

static float	ft_atof_con(const char *nptr, float res, float n, float max)
{
	float	add;
	float	nr;

	nr = 1.0;
	add = 0.0;
	nptr++;
	while (*nptr && *nptr >= '0' && *nptr <= '9')
	{
		add = (add * 10 + (*nptr - 48));
		if (max < 1 && n < 0)
			return (0);
		else if (max < 1 && n > 0)
			return (-1);
		max = max / 10;
		nptr++;
		nr *= 10.0;
	}
	add = add / nr;
	return ((res + add) * n);
}

static float	ft_check_float(const char *nptr, float res, float max, float n)
{
	while (*nptr && *nptr >= '0' && *nptr <= '9')
	{
		res = res * 10.0 + (*nptr - 48.0);
		if (max < 1.0 && n < 0.0)
			return (0.0);
		else if (max < 1.0 && n > 0.0)
			return (-1.0);
		max = max / 10.0;
		nptr++;
	}
	return (res);
}

float	ft_atof(const char *nptr)
{
	float			res;
	float			negative;
	float			max;

	negative = 1.0;
	res = 0.0;
	max = INT_MAX;
	while (*nptr && (ft_strchr(" \n\t\v\f\r", *nptr)))
		nptr++;
	negative = 1.0;
	if (*nptr == '-')
		negative = -1.0;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	res = ft_check_float(nptr, res, max, negative);
	while (*nptr && *nptr >= '0' && *nptr <= '9')
		nptr++;
	if (*nptr == '.')
		return (ft_atof_con(nptr, res, negative, max));
	return ((int)res * negative);
}
