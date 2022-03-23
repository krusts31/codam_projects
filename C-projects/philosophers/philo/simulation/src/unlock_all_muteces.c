/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unlock_all_muteces.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/24 20:27:11 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/04 18:45:24 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	unlock_all_forks(t_main_thread *template, int index)
{
	if (index == template->programm_args.number_of_philosophers)
		return ;
	if (template->philosophers[index].fork_state == both_forks)
		let_go_forks(&template->philosophers[index]);
	unlock_all_forks(template, ++index);
}
