/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_printing_semaphore.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/10 19:04:02 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/10 19:04:46 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	set_printing_semaphore(t_main_process *template, int index)
{
	template->philosophers[index].printing_semaphore
		= template->printing_semaphore;
}
