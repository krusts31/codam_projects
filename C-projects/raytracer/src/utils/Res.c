/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Res.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:15:26 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/04/30 12:20:24 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parcer.h"

#include <stdlib.h>
#include <stdio.h>

char	ft_check_res(char hit, char hit_dig, char b_char)
{
	if (hit == 0 && hit_dig == 1)
		return (0);
	if (!ft_strchr("0123456789R \n", b_char))
		return (0);
	if (hit == (char) 2)
		return (0);
	return (1);
}

/*
**	IS RES CONE BRAKEBLE?
//	WHAT IF HIT_D IS BIGGER THAN 3
**	BY PASSING HIT_D
*/

char	res_con(t_task *task, t_pars_vars *vars, char *hit, char hit_d)
{
	while (vars->line[vars->i])
	{
		if (vars->line[vars->i] == 'R')
			*hit = *hit + 1;
		if (ft_isdigit(vars->line[vars->i]))
		{
			hit_d++;
			if (hit_d == 1)
			{
				task->X_res = ft_atoi(vars->line + vars->i);
				vars->i += ft_size_t_len(task->X_res);
			}
			if (hit_d == 2)
			{
				task->Y_res = ft_atoi(vars->line + vars->i);
				vars->i += ft_size_t_len(task->Y_res);
			}
		}
		else
			vars->i++;
		if (!ft_check_res(*hit, hit_d, vars->line[vars->i]))
			return (0);
	}
	return (hit_d);
}

char	ft_parc_res(t_task *task, t_pars_vars *vars)
{
	static char	hitR = 0;
	char		hit_dig;

	hit_dig = 0;
	vars->i = 0;
	hit_dig = res_con(task, vars, &hitR, hit_dig);
	if (hit_dig != 2)
		exit(!printf("Error\non line: %ld\n", vars->line_cnt));
	if (task->X_res == 0 || task->Y_res == 0)
		exit(!printf("Error\non line: %ld\n", vars->line_cnt));
	vars->res = 1;
	return (1);
}
