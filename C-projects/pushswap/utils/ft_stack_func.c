/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_stack_func.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 19:05:14 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/12/08 17:22:08 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_max_from_stack(t_stack *numbers)
{
	t_stack	*tmp;
	int		max;

	max = numbers->index;
	tmp = numbers;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}

void	ft_stack(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp = ft_last_stack(*lst);
		tmp->next = new;
		new->previus = tmp;
	}
}

t_stack	*ft_new_unit(int content)
{
	t_stack	*tmp;

	tmp = malloc_wrap(sizeof(t_stack), 1);
	tmp->content = content;
	tmp->index = -1;
	tmp->next = NULL;
	tmp->previus = NULL;
	return (tmp);
}

size_t	ft_stack_size(t_stack *lst)
{
	size_t	x;

	x = 0;
	while (lst != NULL)
	{
		x++;
		lst = lst->next;
	}
	return (x);
}

t_stack	*ft_new_unit_2(int index)
{
	t_stack	*tmp;

	tmp = malloc_wrap(sizeof(t_stack), 1);
	tmp->content = 0;
	tmp->index = index;
	tmp->next = NULL;
	tmp->previus = NULL;
	return (tmp);
}
