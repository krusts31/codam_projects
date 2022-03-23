/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_programm_args_in_template.c                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/01 18:02:20 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/02/25 19:21:03 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>

int	set_programm_args_in_template(int argc,
		char **argv,
		t_programm_args *template,
		int (**parser_func)(int argc, char **argv, t_programm_args *template))
{
	int	index;

	index = 0;
	while (parser_func[index] != NULL)
	{
		if (parser_func[index](argc, argv, template) == 1)
			return (1);
		index++;
	}
	return (0);
}
