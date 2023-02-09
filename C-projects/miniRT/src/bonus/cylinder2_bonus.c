/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cylinder2_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:20:46 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/04/30 12:20:46 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parcer_bonus.h"
#include "miniRT_bonus.h"

char	ft_cy_con2(t_cy **cy, t_pars_vars *vars, char hit_dig)
{
	if (hit_dig == 1)
		return (fl_parce(&(*cy)->cor.x, vars));
	if (hit_dig == 2)
		return (fl_parce(&(*cy)->cor.y, vars));
	if (hit_dig == 3)
		return (fl_parce(&(*cy)->cor.z, vars));
	if (hit_dig == 4)
		return (fl_parce(&(*cy)->norm.x, vars));
	if (hit_dig == 5)
		return (fl_parce(&(*cy)->norm.y, vars));
	if (hit_dig == 6)
		return (fl_parce(&(*cy)->norm.z, vars));
	if (hit_dig == 7)
		return (fl_parce(&(*cy)->radius, vars));
	if (hit_dig == 8)
		return (fl_parce(&(*cy)->height, vars));
	if (hit_dig == 9)
		return (char_parce(&(*cy)->col.r, vars));
	if (hit_dig == 10)
		return (char_parce(&(*cy)->col.g, vars));
	if (hit_dig == 11)
		return (char_parce(&(*cy)->col.b, vars));
	return (1);
}

char	ft_cy_con(t_cy **cy, t_pars_vars *vars, char hit, char hit_dig)
{
	char	comma;

	comma = 0;
	while (vars->line[vars->i])
	{
		comma = ft_check_cy2(hit_dig, vars, comma);
		if ((comma == -1 || (hit_dig == 1 && comma == 0)))
			return (-1);
		if (vars->line[vars->i] == 'c')
			hit++;
		if (vars->line[vars->i] == 'y')
			hit++;
		if (ft_isfloat(vars->line[vars->i]))
		{
			hit_dig++;
			ft_cy_con2(cy, vars, hit_dig);
		}
		else
			vars->i++;
		if (!ft_check_cy(hit, hit_dig, vars->line[vars->i]))
			return (0);
	}
	return (hit_dig);
}

char	ft_check_cy2(char hit_dig, t_pars_vars *vars, char comma)
{
	if (hit_dig >= 1 && (vars->line[vars->i] == ','))
		comma++;
	if (hit_dig == 1 && comma != 1)
		return (-1);
	if (hit_dig == 2 && comma != 2)
		return (-1);
	if (hit_dig == 3 && comma != 2)
		return (-1);
	if (hit_dig == 4 && comma != 3)
		return (-1);
	if (hit_dig == 5 && comma != 4)
		return (-1);
	if (hit_dig == 6 && comma != 4)
		return (-1);
	if (hit_dig == 7 && comma != 4)
		return (-1);
	if (hit_dig == 8 && comma != 4)
		return (-1);
	return (ft_check_cy3(hit_dig, comma));
}

char	ft_check_cy3(char hit_dig, char comma)
{
	if (hit_dig == 9 && comma != 5)
		return (-1);
	if (hit_dig == 10 && comma != 6)
		return (-1);
	if (hit_dig == 11 && comma != 6)
		return (-1);
	if (comma == 7)
		return (-1);
	return (comma);
}
