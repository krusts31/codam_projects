/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_time_since_simulatoin_start.c                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 13:30:12 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/11 13:32:08 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	set_time_since_simulation_start(t_main_process *template, int index)
{
	template->philosophers[index].time_since_simulation_start
		= template->time_since_simulation_start;
}
