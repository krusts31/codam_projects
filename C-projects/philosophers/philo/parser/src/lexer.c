/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/30 17:19:45 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/01 12:01:47 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	lexer(int argc, char **argv, t_programm_args *parced_data)
{
	int			word;

	(void)parced_data;
	word = 1;
	if (argc <= 4)
		return (print_error_return_to_main("Error\nProgramm takes min 4 args"));
	if (argc > 7)
		return (print_error_return_to_main("Error\nProgramm takes max 5 args"));
	while (argv[word])
	{
		if (!is_int(argv[word]))
		{
			print_error_return_to_main("Error\nNot int\n");
			return (1);
		}
		word++;
	}
	return (0);
}
