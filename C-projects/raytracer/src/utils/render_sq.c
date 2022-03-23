/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_sq.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:19:36 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/04/30 12:19:36 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minRT.h"

static int	hit_sq2(t_hit_sq *sq_hit, t_ray ray, t_sq sq)
{
	sq_hit->tmp = (t_vec){0, 1, 0};
	sq_hit->span_b = unit_vec(cross_product(sq_hit->tmp, sq.norm));
	sq_hit->span_a = unit_vec(cross_product(sq_hit->span_b, sq.norm));
	sq_hit->span_b = unit_vec(cross_product(sq_hit->span_a, sq.norm));
	sq_hit->Q = point_at_param(ray, sq_hit->t);
	sq_hit->dis = vec_minus_vec(sq_hit->Q, sq.cor);
	sq_hit->abs = dot_product(sq_hit->dis, sq_hit->span_b);
	if (sq_hit->abs < 0)
		sq_hit->abs = -sq_hit->abs;
	if (sq_hit->abs > sq.side_size * 0.5)
		return (0);
	sq_hit->abs = dot_product(sq_hit->dis, sq_hit->span_a);
	if (sq_hit->abs < 0)
		sq_hit->abs = -sq_hit->abs;
	if (sq_hit->abs > sq.side_size * 0.5)
		return (0);
	return (1);
}

int	hit_sq(t_ray ray, t_hit *hit, t_sq sq)
{
	t_hit_sq	sq_hit;

	sq_hit.den = dot_product(sq.norm, ray.v2);
	if (sq_hit.den == 0)
		sq_hit.den = 0.001;
	sq_hit.test = vec_minus_vec(sq.cor, ray.v1);
	sq_hit.t = dot_product(sq_hit.test, sq.norm) / sq_hit.den;
	if (sq_hit.t > 0 && sq_hit.t < hit->t)
	{
		if (!hit_sq2(&sq_hit, ray, sq))
			return (0);
		hit->t = sq_hit.t;
		hit->color.r = sq.col.r / 255.99;
		hit->color.g = sq.col.g / 255.99;
		hit->color.b = sq.col.b / 255.99;
		hit->normal.x = sq.norm.x;
		hit->normal.y = sq.norm.y;
		hit->normal.z = sq.norm.z;
		hit->p = point_at_param(ray, sq_hit.t);
		hit->t = sq_hit.t;
		return (1);
	}
	return (0);
}
