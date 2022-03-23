/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_free_child.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/27 12:08:19 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/10/27 12:08:27 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

void	free_child_pid(t_child *head)
{
	t_child	*tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
