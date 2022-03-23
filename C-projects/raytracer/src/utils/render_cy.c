/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_cy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:19:36 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/04/30 12:19:36 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minRT.h"

#include <math.h>

static int	hit_cy_2(t_hit_cy i, t_cy cy, t_hit *hit, t_ray ray)
{
	i.vars[0] = sqrt(pow(cy.height / 2, 2) + pow(cy.radius / 2, 2));
	if (length_of_vector(i.vecs[1]) > i.vars[0])
	{
		i.vars[6] = i.vars[5];
		i.vecs[0] = point_at_param(ray, i.vars[6]);
		i.vecs[1] = vec_minus_vec(i.vecs[0], cy.cor);
		if (length_of_vector(i.vecs[1]) > i.vars[0])
			return (0);
	}
	if (i.vars[6] > hit->t)
		return (0);
	i.vars[1] = dot_product(cy.norm, vec_minus_vec(i.vecs[0], cy.cor));
	i.vecs[2] = vec_plus_vec(cy.cor, vec_times_num(cy.norm, i.vars[1]));
	hit->normal = unit_vec(vec_minus_vec(i.vecs[0], i.vecs[2]));
	hit->t = i.vars[6];
	hit->p = i.vecs[0];
	hit->color.r = cy.col.r / 255.99;
	hit->color.g = cy.col.g / 255.99;
	hit->color.b = cy.col.b / 255.99;
	return (1);
}

int	hit_cy(t_ray ray, t_hit *hit, t_cy cy)
{
	t_hit_cy	i;

	i.vecs[0] = vec_minus_vec(ray.v1, cy.cor);
	i.vecs[1] = cross_product(ray.v2, cy.norm);
	i.vars[0] = dot_product(i.vecs[1], i.vecs[1]);
	i.vecs[2] = cross_product(i.vecs[0], cy.norm);
	i.vars[1] = 2 * dot_product(i.vecs[1], i.vecs[2]);
	i.vars[2] = dot_product(i.vecs[2], i.vecs[2]) - pow(cy.radius / 2, 2);
	i.vars[3] = i.vars[1] * i.vars[1] - 4 * i.vars[0] * i.vars[2];
	if (i.vars[3] < 0)
		return (0);
	i.vars[4] = (-1.0 * i.vars[1] - sqrt(i.vars[3])) / (2 * i.vars[0]);
	i.vars[5] = (-1.0 * i.vars[1] + sqrt(i.vars[3])) / (2 * i.vars[0]);
	if (i.vars[5] < 0)
		return (0);
	if (i.vars[4] > 0)
		i.vars[6] = i.vars[4];
	else
		i.vars[6] = i.vars[5];
	i.vecs[0] = point_at_param(ray, i.vars[6]);
	i.vecs[1] = vec_minus_vec(i.vecs[0], cy.cor);
	return (hit_cy_2(i, cy, hit, ray));
}
