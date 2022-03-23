/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_locks.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 20:55:01 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/14 11:53:13 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	set_philosopher_state_lock(t_main_thread *template, int index)
{
	template->philosophers[index].state_lock = &template->state_locks[index];
}

void	set_thread_state_lock(t_main_thread *template, int index)
{
	template->philosophers[index].thread_state_lock
		= &template->thread_state_locks[index];
}

void	set_current_time_locks(t_main_thread *template, int index)
{
	template->philosophers[index].current_time_lock
		= &template->current_time_locks[index];
}

void	set_time_of_last_meal_lock(t_main_thread *template, int index)
{
	template->philosophers[index].time_of_last_meal_lock
		= &template->time_of_last_meal_locks[index];
}
