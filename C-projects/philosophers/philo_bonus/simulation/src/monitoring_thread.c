/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitoring_thread.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/13 18:18:25 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/14 11:14:54 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

#include <stdlib.h>

/*
**	first we wait for all the threads to stop printing
**	because other wise since there m8 be some waiting
**	for the priniting lock to be fread up. There for let all
**	philosophers print then get the time then print the time
**	so that the death allways is printed last
*/

void	failed_to_create_thread(void)
{
	exit(1);
}

void	*monitor_philosopher(void *arg)
{
	t_philosopher	*philosopher;
	const int		philosopher_died = 1;

	philosopher = arg;
	usleep(2000);
	while (1)
	{
		set_curent_time(philosopher);
		if (is_starved(philosopher))
		{
			stop_printing(philosopher);
			set_time_of_death(philosopher);
			print_death(philosopher);
			exit(philosopher_died);
			sem_post(philosopher->kill_all);
		}
	}
	return (NULL);
}

void	*creat_monithoring_thread(t_philosopher	*philosopher)
{
	if (pthread_create(&philosopher->monitoring_thread,
			NULL,
			monitor_philosopher,
			philosopher))
		return (failed_to_create_thread);
	return (NULL);
}
