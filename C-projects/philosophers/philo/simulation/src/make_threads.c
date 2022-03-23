/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_threads.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 23:22:29 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/14 20:01:11 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

#include <unistd.h>

/*
 *	we give a usleep of 2000 to let the threads start
 *	thread to pasuse the monithoring thread from killing them
 *	before they have started
 *	index == 0 represent the first philosopher thats when we want to get
 *	the start of sim
 *	once the last philosopher is created we want to sleep for some time to
 *	delay the monithoring thread so that evry philosopher
 *	gettimeofday(&template->philosophers[index].curent_time, 0);
 *	gettimeofday(&template->philosophers[index].time_of_last_meal, 0);
 *	the above is for setting the time fo philosophers that will be watched
 *	by the monithoring thread
 */

static bool done_creating_thread(int index, t_main_thread *template)
{
	if (index == template->programm_args.number_of_philosophers)
		return (true);
	return (false);
}

/*
**	THE CODE syncs even philosophers and odd
**	since all the even philosophers will start with sleeping
**	all the even philosophers will have a less competition for the forks
**	print_parced_data(template.programm_args) add this to debug the parser
*/

void	*simulation(void *arg)
{
	t_philosopher	*philosopher;
	const int		start_with_sleeping = 4;
	const int		start_with_thinking = 0;

	philosopher = arg;
	if (is_even(philosopher->id))
		return (eating_sleeping_thinking(philosopher, start_with_sleeping));
	else
		return (eating_sleeping_thinking(philosopher, start_with_thinking));
}

/*
 *	template->created_threads++ because pthread_creat can fail
 *	there for we want to how many thread to join
 */

void	*make_threads(t_main_thread *template, int index)
{
	if (done_creating_thread(index, template))
		return (NULL);
	set_current_time(template, index);
	set_of_last_meal(template, index);
	if (pthread_create(&template->philosophers[index].thread,
			0,
			simulation,
			&template->philosophers[index]))
	{
		pthread_mutex_lock(template->printing_lock);
		set_to_state(template, 0, 0, error);
		pthread_mutex_unlock(template->printing_lock);
		return (simulation_done);
	}
	template->created_threads++;
	return (make_threads(template, ++index));
}
