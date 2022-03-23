/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sphere3.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:19:36 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/04/30 12:19:36 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minRT.h"

#include <math.h>

static char	ft_calc_sphere2(t_hit *hit, float temp, t_sp sp, t_ray ray)
{
	hit->t = temp;
	hit->p = point_at_param(ray, hit->t);
	hit->normal = vec_minus_vec(hit->p, sp.cor);
	hit->color.r = sp.col.r / 255.99;
	hit->color.g = sp.col.g / 255.99;
	hit->color.b = sp.col.b / 255.99;
	return (1);
}

/*
**	hear I slove for the 2 spherer intersections 
**	the equatio is curatic so there are 2 possible
**	cases one + and -
**	see if you need to devide by 255.99 by removing the mutiplyer in main.c
**	devison by 255.99
*/

char	c_sp(t_hit *hit, t_hit_sp hit_sp, t_sp sp, t_ray ray)
{
	float	temp;

	temp = -1.0 * hit_sp.b - sqrt(hit_sp.disc) / hit_sp.a;
	if (temp < hit->t && temp > 0.001)
	{
		hit->t = temp;
		hit->p = point_at_param(ray, hit->t);
		hit->normal = vec_minus_vec(hit->p, sp.cor);
		hit->color.r = sp.col.r / 255.99;
		hit->color.g = sp.col.g / 255.99;
		hit->color.b = sp.col.b / 255.99;
		return (1);
	}
	temp = -1.0 * hit_sp.b + sqrt(hit_sp.disc) / hit_sp.a;
	if (temp < hit->t && temp > 0.001)
		return (ft_calc_sphere2(hit, temp, sp, ray));
	return (0);
}
