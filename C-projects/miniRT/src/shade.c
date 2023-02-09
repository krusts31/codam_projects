/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shade.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:19:36 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/04/30 12:19:36 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minRT.h"

static int	shade3(t_ray shadow, t_task task, t_hit *hit)
{
	t_sq	*sq;

	sq = task.sq;
	while (sq)
	{
		if (hit_sq(shadow, hit, *sq))
			return (1);
		sq = sq->next;
	}
	return (0);
}

static int	shade2(t_ray shadow, t_task task, t_hit *hit)
{
	t_tr	*tr;
	t_cy	*cy;

	tr = task.tr;
	while (tr)
	{
		if (hit_tr(shadow, hit, *tr))
			return (1);
		tr = tr->next;
	}
	cy = task.cy;
	while (cy)
	{
		if (hit_cy(shadow, hit, *cy))
			return (1);
		cy = cy->next;
	}
	return (shade3(shadow, task, hit));
}

int	shade(t_ray shadow, t_task task, t_hit hit)
{
	t_sp	*sp;
	t_pl	*pl;

	pl = task.pl;
	sp = task.sp;
	while (pl)
	{
		if (hit_pl(shadow, &hit, *pl))
			return (1);
		pl = pl->next;
	}
	while (sp)
	{
		if (hit_sp(shadow, &hit, *sp))
			return (1);
		sp = sp->next;
	}
	return (shade2(shadow, task, &hit));
}
