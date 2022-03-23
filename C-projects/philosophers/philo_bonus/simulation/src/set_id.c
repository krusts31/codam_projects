/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_id.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/10 19:02:53 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/10 19:03:40 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	set_id(t_main_process *template, int index)
{
	template->philosophers[index].id = index;
}
