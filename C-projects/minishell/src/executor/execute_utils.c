/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts/dkrecisz <codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 15:58:09 by alkrusts/dk   #+#    #+#                 */
/*   Updated: 2021/11/02 14:47:10 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"
#include "environ.h"
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

static void	save_child_pid(t_data *data, pid_t pid)
{
	t_child	*tmp;
	t_child	*new;

	if (data == NULL || pid == 0)
		return ;
	tmp = data->child;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
	}
	new = (t_child *)minishell_calloc(1, sizeof(t_child));
	new->pid = pid;
	if (data->child == NULL)
		data->child = new;
	else
		tmp->next = new;
	tmp = data->child;
	while (tmp->next)
	{
		tmp->last = 0;
		tmp = tmp->next;
	}
	new->last = 1;
}

static void	free_command_argv(t_command *cmd, char **env_array)
{
	size_t	i;

	errno = 0;
	i = 0;
	if (cmd != NULL || cmd->argv != NULL)
	{
		while (cmd->argv[i])
		{
			free(cmd->argv[i]);
			i++;
		}
		free(cmd->argv);
		i = 0;
	}
	if (env_array != NULL)
	{
		while (env_array[i])
		{
			free(env_array[i]);
			i++;
		}
		free(env_array);
	}
}

static void	set_fds(t_command *cmd)
{
	if (errno == 0 && cmd->fd->dup_stdin)
		dup2(cmd->fd->read, STDIN_FILENO);
	if (errno == 0 && cmd->fd->dup_stdout)
	{
		if (cmd->fd->pipe[0])
			close(cmd->fd->pipe[0]);
		dup2(cmd->fd->write, STDOUT_FILENO);
	}
	else if (errno == 0 && cmd->fd->dup_stdout == 0 && cmd->fd->output == 0)
	{
		if (cmd->fd->pipe[0])
			close(cmd->fd->pipe[0]);
		dup2(cmd->fd->save_stdout, STDOUT_FILENO);
	}
	if (errno == 0 && cmd->fd->output)
		dup2(cmd->fd->output, STDOUT_FILENO);
	if (errno == 0 && cmd->fd->input)
		dup2(cmd->fd->input, STDIN_FILENO);
}

static void	execute_child(t_command *cmd, char **env_array, t_data *data)
{
	if (env_array == NULL)
		env_array = creat_fresh_array();
	errno = 0;
	set_fds(cmd);
	if (cmd->builtin_id)
	{
		execute_builtin(data, cmd, data->env);
		exit(data->exit_status);
	}
	else if (cmd->builtin_id == 0)
		execve(cmd->argv[0], cmd->argv, env_array);
	if (errno)
	{
		dup2(cmd->fd->save_stdout, STDOUT_FILENO);
		if (cmd->argv != NULL)
			printf("minishell$: %s - Error: %s [%d]\n",
				cmd->argv[0], strerror(errno), errno);
		if (errno == 13)
			exit(126);
		if (errno == 2)
			exit(127);
		exit(errno);
	}
	exit(0);
}

void	execute_command_argv(t_data *data, t_command *cmd, t_environ *env)
{
	pid_t	pid;
	char	**env_array;

	data->exit_status = 0;
	env_array = environ_get_array(env);
	if (signal(SIGINT, sig_int_child) == SIG_ERR
		|| signal(SIGQUIT, sig_quit_child) == SIG_ERR)
		exit_minishell_custom("ERROR SIGINT OR SIGQUIT");
	pid = fork();
	if (isatty(STDIN_FILENO))
		tcsetattr(cmd->fd->save_stdin, TCSANOW, &data->old_term);
	if (pid == -1)
		exit_minishell(errno);
	else if (pid == 0)
		execute_child(cmd, env_array, data);
	save_child_pid(data, pid);
	free_command_argv(cmd, env_array);
}
