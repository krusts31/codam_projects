/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handel_forks.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 16:41:03 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/14 11:04:40 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

#include <unistd.h>
#include <stdlib.h>

bool	is_even(int philosopher_id)
{
	const int		even = 0;

	if (philosopher_id % 2 == even)
		return (true);
	else
		return (false);
}

void	set_take_forks(t_philosopher *philosopher)
{
	philosopher->print_msg = "\x1B[01;91mtaken fork\x1B[0m  🍴";
	philosopher->end.tv_sec = 0;
	philosopher->end.tv_usec = 0;
	philosopher->start.tv_sec = 0;
	philosopher->start.tv_usec = 0;
	philosopher->delta = 0;
}

static void	*edge_case(t_philosopher *philosopher)
{
	sem_wait(philosopher->forks);
	print_status(philosopher);
	usleep(philosopher->program_args.time_to_die * 1000);
	sem_post(philosopher->forks);
	exit(2);
}

void	take_forks(t_philosopher *philosopher)
{
	if (philosopher->program_args.number_of_philosophers == 1)
		edge_case(philosopher);
	if (is_even(philosopher->program_args.number_of_philosophers))
		usleep(1000);
	sem_wait(philosopher->forks);
	print_status(philosopher);
	sem_wait(philosopher->forks);
	print_status(philosopher);
}

void	let_go_forks(t_philosopher *philosopher)
{
	sem_post(philosopher->forks);
	sem_post(philosopher->forks);
}
