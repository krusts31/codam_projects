/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_command.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts/dkrecisz <codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 15:56:42 by alkrusts/dk   #+#    #+#                 */
/*   Updated: 2021/10/13 10:48:03 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "lexer.h"

/**
 * parse_command - creates a AST node for a <command>
 *
 * A <command> consists of words ->	(echo "abc" "123"),
 * or of redirections	->	(echo "abc" > file),
 * or a nested combination of words and redirections
 * ->	(wc -c < file.in > file.out)
 *  
 *	<command>		::=		<word_list>
 *					|		<redirection>
 *					|		<redirection_list>
**/

t_astree	*parse_command(t_data *data)
{
	t_astree	*word_list;
	t_astree	*redirection;
	t_astree	*redirection_list;
	t_token		*token_backup;

	token_backup = data->token_ptr;
	redirection_list = parse_redirection_list(data);
	if (redirection_list && (data->token_ptr->type
			& (HERE_DOC | REDIR_IN | APPEND | REDIR_OUT)))
	{
		delete_ast(redirection_list);
		return (NULL);
	}
	else if (redirection_list)
		return (redirection_list);
	data->token_ptr = token_backup;
	redirection = parse_redirection(data);
	if (redirection)
		return (redirection);
	data->token_ptr = token_backup;
	word_list = parse_word_list(data);
	if (word_list)
		return (word_list);
	return (NULL);
}
