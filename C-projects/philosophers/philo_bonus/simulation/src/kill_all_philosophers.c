/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   kill_all_philosophers.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/09 16:02:03 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/13 18:17:23 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

#include <signal.h>

/*
 *	kills all processes that are not equal to the pid
 *	because pid is the process that exited
 *	if pid == 0 then just kill all processes
 */

void	kill_all_philosophers(t_main_process *template, pid_t pid)
{
	int	index;

	index = 0;
	while (template->processes_spawned > index)
	{
		if (template->processes[index] != pid)
			kill(template->processes[index], SIGINT);
		index++;
	}
}
