/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_pid.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/10 19:07:41 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/10 19:27:07 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	set_pid(t_main_process *template, int index, int value)
{
	template->processes[index] = value;
}
