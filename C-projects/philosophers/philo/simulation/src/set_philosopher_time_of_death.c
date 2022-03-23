/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_philosopher_time_of_death.c                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/10 17:34:14 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/10 17:35:52 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	set_philosopher_time_of_death(t_main_thread *template, int index)
{
	template->philosophers[index].time_of_death = 0;
}
