/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_all_to_dead.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/13 19:59:45 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/14 12:14:43 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	*set_to_state(t_main_thread *template,
		int index,
		int set_philosophers,
		enum e_philosopher_state state)
{
	if (index == template->programm_args.number_of_philosophers)
		index = 0;
	if (template->programm_args.number_of_philosophers == set_philosophers)
		return (NULL);
	pthread_mutex_lock(template->philosophers[index].state_lock);
	if (template->philosophers[index].state != dead)
	{
		template->philosophers[index].state = state;
		set_philosophers++;
	}
	pthread_mutex_unlock(template->philosophers[index].state_lock);
	return (set_to_state(template, ++index, set_philosophers, state));
}
