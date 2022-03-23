/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   programm_args.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 21:00:25 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/01 23:02:16 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	set_time_to_eat(t_main_thread *template, int index)
{
	template->philosophers[index].time_to_eat
		= template->programm_args.time_to_eat;
}

void	set_times_to_eat(t_main_thread *template, int index)
{
	template->philosophers[index].times_to_eat
		= template->programm_args.times_to_eat;
}

void	set_time_to_die(t_main_thread *template, int index)
{
	template->philosophers[index].time_to_die
		= template->programm_args.time_to_die;
}

void	set_time_to_sleep(t_main_thread *template, int index)
{
	template->philosophers[index].time_to_sleep
		= template->programm_args.time_to_sleep;
}
