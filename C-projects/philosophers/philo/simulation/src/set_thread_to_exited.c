/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_thread_to_exited.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/04 19:03:17 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/04 19:06:00 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

#include <pthread.h>

void	set_thread_to_exited(t_philosopher *philosopher)
{
	pthread_mutex_lock(philosopher->thread_state_lock);
	philosopher->thread_state = exited;
	pthread_mutex_unlock(philosopher->thread_state_lock);
}
