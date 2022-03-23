/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handel_forks.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 16:41:03 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/14 19:48:54 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

#include <unistd.h>

bool	is_even(int philosopher_id)
{
	const int		even = 0;

	if (philosopher_id % 2 == even)
		return (true);
	else
		return (false);
}

void	*set_take_forks(t_philosopher *philosopher)
{
	philosopher->fork_state = no_forks;
	philosopher->print_msg = "\x1B[01;91mtaken fork\x1B[0m  🍴";
	philosopher->end.tv_sec = 0;
	philosopher->end.tv_usec = 0;
	philosopher->start.tv_sec = 0;
	philosopher->start.tv_usec = 0;
	philosopher->delta = 0;
	return (NULL);
}

static void	*edge_case(t_philosopher *philosopher)
{
	pthread_mutex_lock(philosopher->right_fork);
	print_status(philosopher);
	usleep(philosopher->program_args.time_to_die * 1000);
	pthread_mutex_unlock(philosopher->right_fork);
	return (philosopher_died);
}

/*
 *	if there is only one philosopehr that is considered as 
 *	an edge case and it will always die because philosophers
 *	need 2 forks to eat
 */

void	*take_forks(t_philosopher *philosopher)
{
	if (philosopher->program_args.number_of_philosophers == 1)
		return (edge_case(philosopher));
	if (is_even(philosopher->id))
	{
		if (!is_even(philosopher->program_args.number_of_philosophers))
			usleep(1000);
		pthread_mutex_lock(philosopher->right_fork);
		print_status(philosopher);
		pthread_mutex_lock(philosopher->left_fork);
		print_status(philosopher);
		philosopher->fork_state = both_forks;
	}
	else
	{
		pthread_mutex_lock(philosopher->left_fork);
		print_status(philosopher);
		pthread_mutex_lock(philosopher->right_fork);
		print_status(philosopher);
		philosopher->fork_state = both_forks;
	}
	return (NULL);
}

void	*let_go_forks(t_philosopher *philosopher)
{
	pthread_mutex_unlock(philosopher->left_fork);
	pthread_mutex_unlock(philosopher->right_fork);
	return (NULL);
}
