#include "minRT.h"

#include <stdio.h>
#include <stdlib.h>

/*	
**	t_camera TMP_CURENT IS A CAMERA POINTER THAT POINTS
**	TO TASK->CAMERA IT GETS USED NOT TO LOOS THE POINTER TO THE BEGGINING OF
**	TASK->CAMERA
*/

void		move_camera(t_cameraP **tmp_camera, char MOVE)
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

void		curent_cam(t_task *task, t_cameraP **tmp_camera)
{
	int		cnt;

	if (task->curent == ft_camera_size(*tmp_camera))
		task->curent = 0;
	if (task->curent == -1)
		task->curent = ft_camera_size(*tmp_camera) - 1;
	cnt = task->curent;
	while (cnt != 0)
	{
		*tmp_camera = (*tmp_camera)->next;
		cnt--;
	}
	if (task->MOVE != '!')
	{
		move_camera(tmp_camera, task->MOVE);
		task->MOVE = '!';
		free((*tmp_camera)->image);
		(*tmp_camera)->image = new_image_plane((*tmp_camera)->FOV, task->X_res / task->Y_res, *tmp_camera);
	}
}

/*
**	draw->ray is a camera ray shoth from tmp_curent
**	at (*darw)->u == x, (*darw)->v == y
**	
*/

void		get_color(t_task *task, t_draw *draw, int i, int j)
{
	int		s;
	t_vec1		tmp;
	t_cameraP	*tmp_camera;
	int		depth;

	tmp_camera = task->camera;
	curent_cam(task, &tmp_camera);
	depth = 0;
	s = 0;
//	while (s < draw->n)
//	{
//		draw->u = (i + drand48()) / draw->x;
//		draw->v = (j + drand48()) / draw->y;
		draw->u = (i + 0.99) / draw->x;
		draw->v = (j + 0.99) / draw->y;
		draw->ray = get_ray(draw->u, draw->v, tmp_camera);
		draw->p = point_at_param(draw->ray, 2.0);
		tmp = hitable_list(draw->ray, task);
		draw->col = vec_plus_vec_3(draw->col, tmp);
//		s++;
//	}
}
