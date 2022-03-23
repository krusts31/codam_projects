/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_curent_time.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/13 18:37:48 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/13 20:14:38 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	*set_time_between_meals(t_philosopher *philosopher)
{
	gettimeofday(&philosopher->time_of_last_meal, NULL);
	gettimeofday(&philosopher->curent_time, NULL);
	return (NULL);
}

void	set_time_of_death(t_philosopher *philosopher)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	philosopher->time_of_death = get_time_diff_in_ms(start,
			*philosopher->time_since_simulation_start);
}

void	set_curent_time(t_philosopher *philosopher)
{
	gettimeofday(&philosopher->curent_time, NULL);
}
