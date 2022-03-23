/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   time_since_simulation_start.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/10 19:06:26 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/10 19:07:17 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	set_printing_semaphore(t_main_process *template, int index)
{
	template->philosophers[index].time_since_simulation_start
		= template->time_since_simulation_start;
}
