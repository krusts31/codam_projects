/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   destroy_muteces.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/01 15:39:06 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/14 20:05:13 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

/*
 * if __sig == 0 theat means that the mutex is not inited!
 */

void	destroy_muteces(t_main_thread *template, int index)
{
	if (template->programm_args.number_of_philosophers == index)
	{
		pthread_mutex_destroy(template->printing_lock);
		return ;
	}
	pthread_mutex_destroy(&template->state_locks[index]);
	pthread_mutex_destroy(&template->current_time_locks[index]);
	pthread_mutex_destroy(&template->time_of_last_meal_locks[index]);
	pthread_mutex_destroy(&template->forks[index]);
	pthread_mutex_destroy(&template->thread_state_locks[index]);
	destroy_muteces(template, ++index);
}
