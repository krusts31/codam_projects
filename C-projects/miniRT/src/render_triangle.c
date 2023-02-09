/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_triangle.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:19:36 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/04/30 12:19:36 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minRT.h"

/*
**	(*hit_tr)->i is the plane and ray intersection
*/

static int	rend_tr_con(t_hit_tr *hit_tr, t_tr tr, t_ray ray)
{
	t_vec	edge;

	hit_tr->Q = point_at_param(ray, hit_tr->t);
	hit_tr->vec_Q_tr_edge = vec_minus_vec(hit_tr->Q, tr.cor1);
	edge = vec_minus_vec(tr.cor2, tr.cor1);
	hit_tr->testing = unit_vec(cross_product(edge, hit_tr->vec_Q_tr_edge));
	if (!(dot_product(hit_tr->testing, hit_tr->cross_AB_AC) >= 0))
		return (0);
	edge = vec_minus_vec(tr.cor3, tr.cor2);
	hit_tr->vec_Q_tr_edge = vec_minus_vec(hit_tr->Q, tr.cor2);
	hit_tr->testing = unit_vec(cross_product(edge, hit_tr->vec_Q_tr_edge));
	if (!(dot_product(hit_tr->testing, hit_tr->cross_AB_AC) >= 0))
		return (0);
	edge = vec_minus_vec(tr.cor1, tr.cor3);
	hit_tr->vec_Q_tr_edge = vec_minus_vec(hit_tr->Q, tr.cor3);
	hit_tr->testing = unit_vec(cross_product(edge, hit_tr->vec_Q_tr_edge));
	if (!(dot_product(hit_tr->testing, hit_tr->cross_AB_AC) >= 0))
		return (0);
	return (1);
}

static void	new_hit_tr(t_hit_tr *r, t_tr tr, t_ray ray)
{
	r->AB = vec_minus_vec(tr.cor2, tr.cor1);
	r->AC = vec_minus_vec(tr.cor1, tr.cor3);
	r->BC = vec_minus_vec(tr.cor3, tr.cor2);
	r->cross_AB_AC = unit_vec(cross_product(r->AC, r->AB));
	r->den = dot_product(r->cross_AB_AC, ray.v2);
	r->i = vec_minus_vec(tr.cor1, ray.v1);
	if (r->den == 0)
		r->den = 0.001;
	r->t = dot_product(r->i, r->cross_AB_AC) / r->den;
}

int	hit_tr(t_ray ray, t_hit *hit, t_tr tr)
{
	t_hit_tr	hit_tr;

	new_hit_tr(&hit_tr, tr, ray);
	if (hit_tr.t > 0.001 && hit_tr.t < hit->t)
	{
		if (!rend_tr_con(&hit_tr, tr, ray))
			return (0);
		hit->color.r = (float)tr.col.r / 255.99;
		hit->color.g = (float)tr.col.g / 255.99;
		hit->color.b = (float)tr.col.b / 255.99;
		hit->t = hit_tr.t;
		hit->normal = unit_vec(cross_product(hit_tr.AB, hit_tr.AC));
		hit->p = point_at_param(ray, hit_tr.t);
		return (1);
	}
	return (0);
}
