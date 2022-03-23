/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_take_forks.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/15 21:23:44 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/14 19:36:05 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

#include "parser.h"

/*
**	LEXER cheks if there are any non int values
**	PARSER set the information in the memmory and checks if there are any
**	negative values
**	ALLOC_HEAP_INIT_MUTECES alloactes all the data needed for philosophers
**	and init muteces to so we can lock them etc
**	MAKE_THREADS calls pthread_creat and starts the eating_sleeping_thinking
**	cycle
**	destroy_muteces will just destroy the muteces
**	free_template will call free on the head data
*/

int	main(int argc, char **argv)
{
	t_main_thread			template;
	const int				error = 1;
	const void 				*all_threads_created = NULL;

	if (lexer(argc, argv, NULL) == error
		|| parser(argc, argv, &template.programm_args) == error
		|| alloc_and_init_muteces(&template))
		return (1);
	if (make_threads(&template, 0) == all_threads_created)
		monitoring_thread(&template, 0);
	join_exited_thread(&template, 0, 0);
	destroy_muteces(&template, 0);
	free_template(&template);
	return (0);
}
