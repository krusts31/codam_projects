/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reset_time_between_meals.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/19 16:32:48 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/10 14:21:30 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	*reset_time_between_meals(t_philosopher *philosopher)
{
	pthread_mutex_lock(philosopher->current_time_lock);
	pthread_mutex_lock(philosopher->time_of_last_meal_lock);
	gettimeofday(&philosopher->time_of_last_meal, NULL);
	gettimeofday(&philosopher->curent_time, NULL);
	pthread_mutex_unlock(philosopher->current_time_lock);
	pthread_mutex_unlock(philosopher->time_of_last_meal_lock);
	return (NULL);
}
