/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_5_bonus.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:20:48 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/04/30 12:20:48 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "varibles_bonus.h"

t_vec	vec_uc_div_vec_2(t_vec v1, t_vec_uc v2)
{
	t_vec	new_v;

	new_v.x = v1.x / v2.r;
	new_v.y = v1.y / v2.g;
	new_v.z = v1.z / v2.b;
	return (new_v);
}

t_vec	vec_minus_vec_uc_2(t_vec v1, t_vec_uc v2)
{
	t_vec	new_v;

	new_v.x = v1.x - v2.r;
	new_v.y = v1.y - v2.g;
	new_v.z = v1.z - v2.b;
	return (new_v);
}

t_vec	vec_minus_vec(t_vec v1, t_vec v2)
{
	t_vec	new_v;

	new_v.x = v1.x - v2.x;
	new_v.y = v1.y - v2.y;
	new_v.z = v1.z - v2.z;
	return (new_v);
}

t_vec1	max_values_lst(t_sc *lst)
{
	t_vec1	ret;
	t_sc	*tmp;

	tmp = lst;
	ret = (t_vec1){0, 0, 0};
	while (tmp)
	{
		if (ret.r < tmp->color.r)
			ret.r = tmp->color.r;
		if (ret.g < tmp->color.g)
			ret.g = tmp->color.g;
		if (ret.b < tmp->color.b)
			ret.b = tmp->color.b;
		tmp = tmp->next;
	}
	return (ret);
}
