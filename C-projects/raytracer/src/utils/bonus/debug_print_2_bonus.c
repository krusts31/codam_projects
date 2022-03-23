/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug_print_2_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:20:46 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/04/30 12:20:46 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

#include <stdio.h>

static void	print_debug_tr_2(t_tr *tr)
{
	printf("cor x: %f\n", tr->cor1.x);
	printf("cor y: %f\n", tr->cor1.y);
	printf("cor z: %f\n", tr->cor1.z);
	printf("cor_2 x: %f\n", tr->cor2.x);
	printf("cor_2 y: %f\n", tr->cor2.y);
	printf("cor_2 z: %f\n", tr->cor2.z);
	printf("cor_3 x: %f\n", tr->cor3.x);
	printf("cor_3 y: %f\n", tr->cor3.y);
	printf("cor_3 z: %f\n", tr->cor3.z);
	printf("col x: %i\n", tr->col.r);
	printf("col y: %i\n", tr->col.g);
	printf("col z: %i\n", tr->col.b);
}

static void	print_debug_light(t_light *light)
{
	size_t	count;

	count = 0;
	if (light == NULL)
		printf("NO LIGHT\n");
	while (light)
	{
		printf("**LIGHT %ld\n", count);
		printf("cor x: %f\n", light->cor.x);
		printf("cor y: %f\n", light->cor.y);
		printf("cor z: %f\n", light->cor.z);
		printf("col r: %i\n", light->col.r);
		printf("col g: %i\n", light->col.g);
		printf("col b: %i\n", light->col.b);
		printf("ratio: %f\n", light->ratio);
		light = light->next;
		count++;
	}
}

static void	print_debug_image_pl(t_image_plane *pl)
{
	size_t	count;

	count = 0;
	if (pl == NULL)
		printf("NO IMAGE PLAIN\n");
	printf("**IMAGE PLAIN\n");
	printf("up_left x: %f\n", pl->upper_left.x);
	printf("up_left y: %f\n", pl->upper_left.y);
	printf("up_left z: %f\n", pl->upper_left.z);
	printf("horizontal x: %f\n", pl->horizontal.x);
	printf("horizontal y: %f\n", pl->horizontal.y);
	printf("horizontal z: %f\n", pl->horizontal.z);
	printf("vertical x: %f\n", pl->vertical.x);
	printf("vertical y: %f\n", pl->vertical.y);
	printf("vertical z: %f\n", pl->vertical.z);
}

static void	print_debug_camera(t_cameraP *camera)
{
	size_t	count;

	count = 0;
	if (camera == NULL)
		printf("NO CAMERA\n");
	while (camera)
	{
		printf("**CAMERA %ld\n", count);
		printf("cor x: %f\n", camera->cor.x);
		printf("cor y: %f\n", camera->cor.y);
		printf("cor z: %f\n", camera->cor.z);
		printf("norm x: %f\n", camera->norm.x);
		printf("norm y: %f\n", camera->norm.y);
		printf("norm z: %f\n", camera->norm.z);
		printf("FOV: %f\n", camera->FOV);
		print_debug_image_pl(camera->image);
		camera = camera->next;
		count++;
	}
}

void	print_debug_tr(t_task *task, t_tr *tr)
{
	size_t	count;

	count = 0;
	if (tr == NULL)
		printf("NO TRIANGLE\n");
	while (tr)
	{
		printf("**TR %ld\n", count);
		print_debug_tr_2(tr);
		tr = tr->next;
		count++;
	}
	print_debug_light(task->light);
	print_debug_camera(task->camera);
}
