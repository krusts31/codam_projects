/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_philosophers.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/13 18:04:02 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/14 19:31:17 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

static bool	are_all_philosophers_inited(t_main_thread *template, int index)
{
	if (template->programm_args.number_of_philosophers > index)
		return (false);
	return (true);
}

/*
 *	since I use one struct I just use index as 
 */

int	set_philosophers(t_main_thread *template, int index)
{
	if (are_all_philosophers_inited(template, index))
		return (0);
	set_id(template, index);
	set_index(template, index);
	set_programm_args(template, index);
	set_state(template, index);
	set_right_fork(template, index);
	set_left_fork(template, index);
	set_philosopher_state(template, index);
	set_printing_lock(template, index);
	set_philosopher_state_lock(template, index);
	set_thread_state_lock(template, index);
	set_time_of_last_meal_lock(template, index);
	set_time_since_simulation_started(template, index);
	set_current_time_locks(template, index);
	set_philosopher_time_of_death(template, index);
	set_current_time(template, index);
	return (set_philosophers(template, ++index));
}
