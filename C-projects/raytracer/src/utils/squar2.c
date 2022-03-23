/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   squar2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:19:36 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/04/30 12:19:36 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parcer.h"
#include "minRT.h"

char	ft_sq_con2(t_sq **sq, t_pars_vars *vars, char hit_dig)
{
	if (hit_dig == 1)
		return (fl_parce(&(*sq)->cor.x, vars));
	if (hit_dig == 2)
		return (fl_parce(&(*sq)->cor.y, vars));
	if (hit_dig == 3)
		return (fl_parce(&(*sq)->cor.z, vars));
	if (hit_dig == 4)
		return (fl_parce(&(*sq)->norm.x, vars));
	if (hit_dig == 5)
		return (fl_parce(&(*sq)->norm.y, vars));
	if (hit_dig == 6)
		return (fl_parce(&(*sq)->norm.z, vars));
	if (hit_dig == 7)
		return (fl_parce(&(*sq)->side_size, vars));
	if (hit_dig == 8)
		return (char_parce(&(*sq)->col.r, vars));
	if (hit_dig == 9)
		return (char_parce(&(*sq)->col.g, vars));
	if (hit_dig == 10)
		return (char_parce(&(*sq)->col.b, vars));
	return (1);
}

char	ft_sq_con(t_sq **sq, t_pars_vars *vars, char hit, char hit_dig)
{
	char	comma;

	comma = 0;
	while (vars->line[vars->i])
	{
		comma = ft_check_sq2(hit_dig, vars, comma);
		if ((comma == -1 || (hit_dig == 1 && comma == 0)))
			return (0);
		if (vars->line[vars->i] == 's')
			hit++;
		if (vars->line[vars->i] == 'q')
			hit++;
		if (ft_isfloat(vars->line[vars->i]))
		{
			hit_dig++;
			ft_sq_con2(sq, vars, hit_dig);
		}
		else
			vars->i++;
		if (!ft_check_sq(hit, hit_dig, vars->line[vars->i]))
			return (0);
	}
	return (hit_dig);
}

char	ft_check_sq2(char hit_dig, t_pars_vars *vars, char comma)
{
	if (hit_dig >= 1 && (vars->line[vars->i] == ','))
		comma++;
	if ((hit_dig == 1 && comma != 1) || (hit_dig == 2 && comma != 2))
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
	if (hit_dig == 8 && comma != 5)
		return (-1);
	if (hit_dig == 9 && comma != 6)
		return (-1);
	if (hit_dig == 10 && comma != 6)
		return (-1);
	if (comma == 7)
		return (-1);
	return (comma);
}
