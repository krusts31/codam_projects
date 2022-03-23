/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera2.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:19:35 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/04/30 12:19:35 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parcer.h"

char	c_con2(t_cameraP **camera, t_pars_vars *vars, char hit_dig)
{
	if (hit_dig == 3)
		return (fl_parce(&(*camera)->cor.x, vars));
	if (hit_dig == 2)
		return (fl_parce(&(*camera)->cor.y, vars));
	if (hit_dig == 1)
		return (fl_parce(&(*camera)->cor.z, vars));
	if (hit_dig == 7)
		return (fl_parce(&(*camera)->FOV, vars));
	if (hit_dig == 6)
		return (fl_parce(&(*camera)->norm.x, vars));
	if (hit_dig == 5)
		return (fl_parce(&(*camera)->norm.y, vars));
	if (hit_dig == 4)
		return (fl_parce(&(*camera)->norm.z, vars));
	return (1);
}

char	c_con(t_cameraP **cam, t_pars_vars *vars, char hit, char hit_d)
{
	char	comma;

	comma = 0;
	while (vars->line[vars->i])
	{
		comma = ft_check_camera2(hit_d, vars, comma);
		if (comma == -1 || (hit_d == 1 && comma == 0))
			return (0);
		if (vars->line[vars->i] == 'c')
			hit++;
		if (ft_isfloat(vars->line[vars->i]))
		{
			hit_d++;
			c_con2(cam, vars, hit_d);
		}
		else
			vars->i++;
		if (!ft_check_camera(hit, hit_d, vars->line[vars->i]))
			return (0);
	}
	return (hit_d);
}

char	ft_check_camera2(char hit_dig, t_pars_vars *vars, char comma)
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
	if (comma == 5)
		return (-1);
	return (comma);
}
