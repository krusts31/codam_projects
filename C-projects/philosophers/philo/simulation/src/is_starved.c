/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_starved.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/19 23:34:59 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/10 17:51:11 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

bool	is_starved(t_philosopher *philosopher)
{
	float	time_since_last_meal;

	pthread_mutex_lock(philosopher->current_time_lock);
	pthread_mutex_lock(philosopher->time_of_last_meal_lock);
	time_since_last_meal = subtract_time_in_ms(philosopher->curent_time,
			philosopher->time_of_last_meal);
	pthread_mutex_unlock(philosopher->current_time_lock);
	pthread_mutex_unlock(philosopher->time_of_last_meal_lock);
	if (time_since_last_meal >= philosopher->program_args.time_to_die)
		return (true);
	return (false);
}
