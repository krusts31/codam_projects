/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts/dkrecisz <codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 15:56:52 by alkrusts/dk   #+#    #+#                 */
/*   Updated: 2021/10/16 01:27:43 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "lexer.h"
#include "parser.h"
#include <errno.h>

int	get_next_token(t_data *data, char **token_str, int token_type)
{
	if (data->token_ptr->type == EMPTY)
		return (1);
	else if (data->token_ptr->type & token_type)
	{
		if (token_str)
		{
			*token_str = ft_strdup(data->token_ptr->str);
			if (*token_str == NULL)
				exit_minishell(errno);
		}
		data->token_ptr = data->token_ptr->next;
		return (0);
	}
	data->token_ptr = data->token_ptr->next;
	return (1);
}

static void	syntax_error(t_data *data)
{
	minishell_putstr_fd("minishell: Syntax error!\n", 2);
	data->exit_status = 258;
	data->astree = NULL;
}

static int	check_syntax(t_data *data)
{
	t_token	*tmp;

	tmp = data->token;
	while (tmp->next->type)
		tmp = tmp->next;
	if (tmp->type & (HERE_DOC | REDIR_IN | APPEND | REDIR_OUT | PIPE))
		return (1);
	return (0);
}

void	parser(t_data *data)
{
	if (data->token->next == NULL)
	{
		data->astree = NULL;
		return ;
	}
	else if (check_syntax(data))
		return (syntax_error(data));
	data->token_ptr = data->token;
	data->astree = parse_pipeline(data);
	if (data->astree == NULL)
		return (syntax_error(data));
}
