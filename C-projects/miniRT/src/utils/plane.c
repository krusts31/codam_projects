/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   plane.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:19:36 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/04/30 12:19:36 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parcer.h"
#include "minRT.h"

#include <stdio.h>

void	ft_lstadd_back_pl(t_pl **lst, t_pl *new)
{
	t_pl	*tmp;

	if (new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp = ft_lstlast_pl(*lst);
		tmp->next = new;
	}
}

t_pl	*ft_lstlast_pl(t_pl *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_pl	*ft_new_pl(void)
{
	t_pl	*tmp;

	tmp = malloc(sizeof(t_pl));
	if (tmp == NULL)
		return (NULL);
	else if (tmp)
	{
		tmp->cor = (t_vec){0, 0, 0};
		tmp->norm = (t_vec){0, 0, 0};
		tmp->col = (t_vec_uc){0, 0, 0};
		tmp->next = NULL;
	}
	return (tmp);
}

void	ft_parc_pl(t_task *task, t_pars_vars *vars)
{
	char	hit;
	char	hit_dig;
	t_pl	*tmp;

	hit_dig = 0;
	hit = 0;
	vars->i = 0;
	tmp = ft_new_pl();
	if (tmp == NULL)
		exit(!printf("Error\nOut of memmory ft_new_pl()\n"));
	hit_dig = pl_con(&tmp, vars, hit, hit_dig);
	if (hit_dig != 9)
		exit(!printf("Error\non line %ld\n", vars->line_cnt));
	norm_round(&tmp->norm);
	ft_lstadd_back_pl(&task->pl, tmp);
}

char	ft_check_pl(char hit, char hit_dig, char b_char)
{
	if (hit > 2 && hit_dig == 1)
		return (0);
	if (!ft_strchr("0123456789pl-,. \n", b_char))
		return (0);
	if (hit == (char) 3)
		return (0);
	return (1);
}
