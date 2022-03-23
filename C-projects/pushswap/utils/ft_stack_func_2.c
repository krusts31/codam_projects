/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_stack_func_2.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 13:30:31 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/12/09 13:37:07 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_min_from_stack(t_stack *numbers)
{
	int		min;
	t_stack	*tmp;

	min = numbers->index;
	tmp = numbers;
	while (tmp)
	{
		if (tmp->index < min)
			min = tmp->index;
		tmp = tmp->next;
	}
	return (min);
}

int	ft_element_positon_by_index(t_stack *numbers, int index)
{
	t_stack	*tmp;
	int		pos;

	pos = 0;
	tmp = numbers;
	while (tmp)
	{
		if (tmp->index == index)
			return (pos);
		tmp = tmp->next;
		pos++;
	}
	return (-1);
}

int	ft_get_mid_from_stack(t_stack *numbers, int min, int max)
{
	int		mid;
	t_stack	*tmp;

	tmp = numbers;
	while (tmp)
	{
		if (tmp->index != max && tmp->index != min)
			mid = tmp->index;
		tmp = tmp->next;
	}
	return (mid);
}
