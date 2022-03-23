/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 21:04:16 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/10 17:23:23 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	set_state(t_main_thread *template, int index)
{
	template->philosophers[index].thread_state = running;
}

void	set_printing_lock(t_main_thread *template, int index)
{
	template->philosophers[index].printing_lock = template->printing_lock;
}

void	set_time_since_simulation_started(t_main_thread *template, int index)
{
	template->philosophers[index].time_since_simulation_start
		= template->time_since_simulation_start;
}

void	set_philosopher_state(t_main_thread *template, int index)
{
	template->philosophers[index].state = alive;
}

void	set_id(t_main_thread *template, int index)
{
	template->philosophers[index].id = index;
}
