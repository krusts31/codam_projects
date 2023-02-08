/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils5.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:19:37 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/04/30 12:19:37 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minRT.h"

#include <stdio.h>
#include <stdlib.h>

size_t	light_obj_count(t_light *li)
{
	size_t	cnt;

	cnt = 0;
	while (li)
	{
		li = li->next;
		cnt++;
	}
	return (cnt);
}

void	init_mlx(t_data *d, t_task *t)
{
	d->mlx = mlx_init();
	if (d->mlx == NULL)
		exit(!(printf("Error\nutils5.c:22")));
	resize_screen(d);
	d->mlx_win = mlx_new_window(d->mlx, t->X_res, t->Y_res, "MINIRT");
	if (d->mlx_win == NULL)
		exit(!(printf("Error\nutils5.c:26")));
	d->img = mlx_new_image(d->mlx, t->X_res, t->Y_res);
	d->addr = mlx_get_data_addr(d->img, &(d->bits_per_pixel),
			&d->line_length, &d->endian);
}
