/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   split_words.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts/dkrecisz <codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 15:56:32 by alkrusts/dk   #+#    #+#                 */
/*   Updated: 2021/11/03 10:18:42 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "expansion.h"
#include "lexer.h"
#include "libft.h"
#include <stdlib.h>
#include <errno.h>

static void	make_word_list(t_token	*token, char **words)
{
	size_t	i;

	i = 0;
	free(token->str);
	while (1)
	{
		token->str = words[i];
		token->type |= WORD;
		i++;
		if (words[i])
		{
			token->next = (t_token *)minishell_calloc(1, sizeof(t_token));
			token = token->next;
		}
		else
			break ;
	}
}

static int	check_split(char *str)
{
	if (ft_strchr(str, ' ') || ft_strchr(str, '\t') || ft_strchr(str, '\n'))
		return (TRUE);
	return (FALSE);
}

void	split_words(t_token *token)
{
	char	**words;

	if (check_split(token->str) == FALSE)
		return ;
	words = word_splitter(token->str, " \t\n");
	if (words == NULL && errno)
		exit_minishell(errno);
	make_word_list(token, words);
}
