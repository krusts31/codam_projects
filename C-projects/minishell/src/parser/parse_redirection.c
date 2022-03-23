/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_redirection.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts/dkrecisz <codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 15:56:47 by alkrusts/dk   #+#    #+#                 */
/*   Updated: 2021/09/13 15:57:48 by alkrusts/dk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "lexer.h"

/**
 * parse_redirection - creates a AST node for <redirection>
 * 
 *	<redirection>	::=	'<' <filename> <word_list>	# redir_in
 *					|	<word_list> '<' <filename>
 *					|	'<' <filename> 
 *					|
 *					|	'>' <filename> <word_list>	# redir_out
 *					|	<word_list> '>' <filename>
 *					|	'>' <filename>
 *					|
 *					|	'>>' <filename> <word_list>	# append
 *					|	<word_list> '>>' <filename>
 *					|	'>>' <filename>
 *					|
 *					|	'<<' <filename> <word_list>	# here_docs
 *					|	<word_list> '<<' <filename>
 *					|	'<<' <filename>
**/

t_astree	*parse_redirection(t_data *data)
{
	t_astree	*redirection;
	t_astree	*word_list;
	char		*filename;
	int			ast_node_type;

	word_list = parse_word_list(data);
	ast_node_type = get_ast_node_type(data->token_ptr->type);
	if (get_next_token(data, NULL, (HERE_DOC | REDIR_IN | APPEND | REDIR_OUT)))
	{
		delete_ast(word_list);
		return (NULL);
	}
	if (ast_node_type & AST_HERE_DOC && data->token_ptr->type & RMQUOTE)
		ast_node_type |= RMQUOTE;
	if (get_next_token(data, &filename, WORD))
	{
		delete_ast(word_list);
		return (NULL);
	}
	if (word_list == NULL)
		word_list = parse_word_list(data);
	redirection = (t_astree *)minishell_calloc(1, sizeof(t_astree));
	init_ast_node(redirection, filename, ast_node_type);
	insert_ast_node(redirection, NULL, word_list);
	return (redirection);
}

/**
 * parse_redirection_list - creates a AST node for <redirection_list>
 * 
 *	<redirection_list>	::= <redirection>
 *						|	<redirection_list> <redirection>
**/

static int	abs_gnt(t_data *data, char **token_str, int token_type, t_ptr ptr)
{
	if (get_next_token(data, token_str, token_type))
	{
		data->token_ptr = ptr.token_backup;
		delete_ast(ptr.word_list);
		return (1);
	}
	return (0);
}

t_astree	*parse_redirection_list(t_data *data)
{
	t_ptr		ptr;
	char		*filename;
	int			ast_node_type;

	ptr.token_backup = data->token_ptr;
	ptr.word_list = parse_word_list(data);
	ast_node_type = get_ast_node_type(data->token_ptr->type);
	if (abs_gnt(data, NULL, (HERE_DOC | REDIR_IN | APPEND | REDIR_OUT), ptr))
		return (NULL);
	if (ast_node_type & AST_HERE_DOC && data->token_ptr->type & RMQUOTE)
		ast_node_type |= RMQUOTE;
	if (abs_gnt(data, &filename, WORD, ptr))
		return (NULL);
	if (ptr.word_list == NULL)
		ptr.word_list = parse_word_list(data);
	ptr.redirection = parse_redirection_list(data);
	ptr.redirection_list = (t_astree *)minishell_calloc(1, sizeof(t_astree));
	init_ast_node(ptr.redirection_list, filename, ast_node_type);
	insert_ast_node(ptr.redirection_list, ptr.redirection, ptr.word_list);
	return (ptr.redirection_list);
}
