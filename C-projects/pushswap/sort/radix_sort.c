/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 19:04:30 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/12/07 17:49:30 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdbool.h>

static void	radix_sort_2(int index, t_stack **a, t_stack **b, int size)
{
	int	index_2;
	int	num;

	index_2 = 0;
	while (index_2 < size)
	{
		if (*a != NULL)
		{
			num = (*a)->index;
			if (((num >> index) & 1) == 1)
				ra(a);
			else
				pb(a, b);
		}
		index_2++;
	}
}

void	radix_sort(int size, t_stack **numbers)
{
	t_stack	*a;
	t_stack	*b;
	int		index;

	index = 0;
	a = *numbers;
	b = NULL;
	while (is_sorted(a) == false)
	{
		radix_sort_2(index, &a, &b, size);
		while (is_empty_stack(b) == false)
			pa(&a, &b);
		index++;
	}
}
