/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_builtin.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts/dkrecisz <codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 15:55:21 by alkrusts/dk   #+#    #+#                 */
/*   Updated: 2021/11/01 11:24:38 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtins.h"

static int	is_end_of_pipe(t_command *cmd)
{
	return (cmd->fd->dup_stdin == 1 && cmd->fd->dup_stdout == 0);
}

void	execute_builtin(t_data *data, t_command *cmd, t_environ *env)
{
	if (is_end_of_pipe(cmd))
	{
		if (cmd->fd->output == 0)
			cmd->fd->write = cmd->fd->save_stdout;
	}
	if (cmd->builtin_id == BUILTIN_ECHO)
		data->exit_status = builtin_echo(cmd);
	else if (cmd->builtin_id == BUILTIN_CD)
		data->exit_status = builtin_cd(cmd, env);
	else if (cmd->builtin_id == BUILTIN_PWD)
		data->exit_status = builtin_pwd(cmd);
	else if (cmd->builtin_id == BUILTIN_EXPORT)
	{
		data->exit_status = builtin_export(cmd, &env);
		data->env = env;
	}
	else if (cmd->builtin_id == BUILTIN_UNSET)
		data->exit_status = builtin_unset(data, cmd);
	else if (cmd->builtin_id == BUILTIN_ENV)
		data->exit_status = builtin_env(cmd, env);
	else if (cmd->builtin_id == BUILTIN_EXIT)
		data->exit_status = builtin_exit(cmd);
}
