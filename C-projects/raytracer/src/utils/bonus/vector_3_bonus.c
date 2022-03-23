/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_3_bonus.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:20:48 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/04/30 12:20:48 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

t_vec1	vec_plus_vec_3(t_vec1 v1, t_vec1 v2)
{
	t_vec1	new;

	new.r = v1.r + v2.r;
	new.g = v1.g + v2.g;
	new.b = v1.b + v2.b;
	return (new);
}

t_vec1	vec_div_num_3(t_vec1 v1, float num)
{
	t_vec1	new;

	new.r = v1.r / num;
	new.g = v1.g / num;
	new.b = v1.b / num;
	return (new);
}

t_vec1	vec_times_vec2(t_vec1 v1, t_vec1 v2)
{
	t_vec1	new;

	new.r = v1.r * v2.r;
	new.g = v1.g * v2.g;
	new.b = v1.b * v2.b;
	return (new);
}

t_vec1	vec_uc_times_num2(t_vec1 v1, float num)
{
	t_vec1	new;

	new.r = v1.r * num;
	new.g = v1.g * num;
	new.b = v1.b * num;
	return (new);
}

t_vec	vec_div_num(t_vec v1, float num)
{
	t_vec	new;

	new.x = v1.x / num;
	new.y = v1.y / num;
	new.z = v1.z / num;
	return (new);
}
