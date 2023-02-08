/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_for_light_2.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:19:37 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/04/30 12:19:37 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minRT.h"

#include <math.h>
#include <stdlib.h>

t_sc	*specular(float spec, t_task *task)
{
	t_vec1		s;
	t_sc		*specular;
	float		f;
	t_vec_uc	w;

	w = (t_vec_uc){255, 255, 255};
	f = task->light->ratio;
	specular = malloc(sizeof(t_sc) * 1);
	if (specular == NULL)
		return (NULL);
	s = vec_uc_times_num_3(w, spec * 0.00000002);
	specular->color = s;
	specular->next = NULL;
	return (specular);
}

float	max_from_float_arr(float *ptr, size_t cnt)
{
	size_t	biggest;

	biggest = 0;
	while (cnt != 0)
	{
		if (ptr[0] < ptr[biggest])
			ptr[0] = ptr[biggest];
		cnt--;
		biggest++;
	}
	if (ptr[0] >= 1)
		return (1);
	return (ptr[0]);
}

/*
**	Amb_intensity rgb color intensity at that given point
**	Amb_color is the light reflected from the point
**	since objects reflect the light that theye are
**	if we shine green light on a blue object it will
**	not be sean, hence vec_times_vec_2.
**	why are we using task->Amb_light->col?
**	printf("%f %f %f\n", Amb_reflected.r, Amb_reflected.g, Amb_reflected.b);
*/

t_vec1	light_Amb(t_hit hit, t_task task)
{
	t_vec1	Amb_i;
	t_vec1	Amb_reflected;

	Amb_i = vec_uc_times_num_3(task.Amb_light.col, task.Amb_light.ratio);
	Amb_reflected = cap(vec_times_vec_3(Amb_i, hit.color), 0, 255);
	return (cap(vec_div_vec_uc(Amb_reflected, task.Amb_light.col), 0, 1));
}

/*
**	DIFFUSE is dependant on the light source
**	some light source produce difuse lighting
**	some have a more laser type of look on the surface
**	you can think of it as a filter
**	#include <stdio.h>
**	printf("%f %f %f\n", test.r, test.g, test.b);
**	printf("%i %i %i\n", li.col.r, li.col.g, li.col.b);
**	do we need cap funtion hear
*/

t_sc	*diff_light(t_hit hit, t_light li, float coef)
{
	t_vec1	diff_reflected;
	t_vec1	diff_intensity;
	t_sc	*diffuse;

	diffuse = malloc(sizeof(t_sc));
	if (diffuse == NULL)
		return (NULL);
	diff_intensity = cap(vec_uc_times_num_3(li.col, coef), 0, 255);
	diff_reflected = cap(vec_times_vec_3(diff_intensity, hit.color), 0, 65025);
	diffuse->color = cap(vec_div_vec_uc(diff_reflected, li.col), 0, 1);
	diffuse->next = NULL;
	return (diffuse);
}

/*
**	sq_finito informal way of saying done or finished
**l = cap(vec_plus_vec_3(lights->max_spec, lights->max_diff), 0, 1);
**	so far we have a Ambient, diffuse, specular light maps*
**	Ambient returned by light_Amb
**	list diffuse of light hit->diffuse
**	list specular of lights hit->specular
**	by returning the bigest value of both lists
**	we are going to get the combined light at that point
*/

t_vec1	finito(t_hit *hit, t_task task)
{
	t_vec1	max_diff;
	t_vec1	max_spec;
	t_vec1	max_col;

	max_diff = cap(max_values_lst(hit->diffuse), 0, 1);
	max_spec = cap(max_values_lst(hit->specular), 0, 1);
	max_col = cap(max_value_of_2_vec(max_spec, max_diff), 0, 1);
	free_l(hit->specular, hit->diffuse);
	return (max_value_of_2_vec(light_Amb(*hit, task), max_col));
}
