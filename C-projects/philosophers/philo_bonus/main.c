/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/05 15:18:33 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/14 20:12:38 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "parser.h"

#include <stdlib.h>

void	reset_index_sim(t_philosopher *philosopher)
{
	philosopher->index = 1;
}

/*
*  template->processes + 1 because we are going to set the last
*  one to 0 for keeping track if all phorses have done before
*  the parent process exits
*  (template->programm_args.number_of_philosophers + 1)
*  this is hadelend like this becauase we need to add one more
*  to the philosopher count because we are mallocing set's of 4 byts
*  and not one 1 byte
*/

void	start_simulation_odd(t_philosopher *philosopher)
{
	while (1)
	{
		set_take_forks(philosopher);
		take_forks(philosopher);
		set_eating(philosopher);
		eating(philosopher);
		let_go_forks(philosopher);
		set_sleeping(philosopher);
		sleeping(philosopher);
		set_thinking(philosopher);
		thinking(philosopher);
		reset_index_sim(philosopher);
	}
}

void	start_simulation_even(t_philosopher *philosopher)
{
	while (1)
	{
		set_sleeping(philosopher);
		sleeping(philosopher);
		set_thinking(philosopher);
		thinking(philosopher);
		set_take_forks(philosopher);
		take_forks(philosopher);
		set_eating(philosopher);
		eating(philosopher);
		let_go_forks(philosopher);
		reset_index_sim(philosopher);
	}
}

/*
 *	first we wait for all the threads to stop printing
 *	because other wise since there m8 be some waiting
 *	for the priniting lock to be fread up. There for let all
 *	philosophers print then get the time then print the time
 *	so that the death allways is printed last
 */

int	main(int argc, char **argv)
{
	t_main_process	template;

	if (lexer(argc, argv, NULL)
		|| parser(argc, argv, &template.programm_args))
		return (1);
	alloc_processes(&template);
	set_philosophers(&template);
	make_processes(&template);
	wait_for_processes(&template);
	exit(0);
}
