/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reset_time_between_meals.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/19 16:32:48 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/10 09:51:34 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

#include <stdio.h>

void	*reset_time_between_meals(t_philosopher *philosopher)
{
	gettimeofday(&philosopher->time_of_last_meal, NULL);
	gettimeofday(&philosopher->curent_time, NULL);
	return (NULL);
}
