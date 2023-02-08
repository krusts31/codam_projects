/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_2_bonus.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:20:48 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/04/30 12:20:48 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "varibles_bonus.h"

//#include <stdio.h>
//      printf("%f %f %f\n", new_v.r, new_v.g, new_v.b);

float	length_of_vector_pow(t_vec s)
{
	return (s.x * s.x + s.y * s.y + s.z * s.z);
}

t_vec1	max_value_of_2_vec(t_vec1 v1, t_vec1 v2)
{
	t_vec1	new_v;

	new_v = (t_vec1){0, 0, 0};
	if (new_v.r < v1.r)
		new_v.r = v1.r;
	if (new_v.r < v2.r)
		new_v.r = v2.r;
	if (new_v.g < v1.g)
		new_v.g = v1.g;
	if (new_v.g < v2.g)
		new_v.g = v2.g;
	if (new_v.b < v1.b)
		new_v.b = v1.b;
	if (new_v.b < v2.b)
		new_v.b = v2.b;
	return (new_v);
}
