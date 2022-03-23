/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_philosopher_dead.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 18:43:36 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/14 18:44:37 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

bool	is_philosopher_dead(t_philosopher *philosopher)
{
	pthread_mutex_lock(philosopher->state_lock);
	if (philosopher->state != alive)
	{
		pthread_mutex_unlock(philosopher->state_lock);
		return (true);
	}
	pthread_mutex_unlock(philosopher->state_lock);
	return (false);
}
