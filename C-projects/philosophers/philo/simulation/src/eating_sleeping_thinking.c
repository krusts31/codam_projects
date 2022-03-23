/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   even_philo.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/13 20:35:28 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/14 20:00:59 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

/*
**	THIS IS A RECURSIVE FUNCTOIN
**	if phillosopher is dead
**	or sim_func returns anything that is not NULL
**	we need to check if there are any fork that are locked
**	if thre are we need to let them go
**	that why thre is no else before both_forks
*/

void	*eating_sleeping_thinking(t_philosopher *philosopher, int index)
{
	const int					max_index = 8;
	static t_simulation_func	sim_func[8] = {
		set_take_forks,
		take_forks,
		set_eating,
		eating,
		set_sleeping,
		sleeping,
		set_thinking,
		thinking
	};

	if (!is_philosopher_dead(philosopher))
	{
		if (index == max_index)
			index = 0;
		if (!sim_func[index](philosopher))
			return (eating_sleeping_thinking(philosopher, ++index));
	}
	if (philosopher->fork_state == both_forks)
		let_go_forks(philosopher);
	set_thread_to_exited(philosopher);
	return (NULL);
}
