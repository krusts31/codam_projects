/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cameraCore_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:20:46 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/04/30 12:20:46 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
**	theta angle in radians
**	half_height is a hlaf of the X image plane
**	p is the amount of Y is X so then X * Y == hlaf width
**	var->w is the direction I am pointing the camera
*/

void	new_img_con(float FOV, float p, t_image_var *var, t_cameraP *c)
{
	var->theta = FOV * M_PI / 180;
	var->half_height = tan(var->theta / 2);
	var->half_width = p * var->half_height;
	var->w = (t_vec){0, 0, 0};
	var->w.x = -c->norm.x;
	var->w.y = -c->norm.y;
	var->w.z = -c->norm.z;
	var->u = unit_vec(cross_product((t_vec){0, 1, 0}, var->w));
	var->v = unit_vec(cross_product(var->u, var->w));
}

void	new_img_con2(t_image_plane **new, t_image_var *vari, t_cameraP *camera)
{
	vari->tmp = vec_times_num(vari->u, vari->half_width);
	vari->tmp2 = vec_times_num(vari->v, vari->half_height);
	(*new)->vertical = vec_times_num(vari->tmp2, 2);
	(*new)->horizontal = vec_times_num(vari->tmp, 2);
	vari->tmp3 = vec_minus_vec(camera->cor, vari->tmp);
	vari->tmp4 = vec_minus_vec(vari->tmp3, vari->tmp2);
	(*new)->upper_left = vec_minus_vec(vari->tmp4, vari->w);
}

/*
**	portion reflect how may Y pixels are in a on Row of X pixels
*/

t_image_plane	*new_image_plane(float FOV, float portion, t_cameraP *camera)
{
	t_image_plane	*new;
	t_image_var		var;

	new = ft_init_image_plane();
	new_img_con(FOV, portion, &var, camera);
	new_img_con2(&new, &var, camera);
	return (new);
}

static t_ray	free_get_ray(t_vec cor, t_vec fin)
{
	t_ray	new;

	new.v1 = cor;
	new.v2 = unit_vec(fin);
	return (new);
}

/*
**	cam->image->horizontal ==
**	cam->image->vertical ==
**	what cordinates does the camera ray have?
**	
*/

t_ray	get_ray(float u, float v, t_cameraP *cam)
{
	t_vec	sum_lower_hor;
	t_vec	fin;
	t_vec	tmp;
	t_vec	tmp1;
	t_vec	tmp3;

	tmp = vec_times_num(cam->image->horizontal, u);
	tmp1 = vec_times_num(cam->image->vertical, v);
	sum_lower_hor = vec_plus_vec(cam->image->upper_left, tmp);
	tmp3 = vec_minus_vec(tmp1, cam->cor);
	fin = vec_plus_vec(sum_lower_hor, tmp3);
	return (free_get_ray(cam->cor, fin));
}
