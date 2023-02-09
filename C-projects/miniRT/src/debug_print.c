/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug_print.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:19:35 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/04/30 12:19:35 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minRT.h"

#include <stdio.h>

static void	print_debug_sq(t_sq *sq)
{
	size_t	count;

	count = 0;
	if (sq == NULL)
		printf("NO SQUARE\n");
	while (sq)
	{
		printf("**SQ %ld\n", count);
		printf("cor x: %f\n", sq->cor.x);
		printf("cor y: %f\n", sq->cor.y);
		printf("cor z: %f\n", sq->cor.z);
		printf("norm x: %f\n", sq->norm.x);
		printf("norm y: %f\n", sq->norm.y);
		printf("norm z: %f\n", sq->norm.z);
		printf("col r: %i\n", sq->col.r);
		printf("col g: %i\n", sq->col.g);
		printf("col b: %i\n", sq->col.b);
		printf("side size: %f\n", sq->side_size);
		printf("rotation: %f\n", sq->rotation);
		sq = sq->next;
		count++;
	}
}

static void	print_debug_pl(t_pl *pl)
{
	size_t	count;

	count = 0;
	if (pl == NULL)
		printf("NO PLANE\n");
	while (pl)
	{
		printf("**PL %ld\n", count);
		printf("cor x: %f\n", pl->cor.x);
		printf("cor y: %f\n", pl->cor.y);
		printf("cor z: %f\n", pl->cor.z);
		printf("norm x: %f\n", pl->norm.x);
		printf("norm y: %f\n", pl->norm.y);
		printf("norm z: %f\n", pl->norm.z);
		printf("col r: %i\n", pl->col.r);
		printf("col g: %i\n", pl->col.g);
		printf("col b: %i\n", pl->col.b);
		pl = pl->next;
		count++;
	}
}

static void	print_debug_cy(t_cy *cy)
{
	size_t	count;

	count = 0;
	if (cy == NULL)
		printf("NO CYLINDER\n");
	while (cy)
	{
		printf("**CY %ld\n", count);
		printf("cor x: %f\n", cy->cor.x);
		printf("cor y: %f\n", cy->cor.y);
		printf("cor z: %f\n", cy->cor.z);
		printf("norm x: %f\n", cy->norm.x);
		printf("norm y: %f\n", cy->norm.y);
		printf("norm z: %f\n", cy->norm.z);
		printf("col x: %i\n", cy->col.r);
		printf("col y: %i\n", cy->col.g);
		printf("col z: %i\n", cy->col.b);
		printf("radius: %f\n", cy->radius);
		printf("height: %f\n", cy->height);
		cy = cy->next;
		count++;
	}
}

static void	print_debug_sp(t_sp *sp)
{
	size_t	count;

	count = 0;
	if (sp == NULL)
		printf("NO SPHEAR\n");
	while (sp)
	{
		printf("**SP %ld\n", count);
		printf("cor x: %f\n", sp->cor.x);
		printf("cor y: %f\n", sp->cor.y);
		printf("cor z: %f\n", sp->cor.z);
		printf("col x: %i\n", sp->col.r);
		printf("col y: %i\n", sp->col.g);
		printf("col z: %i\n", sp->col.b);
		printf("diameter: %f\n", sp->radius);
		sp = sp->next;
		count++;
	}
}

void	print_debug(t_task *task)
{
	if (task == NULL)
		return ;
	printf("**RES*\n");
	printf("X: res %ld\n", task->X_res);
	printf("Y: res %ld\n", task->Y_res);
	printf("******\n");
	printf("**AMB*\n");
	printf("AMB: r %i\n", task->Amb_light.col.r);
	printf("AMB: g %i\n", task->Amb_light.col.g);
	printf("AMB: b %i\n", task->Amb_light.col.b);
	printf("AMB: ratio %f\n", task->Amb_light.ratio);
	printf("******\n");
	print_debug_sq(task->sq);
	print_debug_pl(task->pl);
	print_debug_cy(task->cy);
	print_debug_sp(task->sp);
	print_debug_tr(task, task->tr);
}
