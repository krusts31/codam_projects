/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_4.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:19:37 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/04/30 12:19:37 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "varibles.h"

t_vec1	cap(t_vec1 v, float min, float max)
{
	t_vec1	new;

	if (v.r > max)
		new.r = max;
	else if (v.r < min)
		new.r = min;
	else
		new.r = v.r;
	if (v.g > max)
		new.g = max;
	else if (v.g < min)
		new.g = min;
	else
		new.g = v.g;
	if (v.b > max)
		new.b = max;
	else if (v.b < min)
		new.b = min;
	else
		new.b = v.b;
	return (new);
}

t_vec	vec_uc_times_num(t_vec_uc v1, float num)
{
	t_vec	new_v;

	new_v.x = v1.r * num;
	new_v.y = v1.g * num;
	new_v.z = v1.b * num;
	return (new_v);
}

t_vec	vec_plus_vec_2(t_vec v1, t_vec v2)
{
	t_vec	new_v;

	new_v.x = v1.x + v2.x;
	new_v.y = v1.y + v2.y;
	new_v.z = v1.z + v2.z;
	return (new_v);
}

t_vec	vec_times_vec_2(t_vec v1, t_vec v2)
{
	t_vec	new_v;

	new_v.x = v1.x * v2.x;
	new_v.y = v1.y * v2.y;
	new_v.z = v1.z * v2.z;
	return (new_v);
}

t_vec	vec_times_num(t_vec v1, float num)
{
	t_vec	new_v;

	new_v.x = v1.x * num;
	new_v.y = v1.y * num;
	new_v.z = v1.z * num;
	return (new_v);
}
