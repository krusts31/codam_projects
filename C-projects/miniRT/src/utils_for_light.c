/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_for_light.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:19:37 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/04/30 12:19:37 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minRT.h"

/*
**	DIFF LIGHT
**	diff light does 2 operations
**	one:
**		calculates diffuse coeficient
**	tow:
**		calculates specular coefient
*/

float	light_coef(t_lights *li, t_hit *hit, t_ray ray, t_task *t)
{
	float	diff_coef;

	diff_coef = li->diff * t->light->ratio;
	if (diff_coef > 1.0)
		diff_coef = 1.0;
	hit->spec = specular_lighting(hit->normal, li->light_vec);
	li->spec = dot_product(hit->spec, ray.v2);
	return (diff_coef);
}

t_vec	specular_lighting(t_vec norm, t_vec light_vec)
{
	float	li_norm_proj;
	t_vec	norm_li_delta;

	li_norm_proj = 2 * dot_product(norm, light_vec);
	norm_li_delta = vec_minus_vec(norm, light_vec);
	return (vec_times_num(norm_li_delta, li_norm_proj));
}

t_vec	sum_of_light(t_vec *ptr, size_t index)
{
	t_vec	fin;

	fin = (t_vec){0, 0, 0};
	while (index)
	{
		fin = vec_plus_vec(ptr[index], fin);
		index--;
	}
	return (fin);
}
