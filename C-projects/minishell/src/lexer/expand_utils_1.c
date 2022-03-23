/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_utils_1.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts/dkrecisz <codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 15:55:55 by alkrusts/dk   #+#    #+#                 */
/*   Updated: 2021/09/13 15:57:58 by alkrusts/dk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"
#include "lexer.h"
#include "environ.h"
#include <stdlib.h>
#include <errno.h>

void	free_substrings(t_list *substrings)
{
	t_list	*tmp;

	while (substrings)
	{
		tmp = substrings->next;
		if (substrings->content)
			free(substrings->content);
		free(substrings);
		substrings = tmp;
	}
}

int	check_expansion(t_token *token)
{
	size_t	i;

	i = 0;
	while (token->str[i])
	{
		if (is_valid_expansion(token->str + i))
		{
			token->type |= EXPAND;
			return (TRUE);
		}
		i++;
	}
	token->type &= ~(EXPAND);
	return (FALSE);
}

void	init_expansion(t_expansion *exp)
{
	exp->i = 0;
	exp->copy_start = 0;
	exp->substrings = (t_list *)minishell_calloc(1, sizeof(t_list));
}

int	is_valid_variable_char(char c)
{
	return (ft_isalnum(c) || c == '_');
}

void	get_keyvalue(t_expansion *exp, char *str, t_environ *env)
{
	size_t	i;
	size_t	j;
	char	*value;

	i = 1;
	j = 0;
	exp->var_key = (char *)minishell_calloc(ft_strlen(str), sizeof(char));
	while (is_valid_variable_char(str[i]))
	{
		exp->var_key[j] = str[i];
		i++;
		j++;
	}
	value = environ_get(env, exp->var_key);
	if (value == NULL)
		value = "";
	exp->var_value = ft_strdup(value);
	if (exp->var_value == 0 && errno == 0)
		exp->var_value = "";
	else if (!exp->var_value && errno)
		exit_minishell(errno);
}
