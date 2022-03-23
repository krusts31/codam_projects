/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts/dkrecisz <codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 15:54:28 by alkrusts/dk   #+#    #+#                 */
/*   Updated: 2021/11/03 08:14:26 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "minishell.h"

/**
 *	Strings used by the lexical analyzer
**/
# define METAS_CHAR			"<>|"
# define BREAK_CHAR			"<>| \t\n"
# define QUOTE_CHAR			"\"\'"
# define EXPANSION_CHAR		"$"
# define BLANK_CHAR			"\t "

/**
 * Token type macros
**/
# define EMPTY		0x0000
# define WORD		0x0001
# define PIPE		0x0002
# define HERE_DOC	0x0004
# define REDIR_IN	0x0008
# define APPEND		0x0010
# define REDIR_OUT	0x0020
# define EXPAND		0x0040
# define SQUOTE		0x0080
# define DQUOTE		0x0100
# define RMQUOTE	0x0200

int		lexer(t_data **data, char *line);

t_token	*init_token_list(size_t len);
void	init_new_token(t_token **token, size_t len, size_t *j, size_t i);
void	free_token_list(t_token *token);
void	make_token_meta(t_token **token, t_data **data, size_t *i, size_t *j);
void	make_token_quote(t_token **token, t_data **data, size_t *i, size_t *j);
int		get_token_type(char *s);
void	lexer_count_tokens(t_data *data);

char	*is_meta(char c);
char	*is_break(char c);
char	*is_quote(char c);
char	*is_expansion(char c);
char	*is_blank(char c);
void	get_exit_status(t_data **data, t_token **token, size_t *i, size_t *j);
int		is_valid_expansion(char *str);
int		is_special_expansion(char *str);
int		is_quote_edge_case(t_data *data, size_t i);

#endif
