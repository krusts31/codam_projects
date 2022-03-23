/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   comparison_functions.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/09 13:03:27 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/12/09 13:36:25 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdbool.h>

bool	does_stack_need_to_be_ra(t_stack *numbers)
{
	int		max;
	int		min;
	int		mid;

	max = ft_get_max_from_stack(numbers);
	min = ft_get_min_from_stack(numbers);
	mid = ft_get_mid_from_stack(numbers, min, max);
	if (numbers->index == max && numbers->next->index == min
		&& numbers->next->next->index == mid)
		return (true);
	return (false);
}

bool	does_stack_need_to_be_sasara(t_stack *numbers)
{
	int		max;
	int		min;
	int		mid;

	max = ft_get_max_from_stack(numbers);
	min = ft_get_min_from_stack(numbers);
	mid = ft_get_mid_from_stack(numbers, min, max);
	if (numbers->index == max && numbers->next->index == mid
		&& numbers->next->next->index == min)
		return (true);
	return (false);
}

bool	does_stack_need_to_be_sa(t_stack *numbers)
{
	int		max;
	int		min;
	int		mid;

	max = ft_get_max_from_stack(numbers);
	min = ft_get_min_from_stack(numbers);
	mid = ft_get_mid_from_stack(numbers, min, max);
	if (numbers->index == mid && numbers->next->index == min
		&& numbers->next->next->index == max)
		return (true);
	return (false);
}

bool	does_stack_need_to_be_rra(t_stack *numbers)
{
	int		max;
	int		min;
	int		mid;

	max = ft_get_max_from_stack(numbers);
	min = ft_get_min_from_stack(numbers);
	mid = ft_get_mid_from_stack(numbers, min, max);
	if (numbers->index == mid && numbers->next->index == max
		&& numbers->next->next->index == min)
		return (true);
	return (false);
}

bool	does_stack_need_to_be_pbrapa(t_stack *numbers)
{
	int		max;
	int		min;
	int		mid;

	max = ft_get_max_from_stack(numbers);
	min = ft_get_min_from_stack(numbers);
	mid = ft_get_mid_from_stack(numbers, min, max);
	if (numbers->index == min && numbers->next->index == max
		&& numbers->next->next->index == mid)
		return (true);
	return (false);
}
