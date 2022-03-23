/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   build_time.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 18:03:41 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/14 19:35:20 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

static void	set_time_since_simulation_start(t_main_thread *template)
{
	gettimeofday(template->time_since_simulation_start, 0);
}

static void	set_created_threads_cnt(t_main_thread *template)
{
	template->created_threads = 0;
}

/*
**	buil_time does all te allocation of heap data
**	inits all muteces
**	it set the pointers in all philosophers to point to template
**	and set the time when simulation started
**	the time when simulation has started can be set at any time
**	since it will not be part of the 
*/

int	alloc_and_init_muteces(t_main_thread *template)
{
	alloc_heap_data(template);
	if (!is_template_alloced(template))
	{
		free_template(template);
		return (1);
	}
	init_muteces(template);
	if (!is_template_inited(template, 0))
	{
		destroy_muteces(template, 0);
		free_template(template);
		return (1);
	}
	set_created_threads_cnt(template);
	set_philosophers(template, 0);
	set_time_since_simulation_start(template);
	return (0);
}
