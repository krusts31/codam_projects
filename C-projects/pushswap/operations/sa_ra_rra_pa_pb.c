/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sa_ra_rra_pa_pb.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 19:03:52 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/12/06 19:03:54 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	shift up dwon elements of stack a by 1
*/

void	rra(t_stack **a)
{
	t_stack		*old_head;
	t_stack		*new_head;
	t_stack		*one_before_last;
	const int	write_failed = -1;

	if (is_empty_stack(*a))
		return ;
	if ((*a)->next == NULL && (*a)->previus == NULL)
		return ;
	new_head = ft_last_stack(*a);
	one_before_last = new_head->previus;
	old_head = *a;
	*a = new_head;
	new_head->next = old_head;
	new_head->previus = NULL;
	old_head->previus = new_head;
	one_before_last->next = NULL;
	if (write_msg(RRA) == write_failed)
		print_error_and_exit("Error\nWrite Failed\n");
}
/*
**	shift up all elements of stack a by 1
*/

void	ra(t_stack **a)
{
	t_stack		*last;
	t_stack		*new_head;
	const int	write_failed = -1;

	if (is_empty_stack(*a))
		return ;
	if ((*a)->next == NULL && (*a)->previus == NULL)
		return ;
	new_head = (*a)->next;
	last = ft_last_stack(*a);
	last->next = *a;
	(*a)->previus = last;
	(*a)->next = NULL;
	*a = new_head;
	if (write_msg(RA) == write_failed)
		print_error_and_exit("Error\nWrite Failed\n");
}

/*
**	take the first element at the top of a and put it at the top of b
*/

void	pb(t_stack **a, t_stack **b)
{
	t_stack		*tmp;
	t_stack		*tmp_2;
	const int	write_failed = -1;

	if (*b == NULL)
	{
		tmp = (*a)->next;
		*b = *a;
		(*b)->next = NULL;
		(*b)->previus = NULL;
		*a = tmp;
	}
	else
	{
		tmp_2 = (*a)->next;
		tmp = *b;
		*b = *a;
		(*b)->next = tmp;
		tmp->previus = *b;
		*a = tmp_2;
	}
	if (write_msg(PB) == write_failed)
		print_error_and_exit("Error\nWrite Failed\n");
}

/*
**	take the first element at the top of b and put it at the top of a
*/

void	pa(t_stack **a, t_stack **b)
{
	t_stack		*tmp;
	t_stack		*tmp_2;
	const int	write_failed = -1;

	if (*a == NULL)
	{
		tmp = (*b)->next;
		*a = *b;
		(*a)->next = NULL;
		(*a)->previus = NULL;
		*b = tmp;
	}
	else
	{
		tmp_2 = (*b)->next;
		tmp = *a;
		*a = *b;
		(*a)->next = tmp;
		tmp->previus = *a;
		*b = tmp_2;
	}
	if (write_msg(PA) == write_failed)
		print_error_and_exit("Error\nWrite Failed\n");
}

/*
**	Swap 2 first elements on stack A
*/
void	sa(t_stack **a)
{
	t_stack		*tmp;
	t_stack		*tmp_next;
	t_stack		*tmp_next_next;
	const int	write_failed = -1;

	tmp = *a;
	tmp_next = (*a)->next;
	tmp_next_next = (*a)->next->next;
	*a = tmp_next;
	tmp_next->previus = NULL;
	tmp_next->next = tmp;
	tmp->previus = tmp_next;
	tmp->next = tmp_next_next;
	if (write_msg(SA) == write_failed)
		print_error_and_exit("Error\nWrite Failed\n");
}
