/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 19:02:59 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/12/09 13:37:57 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define ERROR_MSG "Error\n"
# define PA "pa\n"
# define PB "pb\n"
# define RA "ra\n"
# define SA "sa\n"
# define RRA "rra\n"
# include <stddef.h>
# include <stdbool.h>

typedef struct s_stack_A
{
	struct s_stack_A	*next;
	struct s_stack_A	*previus;
	int					content;
	int					index;
}	t_stack;

/*
**	UTIL FUNCTIONS
*/

void	*malloc_wrap(size_t size, size_t amount);
void	print_error_and_exit(char *error_msg);
int		write_msg(char *msg);
int		write_error_msg(char *msg);

/*
**	PARCER
*/

void	parcer(int argc, char **argv, t_stack **numbers);
void	check_for_non_int_values(char *argv);
void	check_duplicates(t_stack *stack);
void	index_stack(t_stack **numbers, int siz);
void	check_for_non_int_type(char *argv);

/*
**	UTILS
*/

void	ft_stack(t_stack **lst, t_stack *new);
t_stack	*ft_new_unit(int content);
t_stack	*ft_last_stack(t_stack *lst);
t_stack	*ft_new_unit(int content);
int		ft_get_max_from_stack(t_stack *numbers);
int		ft_get_min_from_stack(t_stack *numbers);
int		ft_get_mid_from_stack(t_stack *numbers, int min, int max);
size_t	ft_stack_size(t_stack *lst);
t_stack	*ft_new_unit_2(int index);
bool	is_empty_stack(t_stack *stack);
bool	is_sorted(t_stack *stack);
int		get_max_bits(t_stack *A);
int		ft_element_positon_by_index(t_stack *numbers, int index);
bool	does_stack_need_to_be_ra(t_stack *numbers);
bool	does_stack_need_to_be_sasara(t_stack *numbers);
bool	does_stack_need_to_be_sa(t_stack *numbers);
bool	does_stack_need_to_be_rra(t_stack *numbers);
bool	does_stack_need_to_be_pbrapa(t_stack *numbers);

/*
**	SORT
*/

int		sort(t_stack **numbers);
void	sort_2_stack(t_stack **numbers);
void	sort_5_stack(t_stack **numbers);
void	sort_4_stack(t_stack **numbers);
void	sort_3_stack(t_stack **numbers);
void	radix_sort(int size, t_stack **numbers);

/*
**	swap/push
*/

void	ra(t_stack **a);
void	sa(t_stack **a);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	rra(t_stack **a);

/*
**	DEBUG
*/

void	print_stacks(t_stack *a, t_stack *b, int index);
void	print_before(t_stack *a, t_stack *b);
void	print_after(t_stack *a, t_stack *b);

#endif
