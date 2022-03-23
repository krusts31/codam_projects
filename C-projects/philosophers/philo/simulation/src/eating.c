/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eating.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 16:37:53 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/14 19:58:04 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	*is_done_eating(t_philosopher *philo)
{
	if (philo->delta >= philo->program_args.time_to_eat)
		return (exit_ft_sleep);
	else
		return (NULL);
}

void	*set_eating(t_philosopher *philosopher)
{
	philosopher->print_msg = "\x1B[31mis eating\x1B[0m   🍝";
	philosopher->end.tv_sec = 0;
	philosopher->end.tv_usec = 0;
	philosopher->start.tv_sec = 0;
	philosopher->start.tv_usec = 0;
	philosopher->delta = 0;
	philosopher->sleep_index = 0;
	return (NULL);
}

void	*eating(t_philosopher *philosopher)
{
	reset_time_between_meals(philosopher);
	print_status(philosopher);
	if (philosopher->program_args.times_to_eat != -1)
		philosopher->program_args.times_to_eat--;
	if (philosopher->program_args.times_to_eat == 0)
	{
		pthread_mutex_lock(philosopher->state_lock);
		philosopher->state = done;
		pthread_mutex_unlock(philosopher->state_lock);
		return (simulation_done);
	}
	eat_for_given_time(philosopher);
	return (NULL);
}
