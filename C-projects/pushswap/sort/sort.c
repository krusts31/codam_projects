/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 19:04:45 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/12/06 19:04:48 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdlib.h>

static void	sort_small_stack(int size, t_stack **numbers)
{
	if (size == 2)
		sort_2_stack(numbers);
	if (size == 3)
		sort_3_stack(numbers);
	if (size == 4)
		sort_4_stack(numbers);
	if (size == 5)
		sort_5_stack(numbers);
	exit(0);
}

int	sort(t_stack **numbers)
{
	int	size;

	size = ft_stack_size(*numbers);
	if (size <= 5)
		sort_small_stack(size, numbers);
	else
		radix_sort(size, numbers);
	return (0);
}
