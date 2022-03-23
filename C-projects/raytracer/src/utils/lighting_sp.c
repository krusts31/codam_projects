/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lighting_sp.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:19:35 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/04/30 12:19:35 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minRT.h"

#include <math.h>

static void	sp_light_2(t_lights *lights, t_hit hit, t_task *task)
{
	lights->light_vec = unit_vec(vec_minus_vec(task->light->cor, hit.p));
	lights->shadow = new_ray(hit.p, lights->light_vec);
	lights->diff = dot_product(lights->light_vec, hit.normal);
	if (lights->diff > 1.0)
		lights->diff = 1.0;
}

t_vec1	sp_light(t_lights li, t_task task)
{
	float	c;

	while (task.light)
	{
		sp_light_2(&li, li.hit, &task);
		if (!shade(li.shadow, task, li.hit))
		{
			if (li.diff > 0.0)
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

int	hit_sp_loop(t_ray ray, t_hit *hit, t_task task)
{
	t_sp		*sp;
	t_lights	lights;

	sp = task.sp;
	while (sp)
	{
		if (hit_sp(ray, hit, *sp))
		{
			lights.spec = 0;
			lights.diff = 0;
			lights.hit = *hit;
			lights.ray = ray;
			hit->color = sp_light(lights, task);
		}
		sp = sp->next;
	}
	return (0);
}
