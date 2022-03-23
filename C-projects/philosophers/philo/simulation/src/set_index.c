/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_index.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/10 17:21:18 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/10 17:22:02 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	set_index(t_main_thread *template, int index)
{
	template->philosophers[index].sleep_index = 0;
	template->philosophers[index].index = 0;
}
