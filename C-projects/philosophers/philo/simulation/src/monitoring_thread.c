/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitoring_thread.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 17:40:59 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/13 20:30:08 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

/*
 *	We need to update the current since it we want to know if a philosopher
 *	is dead at the given moment and not at some time in the past or future
 *	this is not the best solution since it cheks one philosopher at a given
 *	moment, but not all philosophers vs one time frame. To Win this
 *	we would have to make a seperate thread that cheks evry philosopher sate
 */

static void	update_curent_time(t_philosopher *philosopher)
{
	pthread_mutex_lock(philosopher->current_time_lock);
	gettimeofday(&philosopher->curent_time, NULL);
	pthread_mutex_unlock(philosopher->current_time_lock);
}

/*
 *	Stop printing is used to ensure that no philosopher can print
 *	their statuses if some one dies. We do it by locking the 
 *	printing mutex. Once all the philosopher states have been changed
 *	to dead we will resume_printing in this way we do not have a risk
 *	of printing a philosopher status after a death of a philosopher.
 *	Since a philosopher only knows its state it does not know if it
 *	has to stop since some one died. It is possible to make some philosophers
 *	die with input like 200 200 200 200 and while set_all_state function
 *	is runing it will changed the states from alive to dead, but some
 *	philosphers wount be set fast enought and will be able to print their
 *	status. but since there is only one printing lock amoung all threads
 *	by locking it we will 100% gurante that all threads will be locked out
 *	of the prnting statment till all philospher have been set to dead.
 *	Once all philosophers have been set to dead we resume printing.
 */

static void	stop_printing(t_main_thread *template)
{
	pthread_mutex_lock(template->printing_lock);
}

static void	resume_printing(t_main_thread *template)
{
	pthread_mutex_unlock(template->printing_lock);
}

static void	*set_time_of_death(t_philosopher *philosopher)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	philosopher->time_of_death = get_time_diff_in_ms(start,
			*philosopher->time_since_simulation_start);
	return (NULL);
}

int	monitoring_thread(t_main_thread *template, int index)
{
	if (index == template->programm_args.number_of_philosophers)
		index = 0;
	if (are_all_done(template))
		return (0);
	update_curent_time(&template->philosophers[index]);
	pthread_mutex_lock(template->philosophers[index].state_lock);
	if (template->philosophers[index].state == alive)
	{
		pthread_mutex_unlock(template->philosophers[index].state_lock);
		if (is_starved(&template->philosophers[index]))
		{
			stop_printing(template);
			set_time_of_death(&template->philosophers[index]);
			print_death(template, index);
			set_to_state(template, index, 0, dead);
			resume_printing(template);
			return (0);
		}
	}
	else
		pthread_mutex_unlock(template->philosophers[index].state_lock);
	return (monitoring_thread(template, ++index));
}
