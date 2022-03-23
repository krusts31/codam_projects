/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quote_removal.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts/dkrecisz <codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 15:56:29 by alkrusts/dk   #+#    #+#                 */
/*   Updated: 2021/09/13 15:57:52 by alkrusts/dk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include <stdlib.h>
#include <errno.h>

void	remove_quotes(t_token *token)
{
	char	*new;
	size_t	len;

	len = ft_strlen(token->str);
	if (len < 3)
	{
		free(token->str);
		token->str = ft_strdup("");
		if (token->str == NULL)
			exit_minishell(errno);
		return ;
	}
	new = (char *)minishell_calloc(len, sizeof(char));
	ft_strlcpy(new, token->str + 1, len - 1);
	free(token->str);
	token->str = new;
}

void	merge_nodes(t_token *tmp)
{
	t_token	*next;
	char	*new;

	next = tmp->next->next;
	new = ft_strjoin(tmp->str, tmp->next->str);
	if (new == NULL)
		exit_minishell(errno);
	tmp->end = tmp->next->end;
	free(tmp->str);
	free(tmp->next->str);
	free(tmp->next);
	tmp->str = new;
	tmp->type |= RMQUOTE;
	tmp->next = next;
}

void	quote_removal(t_data **data)
{
	t_token	*tmp;

	tmp = (*data)->token;
	while (tmp)
	{
		if (tmp->type & (SQUOTE | DQUOTE))
			remove_quotes(tmp);
		tmp = tmp->next;
	}
	tmp = (*data)->token;
	while (tmp)
	{
		if (tmp->next && tmp->end == tmp->next->start - 1 && \
			tmp->type & WORD && tmp->next->type & WORD)
			merge_nodes(tmp);
		else
			tmp = tmp->next;
	}
}
