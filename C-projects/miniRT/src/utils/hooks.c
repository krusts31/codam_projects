/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:19:35 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/04/30 12:19:35 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minRT.h"

#include <limits.h>
#include <stdlib.h>

int	ft_camera_size(t_cameraP *cam)
{
	int	size;

	size = 0;
	if (cam == NULL)
		return (0);
	while (cam)
	{
		size++;
		if (size == INT_MAX)
			return (-1);
		cam = cam->next;
	}
	return (size);
}

/*
**	13 == w moves y + 1
**	1 == s moves y - 1
**	2 == d movec x + 1
**	0 == a moves x - 1
**	12 == q moves z - 1
**	14 == e moves z + 1
**		mlx_destroy_image(d->mlx, d->img);
**		mlx_destroy_image(d->mlx, d->img);
**		mlx_destroy_image(d->mlx, d->img);
*/

static int	hooks_2(int key, t_data *d)
{
	if (key == 12 || key == 1 || key == 2
		|| key == 0 || key == 13 || key == 14)
	{
		if (key == 13)
			d->task.MOVE = 'Y';
		if (key == 1)
			d->task.MOVE = 'y';
		if (key == 2)
			d->task.MOVE = 'X';
		if (key == 0)
			d->task.MOVE = 'x';
		if (key == 12)
			d->task.MOVE = 'z';
		if (key == 14)
			d->task.MOVE = 'Z';
		draw_back_ground(&d->img, &d->task);
		mlx_put_image_to_window(d->mlx, d->mlx_win, d->img, 0, 0);
	}
	return (0);
}

int	hooks(int key, t_data *d)
{
	if (key == 53)
	{
		mlx_destroy_image(d->mlx, d->img);
		mlx_destroy_window(d->mlx, d->mlx_win);
		exit(0);
	}
	if (key == 123)
	{
		d->task.curent = d->task.curent - 1;
		draw_back_ground(&d->img, &d->task);
		mlx_put_image_to_window(d->mlx, d->mlx_win, d->img, 0, 0);
	}
	if (key == 124)
	{
		d->task.curent = d->task.curent + 1;
		draw_back_ground(&d->img, &d->task);
		mlx_put_image_to_window(d->mlx, d->mlx_win, d->img, 0, 0);
	}
	return (hooks_2(key, d));
}

int	close_red(t_data *d)
{
	mlx_destroy_image(d->mlx, d->img);
	mlx_destroy_window(d->mlx, d->mlx_win);
	exit(0);
}
