/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_entry_from_main.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 19:04:20 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/12/07 17:43:14 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "libft.h"

#include <stdlib.h>

static void	free_args(char **args)
{
	int	index;

	index = 0;
	while (args[index])
	{
		free(args[index]);
		index++;
	}
	free(args);
}

static void	parcer_2(char **args, t_stack **numbers)
{
	int		index;
	t_stack	*tmp;
	int		ret;

	index = 0;
	while (args[index])
	{
		check_for_non_int_type(args[index]);
		check_for_non_int_values(args[index]);
		ret = ft_atoi(args[index]);
		tmp = ft_new_unit(ret);
		if (tmp == NULL)
			print_error_and_exit("Error\n malloc failed\n");
		ft_stack(numbers, tmp);
		index++;
	}
}

void	parcer(int argc, char **argv, t_stack **numbers)
{
	size_t	word;
	char	**args;

	if (argc <= 1)
		exit(1);
	word = 1;
	while (argv[word])
	{
		args = ft_split(argv[word], ' ');
		if (args == NULL)
			print_error_and_exit("Error\n malloc failed\n");
		parcer_2(args, numbers);
		free_args(args);
		word++;
	}
	check_duplicates(*numbers);
	index_stack(numbers, ft_stack_size(*numbers));
}
