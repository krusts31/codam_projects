/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 19:04:02 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/12/06 19:59:30 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

#include <stdbool.h>
#include <limits.h>

long	ft_atoi_fin(long res)
{
	if (res > INT_MAX || res < INT_MIN)
		print_error_and_exit(ERROR_MSG);
	return (res);
}

long	ft_atoi2(const char *nptr)
{
	long int	res;
	int			negative;
	double		max;

	negative = 1;
	res = 0;
	max = INT_MAX;
	while (*nptr && (*nptr == ' ' || *nptr == '\n' || *nptr == '\t'
			|| *nptr == '\v' || *nptr == '\f' || *nptr == '\r'))
		nptr++;
	if (*nptr == '-')
		negative = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr && *nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + (*nptr - 48);
		if (max < 1 && negative < 0)
			print_error_and_exit(ERROR_MSG);
		else if (max < 1 && negative > 0)
			print_error_and_exit(ERROR_MSG);
		max = max / 10;
		nptr++;
	}
	return (ft_atoi_fin(res * negative));
}

void	check_duplicates(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*start;
	int		to_check;

	start = stack;
	while (start)
	{
		to_check = start->content;
		tmp = start;
		while (1)
		{
			tmp = tmp->next;
			if (tmp == NULL)
				break ;
			if (to_check == tmp->content)
				print_error_and_exit(ERROR_MSG);
		}
		start = start->next;
	}
}

void	check_for_non_int_values(char *argv)
{
	ft_atoi2(argv);
}

void	check_for_non_int_type(char *argv)
{
	size_t	index;

	index = 0;
	while (argv[index])
	{
		while (argv[index] && (argv[index] == ' '
				|| argv[index] == '\n' || argv[index] == '\t'
				|| argv[index] == '\v' || argv[index] == '\f'
				|| argv[index] == '\r'))
				index++;
		if (argv[index] == '+' || argv[index] == '-')
			index++;
		if (ft_isdigit(argv[index]) == false)
			print_error_and_exit(ERROR_MSG);
		break ;
	}
	while (argv[index])
	{
		if (ft_isdigit(argv[index]) == false)
			print_error_and_exit(ERROR_MSG);
		index++;
	}
}
