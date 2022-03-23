/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts/dkrecisz <codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 15:54:32 by alkrusts/dk   #+#    #+#                 */
/*   Updated: 2021/09/13 15:58:37 by alkrusts/dk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

/**
 * Abstract syntax tree node macros
**/
# define AST_PIPE		0x0001
# define AST_HERE_DOC	0x0002
# define AST_REDIR_IN	0x0004
# define AST_APPEND		0x0008
# define AST_REDIR_OUT	0x0010
# define AST_WORD		0x0020

void		parser(t_data *data);

void		init_ast_node(t_astree *node, char *arg, int type);
void		insert_ast_node(t_astree *node, t_astree *left, t_astree *right);
void		delete_ast(t_astree *node);
int			get_ast_node_type(int type);
int			is_redirection(int node_type);

t_astree	*parse_pipeline(t_data *data);
t_astree	*parse_pipe_sequence(t_data *data);
t_astree	*parse_command(t_data *data);
t_astree	*parse_word_list(t_data *data);
t_astree	*parse_redirection(t_data *data);
t_astree	*parse_redirection_list(t_data *data);

int			get_next_token(t_data *data, char **token_str, int token_type);

#endif
