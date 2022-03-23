/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray_bonus.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:20:47 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/04/30 12:20:47 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

t_vec	point_at_parm_2(t_ray ray, float num)
{
	t_vec	new;

	new = vec_times_num(ray.v2, num);
	return (vec_plus_vec(ray.v1, new));
}

t_ray	new_ray(t_vec vec1, t_vec vec2)
{
	t_ray	new;

	new.v1 = vec1;
	new.v2 = vec2;
	return (new);
}

t_vec	point_at_param(t_ray ray, float t)
{
	t_vec	new;

	new = vec_times_num(ray.v2, t);
	return (vec_plus_vec(ray.v1, new));
}
