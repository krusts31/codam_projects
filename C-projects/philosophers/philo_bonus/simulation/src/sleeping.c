/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sleeping.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 16:38:40 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/08 15:47:05 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	set_sleeping(t_philosopher *philosopher)
{
	philosopher->print_msg = "\x1B[96mis sleeping\x1B[0m 💤";
	philosopher->end.tv_sec = 0;
	philosopher->end.tv_usec = 0;
	philosopher->start.tv_sec = 0;
	philosopher->start.tv_usec = 0;
	philosopher->delta = 0;
	philosopher->sleep_index = 0;
}

void	sleeping(t_philosopher *philosopher)
{
	print_status(philosopher);
	sleep_for_given_time(philosopher);
}
