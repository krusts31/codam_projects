/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_bonus.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:20:48 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/04/30 12:20:48 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "varibles_bonus.h"

t_vec	cross_product(t_vec v1, t_vec v2)
{
	t_vec	new;

	new.x = (v1.y * v2.z - v1.z * v2.y);
	new.y = - (v1.x * v2.z - v1.z * v2.x);
	new.z = (v1.x * v2.y - v1.y * v2.x);
	return (new);
}

t_vec1	vec_times_num_3(t_vec1 v1, float num)
{
	t_vec1	new_v;

	new_v.r = v1.r * num;
	new_v.g = v1.g * num;
	new_v.b = v1.b * num;
	return (new_v);
}

t_vec1	vec_uc_times_num_3(t_vec_uc v1, float num)
{
	t_vec1	new_v;

	new_v.r = (float)v1.r * num;
	new_v.g = (float)v1.g * num;
	new_v.b = (float)v1.b * num;
	return (new_v);
}

t_vec1	vec_times_vec_3(t_vec1 v1, t_vec1 v2)
{
	t_vec1	new_v;

	new_v.r = v1.r * v2.r;
	new_v.g = v1.g * v2.g;
	new_v.b = v1.b * v2.b;
	return (new_v);
}

t_vec1	vec_div_vec_uc(t_vec1 v1, t_vec_uc v2)
{
	t_vec1	new_v;

	new_v.r = v1.r / v2.r;
	new_v.g = v1.g / v2.g;
	new_v.b = v1.b / v2.b;
	return (new_v);
}
