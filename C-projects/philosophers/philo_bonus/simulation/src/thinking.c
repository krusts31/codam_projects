/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   thinking.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 16:39:15 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/10 10:14:13 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	set_thinking(t_philosopher *philosopher)
{
	philosopher->print_msg = "\x1B[01;90mis thinking\x1B[0m 🤔";
	philosopher->end.tv_sec = 0;
	philosopher->end.tv_usec = 0;
	philosopher->start.tv_sec = 0;
	philosopher->start.tv_usec = 0;
}

void	thinking(t_philosopher *philosopher)
{
	print_status(philosopher);
}
