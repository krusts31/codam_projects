/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   kill_all_philosophers.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/09 16:02:03 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/13 18:29:53 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

#include <sys/wait.h>

/*
 *	if philo dies it returns 1 but some times it will be 256 * exit(arrg)
 *	there for if it is more than 256 we devide by it
 *	if the exit code is 2 then the philosopher done eating
 *	and should not be killed
 *	When the WNOHANG option is specified and no processes wish to report status
 *	wait4() returns a process id of 0.
 *	so when waitpid returns 0 the process is still runing and noting changed
 */

void	wait_for_processes(t_main_process *template)
{
	int		stat_loc;
	pid_t	pid;

	stat_loc = 0;
	while (1)
	{
		pid = waitpid(-1, &stat_loc, WNOHANG);
		if (stat_loc > 2)
			stat_loc /= 256;
		if (pid > 0 && stat_loc != 2)
			kill_all_philosophers(template, pid);
		if (pid == -1)
			return ;
	}
}
