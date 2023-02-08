/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera_bonus.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:20:46 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/04/30 12:20:46 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parcer_bonus.h"
#include "miniRT_bonus.h"

#include <stdio.h>

void	ft_lstadd_back_c(t_cameraP **lst, t_cameraP *new)
{
	t_cameraP	*tmp;

	if (new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp = ft_lstlast_c(*lst);
		tmp->next = new;
	}
}

t_cameraP	*ft_lstlast_c(t_cameraP *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_cameraP	*ft_new_camera(void)
{
	t_cameraP	*tmp;

	tmp = malloc(sizeof(t_cameraP));
	if (tmp == NULL)
		return (NULL);
	else if (tmp)
	{
		tmp->cor = (t_vec){0, 0, 0};
		tmp->norm = (t_vec){0, 0, 0};
		tmp->FOV = 0.0;
		tmp->image = NULL;
		tmp->next = NULL;
	}
	return (tmp);
}

void	ft_parc_camera(t_task *task, t_pars_vars *vars)
{
	char		hit;
	char		hit_dig;
	t_cameraP	*tmp;

	hit_dig = 0;
	hit = 0;
	vars->i = 0;
	tmp = ft_new_camera();
	if (vars->res == 0)
		exit(!printf("Error\nCan't specifay camera with no res!\n"));
	if (tmp == NULL)
		exit(!printf("Error\ncamera.c:59!"));
	hit_dig = c_con(&tmp, vars, hit, hit_dig);
	if (hit_dig != 7)
		exit(!printf("Error\non line %ld\n", vars->line_cnt));
	tmp->image = new_image_plane(tmp->FOV, task->X_res / task->Y_res, tmp);
	if (tmp->image == NULL || tmp->FOV < 0 || tmp->FOV > 180)
		exit(!printf("Error\nImage error on line %ld\n", vars->line_cnt));
	norm_round(&tmp->norm, 1);
	ft_lstadd_back_c(&task->camera, tmp);
}

char	ft_check_camera(char hit, char hit_dig, char b_char)
{
	if (hit == 0 && hit_dig == 1)
		return (0);
	if (!ft_strchr("0123456789c-,. \n", b_char))
		return (0);
	if (hit == (char) 2)
		return (0);
	return (1);
}
