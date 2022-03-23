/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colors2.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:19:35 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/04/30 12:19:35 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minRT.h"

#include <stdio.h>
#include <stdlib.h>

/*	
**	t_camera TMP_CURENT IS A CAMERA POINTER THAT POINTS
**	TO TASK->CAMERA IT GETS USED NOT TO LOOS THE POINTER TO THE BEGGINING OF
**	TASK->CAMERA
*/

void	move_camera(t_cameraP **tmp_camera, char MOVE)
{
	if (MOVE == 'x')
		(*tmp_camera)->cor.x -= 1;
	if (MOVE == 'X')
		(*tmp_camera)->cor.x += 1;
	if (MOVE == 'y')
		(*tmp_camera)->cor.y -= 1;
	if (MOVE == 'Y')
		(*tmp_camera)->cor.y += 1;
	if (MOVE == 'z')
		(*tmp_camera)->cor.z -= 1;
	if (MOVE == 'Z')
		(*tmp_camera)->cor.z += 1;
}

void	curent_cam(t_task *t, t_cameraP **tmp)
{
	int		cnt;

	if (t->curent == ft_camera_size(*tmp))
		t->curent = 0;
	if (t->curent == -1)
		t->curent = ft_camera_size(*tmp) - 1;
	cnt = t->curent;
	while (cnt != 0)
	{
		*tmp = (*tmp)->next;
		cnt--;
	}
	if (t->MOVE != '!')
	{
		move_camera(tmp, t->MOVE);
		t->MOVE = '!';
		free((*tmp)->image);
		(*tmp)->image = new_image_plane((*tmp)->FOV, t->X_res / t->Y_res, *tmp);
	}
}
/*
void	curent_cam(t_task *t, t_cameraP **tmp)
{
	int		cnt;

	if (t->curent == ft_camera_size(*tmp))
		t->curent = 0;
	if (t->curent == -1)
		t->curent = ft_camera_size(*tmp) - 1;
	cnt = t->curent;
	while (cnt != 0)
	{
		*tmp = (*tmp)->next;
		cnt--;
	}
}
*/
/*
**	draw->ray is a camera ray shoth from tmp_curent
**	at (*darw)->u == x, (*darw)->v == y
**	
*/

void	get_color(t_task *task, t_draw *draw, int i, int j)
{
	t_cameraP	*tmp_camera;

	tmp_camera = task->camera;
	curent_cam(task, &tmp_camera);
	draw->u = (i + 0.99) / draw->x;
	draw->v = (j + 0.99) / draw->y;
	draw->ray = get_ray(draw->u, draw->v, tmp_camera);
	draw->col = hitable_list(draw->ray, task);
}
