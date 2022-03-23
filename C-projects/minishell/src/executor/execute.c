/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts/dkrecisz <codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 15:55:40 by alkrusts/dk   #+#    #+#                 */
/*   Updated: 2021/11/02 14:46:50 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "executor.h"
#include <errno.h>
#include <sys/wait.h>

static void	setup_fd(t_data *data)
{
	data->fd->read = STDIN_FILENO;
	data->fd->write = STDOUT_FILENO;
	data->fd->save_stdin = dup(STDIN_FILENO);
	data->fd->save_stdout = dup(STDOUT_FILENO);
	if (errno)
		exit_minishell(errno);
}

void	restore_fd(t_file_io *fd)
{
	dup2(fd->save_stdin, STDIN_FILENO);
	dup2(fd->save_stdout, STDOUT_FILENO);
	close(fd->save_stdin);
	fd->save_stdin = 0;
	close(fd->save_stdout);
	fd->save_stdout = 0;
	if (fd->pipe[0])
		close(fd->pipe[0]);
	fd->pipe[0] = 0;
	if (fd->pipe[1])
		close(fd->pipe[1]);
	fd->pipe[1] = 0;
	if (fd->here_doc[0])
		close(fd->here_doc[0]);
	fd->here_doc[0] = 0;
	if (fd->here_doc[1])
		close(fd->here_doc[1]);
	fd->here_doc[1] = 0;
	if (fd->output)
		close(fd->output);
	fd->output = 0;
	if (fd->input)
		close(fd->input);
	fd->input = 0;
}

static void	get_the_last_exit_staus(t_data *data, int stat)
{
	if (WIFEXITED(stat))
		data->exit_status = WEXITSTATUS(stat);
	if (WTERMSIG(stat) == 2)
		data->exit_status = 130;
	if (WTERMSIG(stat) == 3)
		data->exit_status = 131;
	if (g_sig == 130 || g_sig == 131 || g_sig == 1)
		data->exit_status = g_sig;
}

static void	terminate(t_data *data)
{
	int		stat;
	pid_t	pid;
	t_child	*tmp;
	pid_t	last;

	tmp = data->child;
	last = 0;
	while (tmp)
	{
		if (tmp->last)
			last = tmp->pid;
		tmp = tmp->next;
	}
	tmp = data->child;
	while (tmp)
	{
		pid = wait(&stat);
		if (pid == last)
			get_the_last_exit_staus(data, stat);
		tmp = tmp->next;
	}
	free_child_pid(data->child);
	data->child = NULL;
}

void	execute(t_data *data)
{
	if (data->astree == NULL)
		return ;
	setup_fd(data);
	if (data->token_mask & PIPE)
		execute_pipeline(data);
	else
		execute_command(data, data->astree);
	restore_fd(data->fd);
	terminate(data);
	if (isatty(STDIN_FILENO))
		tcsetattr(data->fd->save_stdin, TCSANOW, &data->new_term);
	if (signal(SIGINT, sig_int_parent) == SIG_ERR)
		exit_minishell_custom("Error SIGINT ");
	if (signal(SIGQUIT, sig_quit_parent) == SIG_ERR)
		exit_minishell_custom("Error SIGQUIT ");
}
