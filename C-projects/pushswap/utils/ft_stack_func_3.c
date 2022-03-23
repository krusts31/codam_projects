/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_stack_func_3.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 19:05:20 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/12/06 19:05:22 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdbool.h>

bool	is_empty_stack(t_stack *stack)
{
	if (stack == NULL)
		return (true);
	else
		return (false);
}

bool	is_sorted(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		if (tmp == NULL)
			return (true);
		if (stack->index > tmp->index)
			return (false);
		stack = stack->next;
	}
	return (false);
}

int	get_top_element(t_stack *stack)
{
	while (stack)
		stack = stack->previus;
	return (stack->index);
}

int	get_max_bits(t_stack *A)
{
	int	max;
	int	max_bits;

	max = ft_get_max_from_stack(A) - 1;
	max_bits = 0;
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

t_stack	*ft_last_stack(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
