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
#include "libft.h"

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

//	if (!(mlx = ))
//		return(EXIT_FAILURE);

	//TODO
	d->mlx = mlx_init(t->X_res, t->Y_res, "MLX42", true);
	if (d->mlx == NULL)
		exit(!(printf("Error\nutils5.c:22")));
	//resize_screen(d);
	//d->mlx_win = mlx_new_window(d->mlx,  "MINIRT");
	//if (d->mlx_win == NULL)
	//	exit(!(printf("Error\nutils5.c:26")));
	d->img = mlx_new_image(d->mlx, t->X_res, t->Y_res);
	if (!d->img)
		exit(!(printf("Error\nutils5.c:47")));
	ft_memset(d->img->pixels, 255, d->img->width * d->img->height * sizeof(int));
	//d->addr = mlx_get_data_addr(d->img, &(d->bits_per_pixel),
	//			&d->line_length, &d->endian);
}
