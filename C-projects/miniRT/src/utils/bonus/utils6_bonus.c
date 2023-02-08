/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils6_bonus.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:20:48 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/04/30 12:20:48 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "varibles_bonus.h"

#include <stdlib.h>

void	free_sc(t_sc *lst)
{
	t_sc	*tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}

static t_sc	*ft_lstlast_sc(t_sc *lst)
{
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

int	add_sc(t_sc **lst, t_sc *node)
{
	t_sc	*tmp;

	if (node == NULL)
		return (1);
	if (*lst == NULL)
		*lst = node;
	else
	{
		tmp = ft_lstlast_sc(*lst);
		tmp->next = node;
	}
	return (0);
}

t_sc	*ft_new_sc(void)
{
	t_sc	*tmp;

	tmp = malloc(sizeof(t_sc));
	if (tmp == NULL)
		return (NULL);
	tmp->color = (t_vec1){0, 0, 0};
	return (tmp);
}

t_vec_i	cap_i(t_vec1 v, float min, float max)
{
	t_vec_i	new;

	if (v.r > max)
		new.r = max;
	else if (v.r < min)
		new.r = min;
	else
		new.r = v.r;
	if (v.g > max)
		new.g = max;
	else if (v.g < min)
		new.g = min;
	else
		new.g = v.g;
	if (v.b > max)
		new.b = max;
	else if (v.b < min)
		new.b = min;
	else
		new.b = v.b;
	return (new);
}
