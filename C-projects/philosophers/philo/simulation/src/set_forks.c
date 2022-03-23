/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_forks.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 21:02:03 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/14 10:48:57 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

static pthread_mutex_t	*get_right_fork(t_main_thread *template, int index)
{
	pthread_mutex_t	*forks;

	forks = template->forks;
	return (&forks[template->philosophers[index].id]);
}

static pthread_mutex_t	*get_left_fork(t_main_thread *template, int index)
{
	pthread_mutex_t	*forks;

	forks = template->forks;
	return (&forks[(template->philosophers[index].id + 1)
			% template->programm_args.number_of_philosophers]);
}

void	set_right_fork(t_main_thread *template, int index)
{
	template->philosophers[index].right_fork = get_right_fork(template, index);
}

void	set_left_fork(t_main_thread *template, int index)
{
	template->philosophers[index].left_fork = get_left_fork(template, index);
}
