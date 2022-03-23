/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts/dkrecisz <codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 15:56:23 by alkrusts/dk   #+#    #+#                 */
/*   Updated: 2021/11/03 14:39:28 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "expansion.h"
#include <stdlib.h>

void	free_token_list(t_token *token)
{
	t_token	*tmp;

	while (token)
	{
		tmp = token->next;
		free(token->str);
		free(token);
		token = tmp;
	}
}

t_token	*init_token_list(size_t len)
{
	t_token	*new_token;

	new_token = (t_token *)minishell_calloc(len + 1, sizeof(t_token));
	new_token->str = (char *)minishell_calloc(len + 1, sizeof(char));
	return (new_token);
}

void	init_new_token(t_token **token, size_t len, size_t *j, size_t i)
{
	if (len <= 1)
		len = 2;
	if ((*token)->type != EMPTY)
	{
		if ((*token)->type & WORD)
			(*token)->end = i - 1;
		(*token)->next = (t_token *)minishell_calloc(1, sizeof(t_token));
		(*token) = (*token)->next;
		(*token)->str = (char *)minishell_calloc(len + 1, sizeof(char));
		(*j) = 0;
	}
}

static void	analyze_char(t_data **data, t_token **token, size_t *i, size_t *j)
{
	char	c;

	c = (*data)->line[(*i)];
	if (is_break(c) || is_quote(c) || is_quote_edge_case(*data, *i))
		init_new_token(token, (*data)->line_len - (*i), j, *i);
	if (is_meta(c))
		make_token_meta(token, data, i, j);
	else if (is_quote(c) || is_quote_edge_case(*data, *i))
		make_token_quote(token, data, i, j);
	else if (is_blank(c) == NULL && (*data)->error == FALSE)
	{
		if (*j == 0)
			(*token)->start = (*i);
		if (is_valid_expansion((*data)->line + (*i)))
			(*token)->type |= EXPAND;
		else if (is_special_expansion((*data)->line + (*i)))
			return (get_exit_status(data, token, i, j));
		(*token)->str[(*j)] = c;
		if (c != '\n')
			(*token)->type |= WORD;
		(*j)++;
	}
	(*i)++;
	(*data)->token_mask |= (*token)->type;
}

int	lexer(t_data **data, char *line)
{
	t_token		*tmp_token;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	(*data)->token = init_token_list((*data)->line_len);
	tmp_token = (*data)->token;
	while (line[i] && (*data)->error == FALSE)
		analyze_char(data, &tmp_token, &i, &j);
	init_new_token(&tmp_token, 1, &j, i);
	if ((*data)->error == TRUE)
	{
		(*data)->exit_status = 2;
		(*data)->error = FALSE;
		return (EXIT_FAILURE);
	}
	if ((*data)->interactive == FALSE)
		init_new_token(&tmp_token, 0, &j, i);
	if ((*data)->token_mask & EXPAND)
		expand_variables(data, (*data)->env);
	quote_removal(data);
	lexer_count_tokens(*data);
	return (EXIT_SUCCESS);
}
