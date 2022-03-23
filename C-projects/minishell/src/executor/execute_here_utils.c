/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_here_utils.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/02 15:22:52 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/11/02 16:08:08 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <stdlib.h>

void	free_heredocs(char *input, t_list **head)
{
	ft_lstclear(head, free);
	free(input);
}

void	write_here_docs(t_file_io *fd, t_list *head, char *input)
{
	t_list	*tmp;

	free(input);
	while (head)
	{
		tmp = head->next;
		minishell_write(fd->here_doc[1], (char *)head->content,
			ft_strlen((char *)head->content));
		minishell_write(fd->here_doc[1], "\n", 1);
		free(head->content);
		free(head);
		head = tmp;
	}
}
