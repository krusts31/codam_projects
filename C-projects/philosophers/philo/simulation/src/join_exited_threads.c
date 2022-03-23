/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   join_exited_threads.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 23:23:51 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/14 19:56:31 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

static bool	is_reset_index(int index, t_main_thread *template)
{
	if (index == template->programm_args.number_of_philosophers)
		return (true);
	return (false);
}

static bool is_thread_exited(t_main_thread *template, int index)
{
	if (template->philosophers[index].thread_state == exited)
		return (true);
	return (false);
}

static void	set_thread_to_joind(t_main_thread *template, int index)
{
	template->philosophers[index].thread_state = joined;
}

int	join_exited_thread(t_main_thread *template, int index, int joind_threads)
{
	void	*ptr;

	ptr = NULL;
	while (joind_threads != template->created_threads)
	{
		if (is_reset_index(index, template))
			index = 0;
		pthread_mutex_lock(template->philosophers[index].thread_state_lock);
		if (is_thread_exited(template, index))
		{
			pthread_join(template->philosophers[index].thread, &ptr);
			set_thread_to_joind(template, index);
			++joind_threads;
		}
		pthread_mutex_unlock(template->philosophers[index].thread_state_lock);
		index++;
	}
	return (0);
}
