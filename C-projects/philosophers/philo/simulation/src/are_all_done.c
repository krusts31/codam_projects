/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   are_all_done.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/04 18:47:32 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/04 18:49:11 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

/*
 *	this function checks how if all philsophers have eaten
 *	the spcified times, if not then the simulation continues
 */

bool	are_all_done(t_main_thread *template)
{
	int	done_philosopher_cnt;
	int	index;

	index = 0;
	done_philosopher_cnt = 0;
	while (template->programm_args.number_of_philosophers != index)
	{
		pthread_mutex_lock(template->philosophers[index].state_lock);
		if (template->philosophers[index].state == done)
			done_philosopher_cnt++;
		pthread_mutex_unlock(template->philosophers[index].state_lock);
		if (done_philosopher_cnt
			== template->programm_args.number_of_philosophers)
			return (true);
		index++;
	}
	return (false);
}
