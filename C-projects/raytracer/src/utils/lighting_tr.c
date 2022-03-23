/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lighting_tr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:19:35 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/04/30 12:19:35 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minRT.h"

static void	tr_light_2(t_lights *li, t_task *task)
{
	li->light_vec = unit_vec(vec_minus_vec(task->light->cor, li->hit.p));
	li->side = dot_product(li->hit.normal, li->ray.v2);
	li->shadow = new_ray(li->hit.p, li->light_vec);
	li->diff = dot_product(li->light_vec, li->hit.normal);
	if (li->diff > 0.0 && li->side < 0.0)
	{
		li->go = 1;
		li->hit.p = vec_plus_vec(li->hit.p,
				vec_times_num(li->hit.normal, 1e-6));
	}
	else if (li->diff < 0.0 && li->side > 0.0)
	{
		li->hit.p = vec_plus_vec(li->hit.p,
				vec_times_num(li->hit.normal, -1e-6));
		li->go = 1;
	}
	else
		li->go = 0;
	if (li->diff < 0.0)
		li->diff = -li->diff;
	if (li->diff > 1.0)
		li->diff = 1.0;
	li->hit.t = length_of_vector(vec_minus_vec(li->hit.p, task->light->cor));
}

t_vec1	tr_light(t_lights li, t_task task)
{
	float	c;

	while (task.light)
	{
		tr_light_2(&li, &task);
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
