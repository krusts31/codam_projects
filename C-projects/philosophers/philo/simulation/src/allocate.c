/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   allocate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/31 22:55:28 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/14 19:22:46 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

#include <stdlib.h>

int	alloc_heap_data(t_main_thread *template)
{
	const int	philosophers = template->programm_args.number_of_philosophers;
	const int	forks = template->programm_args.number_of_philosophers;

	template->philosophers = malloc(sizeof(t_philosopher) * philosophers);
	template->forks = malloc(sizeof(pthread_mutex_t) * forks);
	template->time_of_last_meal_locks = malloc(sizeof(pthread_mutex_t)
			* philosophers);
	template->current_time_locks = malloc(sizeof(pthread_mutex_t)
			* philosophers);
	template->state_locks = malloc(sizeof(pthread_mutex_t)
			* philosophers);
	template->thread_state_locks = malloc(sizeof(pthread_mutex_t)
			* philosophers);
	template->printing_lock = malloc(sizeof(pthread_mutex_t));
	template->time_since_simulation_start = malloc(sizeof(struct timeval));
	return (0);
}
