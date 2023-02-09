/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lighting_pl.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:19:35 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/04/30 12:19:35 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minRT.h"

/*
*/

static void	pl_light_2(t_lights *li, t_task *task)
{
	t_vec	tmp;

	li->light_vec = unit_vec(vec_minus_vec(li->hit.p, task->light->cor));
	li->side = dot_product(li->hit.normal, li->ray.v2);
	tmp = unit_vec(vec_minus_vec(task->light->cor, li->hit.p));
	li->shadow = new_ray(li->hit.p, tmp);
	li->diff = dot_product(li->light_vec, li->hit.normal);
	li->go = 1;
	if (li->diff > 0.0 && li->side > 0.0)
	{
		li->hit.p = vec_plus_vec(li->hit.p,
				vec_times_num(li->hit.normal, -1e-6));
	}
	else if (li->diff < 0.0 && li->side < 0.0)
	{
		li->hit.p = vec_plus_vec(li->hit.p,
				vec_times_num(li->hit.normal, 1e-6));
	}
	else
		li->go = 0;
	if (li->diff < 0.0)
		li->diff = -li->diff;
	if (li->diff > 1.0)
		li->diff = 1.0;
	li->hit.t = length_of_vector(vec_minus_vec(li->hit.p, task->light->cor));
}

t_vec1	pl_light(t_lights li, t_task task)
{
	float	c;

	while (task.light)
	{
		pl_light_2(&li, &task);
		if (!shade(li.shadow, task, li.hit))
		{
			if (li.go == 1)
			{
				c = light_coef(&li, &(li).hit, li.ray, &task);
				if (add_sc(&li.hit.diffuse, diff_light(li.hit, *task.light, c)))
					return (free_l(li.hit.specular, li.hit.diffuse));
				if (li.spec > 0.0)
					if (add_sc(&li.hit.specular, specular(li.spec, &task)))
						return (free_l(li.hit.specular, li.hit.diffuse));
			}
		}
		task.light = task.light->next;
	}
	return (finito(&li.hit, task));
}
