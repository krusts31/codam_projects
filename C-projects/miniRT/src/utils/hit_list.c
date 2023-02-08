/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hit_list.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:19:35 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/04/30 12:19:35 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minRT.h"

#include <limits.h>

void static	hit_cy_loop(t_ray ray, t_hit *hit, t_task task)
{
	t_cy		*cy;
	t_lights	lights;

	cy = task.cy;
	while (cy)
	{
		if (hit_cy(ray, hit, *cy))
		{
			lights.spec = 0;
			lights.diff = 0;
			lights.hit = *hit;
			lights.ray = ray;
			hit->color = cy_light(lights, task);
		}
		cy = cy->next;
	}
}

void static	hit_sq_loop(t_ray ray, t_hit *hit, t_task task)
{
	t_sq		*sq;
	t_lights	lights;

	sq = task.sq;
	while (sq)
	{
		if (hit_sq(ray, hit, *sq))
		{
			lights.spec = 0;
			lights.diff = 0;
			lights.hit = *hit;
			lights.ray = ray;
			hit->color = sq_light(lights, task);
		}
		sq = sq->next;
	}
}

static void	hit_tr_loop(t_ray ray, t_hit *hit, t_task task)
{
	t_tr		*tr;
	t_lights	lights;

	tr = task.tr;
	while (tr)
	{
		if (hit_tr(ray, hit, *tr))
		{
			lights.spec = 0;
			lights.diff = 0;
			lights.hit = *hit;
			lights.ray = ray;
			hit->color = tr_light(lights, task);
		}
		tr = tr->next;
	}
}

static void	hit_pl_loop(t_ray ray, t_hit *hit, t_task task)
{
	t_pl		*pl;
	t_lights	lights;

	pl = task.pl;
	while (pl)
	{
		if (hit_pl(ray, hit, *pl))
		{
			lights.spec = 0;
			lights.diff = 0;
			lights.hit = *hit;
			lights.ray = ray;
			hit->color = pl_light(lights, task);
		}
		pl = pl->next;
	}
}

t_vec1	hitable_list(t_ray ray, t_task *task)
{
	t_hit	hit;

	hit.color = (t_vec1){0, 0, 0};
	hit.t = INT_MAX;
	hit.diffuse = NULL;
	hit.specular = NULL;
	hit_sp_loop(ray, &hit, *task);
	hit_tr_loop(ray, &hit, *task);
	hit_cy_loop(ray, &hit, *task);
	hit_sq_loop(ray, &hit, *task);
	hit_pl_loop(ray, &hit, *task);
	return (hit.color);
}
