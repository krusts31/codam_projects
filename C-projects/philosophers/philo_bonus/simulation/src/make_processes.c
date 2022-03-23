/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_processes.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/13 16:57:33 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/14 11:14:09 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

#include <stdlib.h>

/*
 *	here there is no reason to wait for all the processes
 *	because time of start of simulation is only used
 *	for time_stamping. is_starved only does the calac
 *	on current time and time since last meal
 */

static void	init_time_to_track_philosopher(t_philosopher *philosopher)
{
	gettimeofday(&philosopher->time_of_last_meal, NULL);
	gettimeofday(&philosopher->curent_time, NULL);
}

static void	child_process(t_philosopher *philosopher)
{
	init_time_to_track_philosopher(philosopher);
	if (creat_monithoring_thread(philosopher))
	{
		stop_printing(philosopher);
		exit(3);
	}
	if (is_even(philosopher->id))
		start_simulation_even(philosopher);
	else
		start_simulation_odd(philosopher);
}

static void	parent_process(t_main_process *template, pid_t pid, int index)
{
	template->processes[index] = pid;
	template->processes_spawned++;
}

int	make_processes(t_main_process *template)
{
	int		index;
	pid_t	pid;

	index = 0;
	gettimeofday(template->time_since_simulation_start, NULL);
	while (template->processes[index])
	{
		pid = fork();
		if (pid == -1)
		{
			stop_printing(&template->philosophers[index]);
			kill_all_philosophers(template, -1);
			exit(1);
		}
		if (pid == 0)
			child_process(&template->philosophers[index]);
		else
		{
			parent_process(template, pid, index);
			index++;
		}
	}
	return (0);
}
