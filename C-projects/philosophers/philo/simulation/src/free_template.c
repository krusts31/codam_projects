/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_template.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/12 20:06:37 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/14 11:48:31 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

#include <stdlib.h>

int	free_template(t_main_thread *template)
{
	free(template->philosophers);
	free(template->forks);
	free(template->state_locks);
	free(template->printing_lock);
	free(template->time_since_simulation_start);
	free(template->time_of_last_meal_locks);
	free(template->current_time_locks);
	free(template->thread_state_locks);
	return (0);
}
