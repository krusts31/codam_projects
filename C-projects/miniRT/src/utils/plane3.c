/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   plane3.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:19:36 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/04/30 12:19:36 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minRT.h"

/*
**	A plane can be deffined by a normal(nx, ny, nz) vector and the distance(d)
**	from the origin
**	nx * x + ny * y + nz * z = d
**	have to watch out for devisoin with 0
*/

int	hit_pl(t_ray ray, t_hit *hit, t_pl pl)
{
	float	den;
	t_vec	test;
	float	t;

	den = dot_product(pl.norm, ray.v2);
	if (den == 0)
		den = 0.001;
	test = vec_minus_vec(pl.cor, ray.v1);
	t = dot_product(test, pl.norm) / den;
	if (t > 0.001 && t < hit->t)
	{
		hit->color.r = pl.col.r / 255.99;
		hit->color.g = pl.col.g / 255.99;
		hit->color.b = pl.col.b / 255.99;
		hit->t = t;
		hit->p = point_at_param(ray, t);
		hit->normal = pl.norm;
		return (1);
	}
	return (0);
}
