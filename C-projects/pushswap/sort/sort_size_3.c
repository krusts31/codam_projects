/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_size_3.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 19:05:06 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/12/09 13:23:14 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdbool.h>

void	sort_3_con(t_stack **numbers)
{
	t_stack	*b;

	b = NULL;
	if (does_stack_need_to_be_ra(*numbers))
		ra(numbers);
	else if (does_stack_need_to_be_sasara(*numbers))
	{
		sa(numbers);
		ra(numbers);
		ra(numbers);
	}
	else if (does_stack_need_to_be_sa(*numbers))
		sa(numbers);
	else if (does_stack_need_to_be_rra(*numbers))
		rra(numbers);
	else if (does_stack_need_to_be_pbrapa(*numbers))
	{
		pb(numbers, &b);
		ra(numbers);
		pa(numbers, &b);
	}
}

void	sort_3_stack(t_stack **numbers)
{
	if (is_sorted(*numbers) == false)
		sort_3_con(numbers);
}
