/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_utils_2.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts/dkrecisz <codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 15:56:04 by alkrusts/dk   #+#    #+#                 */
/*   Updated: 2021/09/13 15:57:57 by alkrusts/dk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "expansion.h"
#include "lexer.h"
#include <errno.h>
#include <stdlib.h>

void	append_string(char *dest, char *suffix)
{
	size_t	offset;
	size_t	i;

	if (suffix == NULL)
		return ;
	offset = ft_strlen(dest);
	i = 0;
	while (suffix[i])
	{
		dest[offset] = suffix[i];
		i++;
		offset++;
	}
}

char	*merge_node_strings(t_list *head)
{
	t_list	*tmp;
	size_t	len;
	char	*merged_string;

	tmp = head;
	len = 0;
	while (tmp)
	{
		if (tmp->content)
			len += ft_strlen((const char *)tmp->content);
		tmp = tmp->next;
	}
	merged_string = (char *)minishell_calloc(len + 1, sizeof(char));
	tmp = head;
	while (tmp)
	{
		append_string(merged_string, (char *)tmp->content);
		tmp = tmp->next;
	}
	return (merged_string);
}

void	add_substring(t_expansion *exp, char *str)
{
	ft_lstadd_back(&exp->substrings, ft_lstnew((char *)
			ft_substr(str, exp->copy_start, exp->i - exp->copy_start)));
	if (errno)
		exit_minishell(errno);
}

void	add_expanded_variable(t_expansion *exp)
{
	ft_lstadd_back(&exp->substrings, ft_lstnew(exp->var_value));
	if (errno)
		exit_minishell(errno);
}

void	do_variable_expansion(t_token *token, t_environ *env)
{
	t_expansion	exp;

	init_expansion(&exp);
	while (token->str[exp.i])
	{
		if (is_valid_expansion(token->str + exp.i))
		{
			add_substring(&exp, token->str);
			get_keyvalue(&exp, token->str + exp.i, env);
			add_expanded_variable(&exp);
			exp.i += ft_strlen(exp.var_key) + 1;
			exp.copy_start = exp.i;
			free(exp.var_key);
		}
		else
			exp.i++;
	}
	add_substring(&exp, token->str);
	exp.merged_string = merge_node_strings(exp.substrings);
	free_substrings(exp.substrings);
	free(token->str);
	token->str = exp.merged_string;
}
