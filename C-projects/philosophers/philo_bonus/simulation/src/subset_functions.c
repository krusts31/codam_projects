/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   subset_functions.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 16:36:38 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/09 13:56:50 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

#include <unistd.h>

double	get_time_diff_in_ms(struct timeval end, struct timeval start)
{
	return ((end.tv_sec - start.tv_sec) * 1000.0
		+ (end.tv_usec - start.tv_usec) / 1000.0);
}

void	*set_time_stamp(t_philosopher *philosopher)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	philosopher->time_stamp = get_time_diff_in_ms(start,
			*philosopher->time_since_simulation_start);
	return (NULL);
}

void	*reset_index(t_philosopher *pillow)
{
	pillow->sleep_index = 1;
	return (NULL);
}

void	*eat_for_given_time(t_philosopher *philo)
{
	void							*ret;
	static t_simulation_func		sleep_func[6] = {
		init_time,
		ft_usleep,
		update_time,
		set_delta_ms,
		is_done_eating,
		reset_index
	};

	while (1)
	{
		ret = sleep_func[philo->sleep_index++](philo);
		if (ret == exit_ft_sleep)
			return (NULL);
	}
}

void	*sleep_for_given_time(t_philosopher *philo)
{
	void							*ret;
	static t_simulation_func		sleep_func[6] = {
		init_time,
		ft_usleep,
		update_time,
		set_delta_ms,
		is_done_sleeping,
		reset_index
	};

	while (1)
	{
		ret = sleep_func[philo->sleep_index++](philo);
		if (ret == exit_ft_sleep)
			return (NULL);
	}
}
