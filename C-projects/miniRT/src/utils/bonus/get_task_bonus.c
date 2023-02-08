/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_task_bonus.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:20:46 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/04/30 12:20:46 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parcer_bonus.h"
#include "miniRT_bonus.h"
#include "get_next_line_bonus.h"

#include <string.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>

void	free_var(t_pars_vars *vars)
{
	if (vars->res == 0 || vars->ambient == 0)
		exit(!printf("Error\nNo res or ambient given!\n"));
	if (vars != NULL)
		free(vars->line);
}

int	ft_parce_args2(t_task *task, t_pars_vars *vars)
{
	if (ft_strchr(vars->line, 'l') && !ft_strchr(vars->line, 'p'))
		ft_parc_light(task, vars);
	if (ft_strchr(vars->line, 's') && ft_strchr(vars->line, 'p'))
		ft_parc_sp(task, vars);
	if (ft_strchr(vars->line, 'l') && ft_strchr(vars->line, 'p'))
		ft_parc_pl(task, vars);
	if (ft_strchr(vars->line, 's') && ft_strchr(vars->line, 'q'))
		ft_parc_sq(task, vars);
	if (ft_strchr(vars->line, 't') && ft_strchr(vars->line, 'r'))
		ft_parc_tr(task, vars);
	if (ft_strchr(vars->line, 'c') && ft_strchr(vars->line, 'y'))
		ft_parc_cy(task, vars);
	vars->line_cnt++;
	free(vars->line);
	vars->line = NULL;
	if (vars->ret == 0)
		return (0);
	return (1);
}

int	ft_parce_args(t_task *task, t_pars_vars *vars)
{
	while (1)
	{
		vars->ret = get_next_line(vars->fd, &vars->line);
		if (vars->ret == -1)
			exit(!printf("Error\nGet next line failed!\n"));
		if (ft_strchr(vars->line, '#'))
		{
			vars->line_cnt++;
			free(vars->line);
			vars->line = ft_strdup("");
			if (vars->line == NULL)
				exit(!printf("Error\nget_task.c:54\n"));
		}
		if (ft_strchr(vars->line, 'R'))
			ft_parc_res(task, vars);
		if (ft_strchr(vars->line, 'A'))
			ft_parc_Amb(task, vars);
		if (ft_strchr(vars->line, 'c') && !ft_strchr(vars->line, 'y'))
			ft_parc_camera(task, vars);
		if (!ft_parce_args2(task, vars))
			return (0);
	}
	return (1);
}

char	parce_argv_1(char *argv)
{
	size_t	index;

	index = 0;
	while (argv[index] != '\0')
	{
		if (index == INT_MAX)
			return (0);
		index++;
	}
	if (index < 2)
		return (0);
	if ((argv[index - 1] != 't') || (argv[index - 2] != 'r'))
		return (0);
	if (argv[index - 3] != '.')
		return (0);
	return (1);
}

int	new_task(int argc, char **argv, t_task *task)
{
	t_pars_vars	vars;

	if (argc == 1)
		exit(!printf("Error\nNot enough args\n"));
	if (argc > 3)
		exit(!printf("Error\nTo many args\n"));
	if (!parce_argv_1(argv[1]))
		exit(!printf("Error\n.rt filename to long or not a .rt file\n"));
	init(task, &vars);
	if (argv[2])
	{
		if (!parce_argv_2(argv[2], task))
			exit(!printf("Error\nBad seccond argv\n"));
	}
	else
		task->save = 0;
	vars.fd = open(argv[1], O_RDONLY);
	if (vars.fd == -1)
		exit(!printf("Error: %s\n", strerror(errno)));
	ft_parce_args(task, &vars);
	if (DEBUG)
		print_debug(task);
	free_var(&vars);
	return (1);
}
