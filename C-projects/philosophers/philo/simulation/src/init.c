/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/31 23:00:04 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/14 19:25:04 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

static void	init_muteces_number(pthread_mutex_t *muteces, const int mutex_cnt)
{
	int	mutex_index;

	mutex_index = 0;
	while (mutex_index < mutex_cnt)
	{
		pthread_mutex_init(&muteces[mutex_index], 0);
		mutex_index++;
	}
}

int	init_muteces(t_main_thread *template)
{
	init_muteces_number(template->forks,
		template->programm_args.number_of_philosophers);
	init_muteces_number(template->state_locks,
		template->programm_args.number_of_philosophers);
	init_muteces_number(template->thread_state_locks,
		template->programm_args.number_of_philosophers);
	init_muteces_number(template->current_time_locks,
		template->programm_args.number_of_philosophers);
	init_muteces_number(template->time_of_last_meal_locks,
		template->programm_args.number_of_philosophers);
	init_muteces_number(template->printing_lock, 1);
	return (0);
}
