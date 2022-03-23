/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   all_process.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/10 18:50:53 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/14 20:15:36 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

/*
*  template->processes + 1 because we are going to set the last
*  one to 0 for keeping track if all phorses have done before
*  the parent process exits
*  (template->programm_args.number_of_philosophers + 1)
*  this is hadelend like this becauase we need to add one more
*  to the philosopher count because we are mallocing set's of 4 byts
*  and not one 1 byte
*/

void	alloc_processes(t_main_process *template)
{
	template->philosophers = malloc_wrapper("philosopher",
			sizeof(t_philosopher),
			template->programm_args.number_of_philosophers);
	template->processes = malloc_wrapper("proccesses",
			sizeof(pid_t),
			template->programm_args.number_of_philosophers + 1);
	template->time_since_simulation_start = malloc_wrapper("time",
			sizeof(struct timeval),
			1);
	template->printing_semaphore = new_semaphore("printing_semaphore", 1);
	template->kill_all = new_semaphore("kill_all", 0);
	template->start_semaphore = new_semaphore("start", 0);
	template->forks = new_semaphore("forks",
			template->programm_args.number_of_philosophers);
}
