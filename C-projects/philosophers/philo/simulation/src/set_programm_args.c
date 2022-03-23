/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_programm_agrs.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 21:27:09 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/10 17:50:51 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	set_programm_args(t_main_thread *template, int index)
{
	template->philosophers[index].program_args = template->programm_args;
}
