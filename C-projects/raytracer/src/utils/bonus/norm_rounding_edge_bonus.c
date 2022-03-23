/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   norm_rounding_edge_bonus.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:20:47 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/04/30 12:20:47 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

#include <math.h>

static void	check_zeros(t_vec *norm)
{
	if (norm->x == 0.0)
		norm->x = 0.001;
	if (norm->y == 0.0)
		norm->y = 0.001;
	if (norm->z == 0.0)
		norm->z = 0.001;
}

int	norm_round(t_vec *norm, int round)
{
	float	x;	
	float	y;
	float	z;
	float	U;

	x = norm->x;
	y = norm->y;
	z = norm->z;
	U = sqrt(x * x + y * y + z * z);
	if (U != 1.0 && round == 0)
		return (0);
	check_zeros(norm);
	if (U == 1.0)
		return (1);
	norm->x = x / U;
	norm->y = y / U;
	norm->z = z / U;
	return (1);
}
