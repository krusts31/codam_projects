/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_kill_all.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 13:28:02 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/11 13:29:20 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	set_kill_all(t_main_process *template, int index)
{
	template->philosophers[index].kill_all = template->kill_all;
}
