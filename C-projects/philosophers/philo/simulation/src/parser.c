/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_entry_from_main.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 16:04:37 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/02/25 12:14:03 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool	is_arg_negative(char *arg)
{
	if (ft_atoi(arg) < 0)
		return (true);
	return (false);
}

int	parser(int argc, char **argv, t_programm_args *parced_data)
{
	int	index;

	index = 1;
	while (index < argc)
	{
		if (is_arg_negative(argv[index]))
			return (1);
		index++;
	}
	if (argc == 5)
		parced_data->times_to_eat = -1;
	else
		parced_data->times_to_eat = ft_atoi(argv[5]);
	parced_data->number_of_philosophers = ft_atoi(argv[1]);
	parced_data->time_to_die = ft_atoi(argv[2]);
	parced_data->time_to_eat = ft_atoi(argv[3]);
	parced_data->time_to_sleep = ft_atoi(argv[4]);
	return (0);
}
