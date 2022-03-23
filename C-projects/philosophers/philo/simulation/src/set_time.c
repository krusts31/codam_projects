/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_time.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 21:05:47 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/01 21:29:10 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	set_of_last_meal(t_main_thread *template, int index)
{
	gettimeofday(&template->philosophers[index].time_of_last_meal, 0);
}

void	set_current_time(t_main_thread *template, int index)
{
	gettimeofday(&template->philosophers[index].curent_time, 0);
}
