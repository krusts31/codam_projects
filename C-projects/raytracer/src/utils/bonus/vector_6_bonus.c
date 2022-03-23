/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_6_bonus.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:20:48 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/04/30 12:20:48 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

#include <math.h>

float	length_of_vector(t_vec s)
{
	return (sqrt(s.x * s.x + s.y * s.y + s.z * s.z));
}

t_vec	unit_vec(t_vec v)
{
	return (vec_div_num(v, length_of_vector(v)));
}

float	dot_product(t_vec v1, t_vec v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vec	vec_plus_vec(t_vec v1, t_vec v2)
{
	t_vec	new_v;

	new_v.x = v1.x + v2.x;
	new_v.y = v1.y + v2.y;
	new_v.z = v1.z + v2.z;
	return (new_v);
}

t_vec1	vec_times_num_2(t_vec1 v1, float num)
{
	t_vec1	new_v;

	new_v.r = v1.r * num;
	new_v.g = v1.g * num;
	new_v.b = v1.b * num;
	return (new_v);
}
