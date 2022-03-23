/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_time_between_meals.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 16:18:47 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/02 00:51:17 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	*set_time_between_meals(t_philosopher *philo)
{
	pthread_mutex_lock(philo->current_time_lock);
	pthread_mutex_lock(philo->time_of_last_meal_lock);
	philo->time_between_meals = subtract_time_in_ms(philo->curent_time,
			philo->time_of_last_meal);
	pthread_mutex_unlock(philo->time_of_last_meal_lock);
	pthread_mutex_unlock(philo->current_time_lock);
	return (NULL);
}
