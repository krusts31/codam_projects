/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_forks.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 13:25:55 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/11 13:27:32 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	set_forks(t_main_process *template, int index)
{
	template->philosophers[index].forks = template->forks;
}
