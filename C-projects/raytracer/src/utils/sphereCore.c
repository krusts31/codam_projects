/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sphereCore.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:19:36 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/04/30 12:19:36 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minRT.h"

#include <math.h>

/*
**	HOW DOES THE SPHERE AND RAY INTERSECTION WORK?
**	72: We get the toatal distance from sphere c to the
**	origin of the ray
**	74: dot product between the ->oc and ->v2(ray direction)
**	if the ->b >= 0 then there are no intersections
*/

//	we need to rewrite the parcer so that we dont use the diameter

int	hit_sp(t_ray ray, t_hit *hit, t_sp sp)
{
	t_hit_sp	hit_sp;

	hit_sp.oc = vec_minus_vec(ray.v1, sp.cor);
	hit_sp.a = dot_product(ray.v2, ray.v2);
	hit_sp.b = dot_product(hit_sp.oc, ray.v2);
	hit_sp.c = dot_product(hit_sp.oc, hit_sp.oc) - pow(sp.radius, 2);
	hit_sp.disc = hit_sp.b * hit_sp.b - hit_sp.a * hit_sp.c;
	if (hit_sp.disc >= 0.0)
		return (c_sp(hit, hit_sp, sp, ray));
	return (0);
}
