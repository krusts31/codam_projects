/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parce.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:19:36 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/04/30 12:19:36 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parcer.h"

char	parce_argv_2(char *argv, t_task *task)
{
	if (argv[0] != '-' || argv[1] != '-')
		return (0);
	if (argv[2] != 's' || argv[3] != 'a')
		return (0);
	if (argv[4] != 'v' || argv[5] != 'e')
		return (0);
	if (argv[6] != '\0')
		return (0);
	task->save = 1;
	return (1);
}

char	char_parce(unsigned char *col, t_pars_vars *vars)
{
	char			index;
	unsigned short	nr;
	unsigned char	fin;

	index = 0;
	nr = ft_atoi(vars->line + vars->i);
	if (nr > 255)
		return (0);
	fin = nr;
	while (ft_isdigit(vars->line[vars->i + (int)index]))
	{
		if (index > 3)
			return (0);
		index++;
	}
	*col = fin;
	vars->i += ft_intlen(*col);
	return (1);
}

static char	ft_cos(float *value, size_t index, size_t minuss)
{
	if ((index >= 9 && minuss == 0) || minuss >= 2)
		return (0);
	if (index >= 10 && minuss == 1)
		return (0);
	if (*value == 0.0)
		*value = 0.001;
	return (1);
}

char	fl_parce(float *value, t_pars_vars *vars)
{
	size_t	index;
	size_t	minuss;
	size_t	check;

	check = 0;
	minuss = 0;
	index = 0;
	*value = ft_atof(vars->line + vars->i);
	while (ft_isfloat(vars->line[vars->i]))
	{
		if ((vars->line[vars->i]) == '.')
			check++;
		if (check == 2)
			return (0);
		if (vars->line[vars->i] == '-')
			minuss++;
		if (!ft_cos(value, index, minuss))
			return (0);
		index++;
		vars->i++;
	}
	return (1);
}
