/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_stuf.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/04 18:09:54 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/14 20:03:35 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "functions.h"

#include <stdio.h>

int	print_parced_data(t_programm_args parced_data)
{
	printf("amout of philosphers\t%-10d n\n",
		parced_data.number_of_philosophers);
	printf("time_to_die\t\t%-10d ms\n", parced_data.time_to_die);
	printf("time_to_eat\t\t%-10d ms\n", parced_data.time_to_eat);
	printf("time_to_sleep\t\t%-10d ms\n", parced_data.time_to_sleep);
	printf("times_to_eat\t\t%-10d times\n", parced_data.times_to_eat);
	return (0);
}

/*
 *	id + 1 because the philosophers have to be indexed from 1
 *	but id is more convinient to be kept as a 0 in mem
 */

void	*print_status(t_philosopher *philosopher)
{
	pthread_mutex_lock(philosopher->printing_lock);
	if (!is_philosopher_dead(philosopher)
		&& !is_starved(philosopher))
	{
		set_time_stamp(philosopher);
		printf("[%-20f ms] id -> %-4d %s\n",
			philosopher->time_stamp,
			philosopher->id + 1,
			philosopher->print_msg);
	}
	pthread_mutex_unlock(philosopher->printing_lock);
	return (NULL);
}

void	print_death(t_main_thread *template, int index)
{
	printf("[%-20f ms] id -> %-4d \x1B[97mDIED\x1B[0m	 💀\n",
		template->philosophers[index].time_of_death,
		template->philosophers[index].id + 1);
}
