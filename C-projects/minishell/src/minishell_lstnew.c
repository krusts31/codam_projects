/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/23 16:00:48 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/11/02 15:18:45 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <errno.h>

t_list	*minishell_lstnew(void *content)
{
	t_list	*tmp;

	tmp = malloc(sizeof(t_list));
	if (tmp == NULL)
		exit_minishell(errno);
	else if (tmp)
	{
		tmp->content = content;
		tmp->next = NULL;
	}
	return (tmp);
}
