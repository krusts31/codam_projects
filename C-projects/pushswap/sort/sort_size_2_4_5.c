/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_size_2_4_5.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 19:04:58 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/12/09 13:35:54 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdbool.h>

static void	rotate_stack(t_stack **numbers, int pos_of_min)
{
	if (pos_of_min >= 3)
		rra(numbers);
	else
		ra(numbers);
}

void	sort_4_stack(t_stack **numbers)
{
	t_stack	*b;
	int		min;
	int		pos_of_min;

	b = NULL;
	min = ft_get_min_from_stack(*numbers);
	pos_of_min = ft_element_positon_by_index(*numbers, min);
	while (is_sorted(*numbers) == false)
	{
		if ((*numbers)->index == min)
		{
			pb(numbers, &b);
			sort_3_stack(numbers);
			pa(numbers, &b);
			if (is_sorted(*numbers) == true)
				return ;
			ra(numbers);
		}
		else
			rotate_stack(numbers, pos_of_min);
	}
}

void	sort_5_stack(t_stack **numbers)
{
	t_stack	*b;
	int		min;
	int		pos_of_min;

	b = NULL;
	min = ft_get_min_from_stack(*numbers);
	pos_of_min = ft_element_positon_by_index(*numbers, min);
	while (is_sorted(*numbers) == false)
	{
		if ((*numbers)->index == min)
		{
			pb(numbers, &b);
			sort_4_stack(numbers);
			pa(numbers, &b);
			if (is_sorted(*numbers) == true)
				return ;
			ra(numbers);
		}
		else
			rotate_stack(numbers, pos_of_min);
	}
}

void	sort_2_stack(t_stack **numbers)
{
	if (is_sorted(*numbers) == false)
		ra(numbers);
}
