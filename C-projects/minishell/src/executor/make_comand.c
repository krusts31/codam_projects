/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_comand.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/13 12:09:08 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/10/18 05:53:14 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"
#include "parser.h"
#include "libft.h"

#include <errno.h>

static void	init_cmd(t_data *data, t_command *cmd)
{
	cmd->exit_status = data->exit_status;
	cmd->fd = data->fd;
	cmd->env = data->env;
}

void	make_command(t_data *data, t_astree *node, t_command *cmd)
{
	t_astree	*tmp;

	cmd->argc = 0;
	tmp = node;
	while (tmp && tmp->type & (AST_WORD))
	{
		cmd->argc++;
		tmp = tmp->right;
	}
	cmd->argv = (char **)minishell_calloc(cmd->argc + 1, sizeof(char *));
	cmd->argc = 0;
	tmp = node;
	while (tmp && tmp->type & (AST_WORD))
	{
		if (cmd->argc == 0)
			cmd->builtin_id = search_command(tmp, data->env);
		cmd->argv[cmd->argc] = ft_strdup(tmp->str);
		if (cmd->argv[cmd->argc] == NULL)
			exit_minishell(errno);
		cmd->argc++;
		tmp = tmp->right;
	}
	init_cmd(data, cmd);
}
