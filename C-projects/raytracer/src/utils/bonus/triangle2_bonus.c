/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   triangle2_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:20:48 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/04/30 12:20:48 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parcer_bonus.h"
#include "miniRT_bonus.h"

char	ft_tr_con2(t_tr **tr, t_pars_vars *vars, char hit_dig)
{
	if (hit_dig == 1)
		return (fl_parce(&(*tr)->cor1.x, vars));
	if (hit_dig == 2)
		return (fl_parce(&(*tr)->cor1.y, vars));
	if (hit_dig == 3)
		return (fl_parce(&(*tr)->cor1.z, vars));
	if (hit_dig == 4)
		return (fl_parce(&(*tr)->cor2.x, vars));
	if (hit_dig == 5)
		return (fl_parce(&(*tr)->cor2.y, vars));
	if (hit_dig == 6)
		return (fl_parce(&(*tr)->cor2.z, vars));
	if (hit_dig == 7)
		return (fl_parce(&(*tr)->cor3.x, vars));
	if (hit_dig == 8)
		return (fl_parce(&(*tr)->cor3.y, vars));
	if (hit_dig == 9)
		return (fl_parce(&(*tr)->cor3.z, vars));
	if (hit_dig == 10)
		return (char_parce(&(*tr)->col.r, vars));
	if (hit_dig == 11)
		return (char_parce(&(*tr)->col.g, vars));
	if (hit_dig == 12)
		return (char_parce(&(*tr)->col.b, vars));
	return (1);
}

char	ft_tr_con(t_tr **tr, t_pars_vars *vars, char hit, char hit_dig)
{
	char	comma;

	comma = 0;
	while (vars->line[vars->i])
	{
		comma = ft_check_tr2(hit_dig, vars, comma);
		if ((comma == -1 || comma == 9) || (hit_dig == 1 && comma == 0))
			return (0);
		if (vars->line[vars->i] == 't')
			hit++;
		if (vars->line[vars->i] == 'r')
			hit++;
		if (ft_isfloat(vars->line[vars->i]))
		{
			hit_dig++;
			ft_tr_con2(tr, vars, hit_dig);
		}
		else
			vars->i++;
		if (!ft_check_tr(hit, hit_dig, vars->line[vars->i]))
			return (0);
	}
	return (hit_dig);
}

char	ft_check_tr2(char hit_dig, t_pars_vars *vars, char comma)
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
	if (hit_dig == 7 && comma != 5)
		return (-1);
	if (hit_dig == 8 && comma != 6)
		return (-1);
	return (ft_check_tr3(hit_dig, comma));
}

char	ft_check_tr3(char hit_dig, char comma)
{
	if (hit_dig == 9 && comma != 6)
		return (-1);
	if (hit_dig == 10 && comma != 7)
		return (-1);
	if (hit_dig == 11 && comma != 8)
		return (-1);
	if (hit_dig == 12 && comma != 8)
		return (-1);
	if (comma == 9)
		return (-1);
	return (comma);
}
