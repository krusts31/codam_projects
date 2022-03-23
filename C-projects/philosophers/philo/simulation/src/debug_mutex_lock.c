/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug_mutex_lock.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/10 14:56:56 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/10 15:05:15 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include "functions.h"

void	*debug_mutex_lock(t_philosopher *philosopher, pthread_mutex_t *lock)
{
	pthread_mutex_lock(lock);
	pthread_mutex_lock(philosopher->printing_lock);
	pthread_mutex_lock(philosopher->state_lock);
	if (philosopher->state == alive
		&& !is_starved(philosopher))
	{
		set_time_stamp(philosopher);
		printf("%-20f ms %-4d %s %p\n",
			philosopher->time_stamp,
			philosopher->id,
			philosopher->print_msg,
			lock);
	}
	pthread_mutex_unlock(philosopher->printing_lock);
	pthread_mutex_unlock(philosopher->state_lock);
	return (NULL);
}
