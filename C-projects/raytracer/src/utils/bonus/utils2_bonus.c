/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils2_bonus.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:20:48 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/04/30 12:20:48 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parcer_bonus.h"

void	free_pl(t_task *task)
{
	t_pl	*tmp;

	if (task != NULL)
	{
		while ((task)->pl)
		{
			tmp = (task)->pl->next;
			free((task)->pl);
			(task)->pl = tmp;
		}
	}
}

void	free_cy(t_task *task)
{
	t_cy	*tmp;

	if (task != NULL)
	{
		while ((task)->cy)
		{
			tmp = (task)->cy->next;
			free((task)->cy);
			(task)->cy = tmp;
		}
	}
}

void	free_sp(t_task *task)
{
	t_sp	*tmp;

	if (task != NULL)
	{
		while ((task)->sp)
		{
			tmp = (task)->sp->next;
			free((task)->sp);
			(task)->sp = tmp;
		}
	}
}

void	free_tr(t_task *task)
{
	t_tr	*tmp;

	if (task != NULL)
	{
		while ((task)->tr)
		{
			tmp = (task)->tr->next;
			free((task)->tr);
			(task)->tr = tmp;
		}
	}
}

void	free_light(t_task *task)
{
	t_light	*tmp;

	if (task != NULL)
	{
		while ((task)->light)
		{
			tmp = (task)->light->next;
			free((task)->light);
			(task)->light = tmp;
		}
	}
}
