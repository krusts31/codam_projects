/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils4.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:19:37 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/04/30 12:19:37 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parcer.h"
#include "minRT.h"

#include <stdio.h>

short	error(t_pars_vars *vars, short ret, t_task *task)
{
	if (task != NULL)
		free_task(task);
	if (vars != NULL)
		free_var(vars);
	return (ret);
}

char	free_task(t_task *task)
{
	if (task != NULL)
	{
		free_sq(task);
		free_pl(task);
		free_cy(task);
		free_sp(task);
		free_tr(task);
		free_light(task);
		free_camera(task);
	}
	return (-1);
}

void	init(t_task *task, t_pars_vars *vars)
{
	vars->line = NULL;
	vars->line_cnt = 0;
	vars->ret = 1;
	vars->i = 0;
	vars->fd = 0;
	vars->res = 0;
	vars->ambient = 0;
	task->sq = NULL;
	task->pl = NULL;
	task->cy = NULL;
	task->sp = NULL;
	task->tr = NULL;
	task->light = NULL;
	task->camera = NULL;
	task->curent = 0;
	task->save = 0;
	task->X_res = 0;
	task->Y_res = 0;
	task->MOVE = '!';
}

void	free_camera(t_task *task)
{
	t_cameraP	*tmp;

	if (task != NULL)
	{
		while (task->camera)
		{
			tmp = task->camera->next;
			free(task->camera->image);
			free(task->camera);
			task->camera = tmp;
		}
	}
}

t_vec1	free_l(t_sc *specular, t_sc *diffuse)
{
	void	*tmp;

	while (specular)
	{
		tmp = (void *)specular->next;
		free(specular);
		specular = (t_sc *)tmp;
	}
	while (diffuse)
	{
		tmp = (void *)diffuse->next;
		free(diffuse);
		diffuse = (t_sc *)tmp;
	}
	return ((t_vec1){-42, -42, -42});
}
