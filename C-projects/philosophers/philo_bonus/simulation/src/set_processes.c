/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_processes.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/10 18:06:58 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/11 13:25:21 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	set_philosophers(t_main_process *template)
{
	int		index;

	index = 0;
	while (1)
	{
		if (template->programm_args.number_of_philosophers == index)
		{
			set_pid(template, index, 0);
			break ;
		}
		set_program_args(template, index);
		set_id(template, index);
		set_time_since_simulation_start(template, index);
		set_forks(template, index);
		set_kill_all(template, index);
		set_printing_semaphore(template, index);
		set_pid(template, index, -1);
		index++;
	}
}
