/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_token_quote.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts/dkrecisz <codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 15:56:27 by alkrusts/dk   #+#    #+#                 */
/*   Updated: 2021/09/13 15:57:53 by alkrusts/dk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"

/**
 * make_token_squote()
 * - ORs the token type with (WORD | SQUOTE)
 * - the function tries to copy characters
 * 		up until a matching single quote has been found.
 * - at the end of the loop there is a check if the end of the input
 * 		line has been reached. This means that the quotes are open
 * 		(e.g.: echo 'lol ). The error variable is set to TRUE and
 * 		the calling function will know about the syntax error.
**/
void	make_token_squote(t_token **token, t_data **data, size_t *i, size_t *j)
{
	char	*line;

	line = (*data)->line;
	(*token)->type |= (WORD | SQUOTE);
	while (line[(*i)])
	{
		(*token)->str[(*j)] = line[(*i)];
		(*i)++;
		(*j)++;
		if (line[(*i)] == '\0')
			(*data)->error = TRUE;
		else if (line[(*i)] == '\'')
			break ;
	}
	(*token)->str[(*j)] = line[(*i)];
	(*j)++;
}

/**
 * make_token_dquote()
 * - ORs the token type with (WORD | DQUOTE)
 * - the function tries to copy characters
 * 		up until a matching double quote has been found.
 * - if a '$' is present this method ORs the token type with EXPAND value.
 * 		this will allow to do variable expansion before commmand execution.
 * - at the end of the loop there is a check if the end of the input
 * 		line has been reached. This means that the quotes are open
 * 		(e.g.: echo "lol ). The error variable is set to TRUE and
 * 		the calling function will know about the syntax error.
**/
void	make_token_dquote(t_token **token, t_data **data, size_t *i, size_t *j)
{
	(*token)->type |= (WORD | DQUOTE);
	while ((*data)->line[(*i)])
	{
		if (is_valid_expansion((*data)->line + (*i)))
			(*token)->type |= EXPAND;
		if (is_special_expansion((*data)->line + (*i)))
			get_exit_status(data, token, i, j);
		else
		{
			(*token)->str[(*j)] = (*data)->line[(*i)];
			(*i)++;
			(*j)++;
		}
		if ((*data)->line[(*i)] == '\0')
			(*data)->error = TRUE;
		else if ((*data)->line[(*i)] == '\"')
			break ;
	}
	(*token)->str[(*j)] = (*data)->line[(*i)];
	(*j)++;
}

void	make_token_quote(t_token **token, t_data **data, size_t *i, size_t *j)
{
	char	c;

	(*token)->start = *i;
	if ((*data)->line[(*i)] == '$')
		(*i)++;
	c = (*data)->line[(*i)];
	if (c == '\'')
		make_token_squote(token, data, i, j);
	else if (c == '\"')
		make_token_dquote(token, data, i, j);
	(*data)->token_mask |= (*token)->type;
	init_new_token(token, (*data)->line_len - *i, j, *i + 1);
}
