/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_render.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:19:35 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/04/30 12:19:35 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "varibles.h"

t_draw	init_draw(int xs, int ys)
{
	t_draw	draw;

	draw.ray = (t_ray){(t_vec){0, 0, 0}, (t_vec){0, 0, 0}};
	draw.p = (t_vec){0, 0, 0};
	draw.col = (t_vec1){0, 0, 0};
	draw.new_col = (t_vec1){0, 0, 0};
	draw.result = (t_vec_i){0, 0, 0, 0};
	draw.x = xs;
	draw.y = ys;
	draw.u = 0;
	draw.v = 0;
	return (draw);
}
