/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   squar_bonus.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:20:48 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/04/30 12:20:48 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parcer_bonus.h"
#include "miniRT_bonus.h"

#include <stdio.h>

void	ft_lstadd_back_sq(t_sq **lst, t_sq *new)
{
	t_sq	*tmp;

	if (new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp = ft_lstlast_sq(*lst);
		tmp->next = new;
	}
}

t_sq	*ft_lstlast_sq(t_sq *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_sq	*ft_new_sq(void)
{
	t_sq	*tmp;

	tmp = malloc(sizeof(t_sq));
	if (tmp == NULL)
		return (NULL);
	else if (tmp)
	{
		tmp->cor = (t_vec){0, 0, 0};
		tmp->col = (t_vec_uc){0, 0, 0};
		tmp->norm = (t_vec){0, 0, 0};
		tmp->side_size = 0.0;
		tmp->next = NULL;
	}
	return (tmp);
}

char	ft_parc_sq(t_task *task, t_pars_vars *vars)
{
	char	hit;
	char	hit_dig;
	t_sq	*tmp;

	hit_dig = 0;
	hit = 0;
	vars->i = 0;
	tmp = ft_new_sq();
	if (tmp == NULL)
		exit(!printf("Error\nout of memmory ft_new_sq()!\n"));
	hit_dig = ft_sq_con(&tmp, vars, hit, hit_dig);
	if (hit_dig != 10)
		exit(!printf("Error\non line %ld\n", vars->line_cnt));
	if (!norm_round(&tmp->norm, 1))
		exit(!printf("Error\nFix sq norm on line %ld\n", vars->line_cnt));
	ft_lstadd_back_sq(&task->sq, tmp);
	return (1);
}

char	ft_check_sq(char hit, char hit_dig, char b_char)
{
	if (hit > 2 && hit_dig == 1)
		return (0);
	if (!ft_strchr("0123456789sq-,. \n", b_char))
		return (0);
	if (hit == (char) 3)
		return (0);
	return (1);
}
