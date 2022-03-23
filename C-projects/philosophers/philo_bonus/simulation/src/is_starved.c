/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_starved.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/19 23:34:59 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/11 13:40:04 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

/*
 *	we need do not need to sem time_of_last_meal and current_time
 *	because a nother thread is writing to it in eating.c
 */

bool	is_starved(t_philosopher *philosopher)
{
	double	time_since_last_meal;

	time_since_last_meal = subtract_time_in_ms(philosopher->curent_time,
			philosopher->time_of_last_meal);
	if (time_since_last_meal >= philosopher->program_args.time_to_die)
		return (true);
	return (false);
}
