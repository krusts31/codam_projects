/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_template_valid.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/12 19:09:27 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/14 10:45:08 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "struct.h"

bool	is_template_alloced(t_main_thread *template)
{
	if (!template->state_locks
		|| !template->printing_lock
		|| !template->forks
		|| !template->philosophers
		|| !template->thread_state_locks
		|| !template->time_of_last_meal_locks
		|| !template->current_time_locks
		|| !template->time_since_simulation_start)
		return (false);
	else
		return (true);
}

/*
 *	if __sig == 0 then phtread_mutex_init failed to init it
 */

bool	is_template_inited(t_main_thread *template, int index)
{
	(void)template;
	(void)index;
	return (true);
	/*
	if (index == template->programm_args.number_of_philosophers)
	{
		if (template->printing_lock->__sig == 0)
			return (false);
		return (true);
	}
	if (template->state_locks[index].__sig == 0
		|| template->forks[index].__sig == 0
		|| template->thread_state_locks[index].__sig == 0
		|| template->time_of_last_meal_locks[index].__sig == 0
		|| template->current_time_locks[index].__sig == 0)
		return (false);
	return (is_template_inited(template, ++index));
	*/
}
