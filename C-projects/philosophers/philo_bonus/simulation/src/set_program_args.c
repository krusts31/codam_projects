/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_program_args.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/10 19:28:11 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/11 13:35:43 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	set_program_args(t_main_process *template, int index)
{
	template->philosophers[index].program_args = template->programm_args;
}
