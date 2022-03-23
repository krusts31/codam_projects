/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   index_stack.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 19:04:15 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/12/06 19:04:16 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <limits.h>

static int	continue_index(t_stack **numbers, int min, int *index)
{
	t_stack	*tmp;

	tmp = *numbers;
	while (tmp)
	{
		if (tmp->content == min)
		{
			tmp->index = *index;
			*index = *index + 1;
			return (INT_MAX);
		}
		tmp = tmp->next;
	}
	return (INT_MAX);
}

void	index_stack(t_stack **numbers, int size)
{
	int		min;
	int		index;
	t_stack	*tmp;

	index = 0;
	min = (*numbers)->content;
	while (size)
	{
		tmp = *numbers;
		while (tmp)
		{
			if (min > tmp->content && tmp->index == -1)
				min = tmp->content;
			tmp = tmp->next;
		}
		min = continue_index(numbers, min, &index);
		size--;
	}
}
