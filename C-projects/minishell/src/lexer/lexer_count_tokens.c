/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer_count_tokens.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 13:51:58 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/10/28 13:58:32 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lexer_count_tokens(t_data *data)
{
	t_token	*tmp;
	int		i;

	i = 0;
	tmp = data->token;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	if (i >= TOKEN_MAX)
		exit_minishell(2);
}
