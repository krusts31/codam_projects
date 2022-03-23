/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_stuff.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/09 12:39:37 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/14 11:15:19 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "functions.h"

#include <stdio.h>

void	print_parced_data(t_programm_args parced_data)
{
	printf("amout of philosphers\t%-10d n\n",
		parced_data.number_of_philosophers);
	printf("time_to_die\t\t%-10d ms\n", parced_data.time_to_die);
	printf("time_to_eat\t\t%-10d ms\n", parced_data.time_to_eat);
	printf("time_to_sleep\t\t%-10d ms\n", parced_data.time_to_sleep);
	printf("times_to_eat\t\t%-10d times\n", parced_data.times_to_eat);
}

void	*print_status(t_philosopher *philosopher)
{
	sem_wait(philosopher->printing_semaphore);
	set_time_stamp(philosopher);
	printf("%-20f ms %-4d %s\n",
		philosopher->time_stamp,
		philosopher->id + 1,
		philosopher->print_msg);
	sem_post(philosopher->printing_semaphore);
	return (NULL);
}

void	print_death(t_philosopher *philosopher)
{
	printf("%-20f ms %-4d \x1B[97mDIED\x1B[0m	 💀\n",
		philosopher->time_of_death, philosopher->id + 1);
}

void	stop_printing(t_philosopher *philosopher)
{
	sem_wait(philosopher->printing_semaphore);
}

void	resume_printing(t_philosopher *philosopher)
{
	sem_post(philosopher->printing_semaphore);
}
