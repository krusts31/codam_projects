/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sleep_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 14:40:53 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/11 13:39:29 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

#include <unistd.h>

void	*ft_usleep(t_philosopher *philo)
{
	(void)philo;
	usleep(420);
	return (NULL);
}

void	*init_time(t_philosopher *philo)
{
	gettimeofday(&philo->start, NULL);
	gettimeofday(&philo->end, NULL);
	return (NULL);
}

void	*is_done_sleeping(t_philosopher *philo)
{
	if (philo->delta >= philo->program_args.time_to_sleep)
		return (exit_ft_sleep);
	else
		return (NULL);
}

void	*set_delta_ms(t_philosopher *philo)
{
	philo->delta = subtract_time_in_ms(philo->end, philo->start);
	return (NULL);
}

void	*update_time(t_philosopher *philo)
{
	gettimeofday(&philo->end, NULL);
	return (NULL);
}
