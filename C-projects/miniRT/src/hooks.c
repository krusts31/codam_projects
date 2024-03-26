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
