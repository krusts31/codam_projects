/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:19:36 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/04/30 12:19:36 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minRT.h"
#include "parcer.h"

#include <stdio.h>
#include <math.h>

/*
**	I am using a right handed coordinate system
**	the up vector is Y
**	the forawd vector is Z
**	the right vector is X
**	Draw init last argument supplys the amout of alliasing!
*/

int	draw_back_ground(void *img, t_task *task)
{
	unsigned int	ret;
	t_draw			d;
	int				x;
	int				y;

	d = init_draw(task->X_res, task->Y_res);
	y = d.y - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < d.x)
		{
			d.col = (t_vec1){0.0, 0.0, 0.0};
			get_color(task, &d, x, y);
			d.new_col = (t_vec1){sqrt(d.col.r), sqrt(d.col.g), sqrt(d.col.b)};
			d.result = cap_i(vec_times_num_2(d.new_col, 255.99), 0, 255);
			ret = create_trgb(d.result);
			my_mlx_pixel_put(img, x, y, ret);
			x++;
		}
		y--;
	}
	return (0);
}

/*
**	data contains all the informations needed to render the images
**	task in a pointer in data that contains the parameters of objects
**	draw_back_ground is the function that will render the iamge in to buf
*/

int	main(int argc, char **argv)
{
	t_data		data;

	new_task(argc, argv, &data.task);
	if (data.task.camera == NULL)
		exit(printf("Error\nNo Camera provided!\n"));
	init_mlx(&data, &data.task);
	draw_back_ground(&data.img, &data.task);
	if (data.task.save == 1)
		save_bmp(&data);
	else
		mlx_image_to_window(data.mlx, data.img, 0, 0);
	//mlx_loop_hook(data.mlx_win, 2, 1L << 0, hooks, &data);
	//mlx_loop_hook(data.mlx_win, 17, 1L << 13, close_red, &data);
	mlx_loop(data.mlx);
	return (0);
}
