/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   light2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:19:35 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/04/30 12:19:35 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parcer.h"
#include "minRT.h"

#include <stdlib.h>
#include <stdio.h>

void	ft_lstadd_back_l(t_light **lst, t_light *new)
{
	t_light	*tmp;

	if (new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp = ft_lstlast_l(*lst);
		tmp->next = new;
	}
}

t_light	*ft_lstlast_l(t_light *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_light	*ft_new_light(void)
{
	t_light	*tmp;

	tmp = malloc(sizeof(t_light));
	if (tmp == NULL)
		return (NULL);
	else if (tmp)
	{
		tmp->cor = (t_vec){0, 0, 0};
		tmp->col = (t_vec_uc){0, 0, 0};
		tmp->next = NULL;
	}
	return (tmp);
}

void	ft_parc_light(t_task *task, t_pars_vars *vars)
{
	char		hit;
	char		hit_dig;
	t_light		*tmp;

	hit_dig = 0;
	hit = 0;
	vars->i = 0;
	tmp = ft_new_light();
	if (tmp == NULL)
		exit(!printf("Error\nOut of memmort fT_new_light()!\n"));
	hit_dig = l_con(&tmp, vars, hit, hit_dig);
	if (hit_dig != 7)
		exit(!printf("Error\non line %ld\n", vars->line_cnt));
	ft_lstadd_back_l(&task->light, tmp);
}

char	ft_check_light(char hit, char hit_dig, char b_char)
{
	if (hit == 0 && hit_dig == 1)
		return (0);
	if (!ft_strchr("0123456789l-,. \n", b_char))
		return (0);
	if (hit == (char) 2)
		return (0);
	return (1);
}
