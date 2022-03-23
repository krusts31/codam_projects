/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_pipeline.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts/dkrecisz <codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 15:58:09 by alkrusts/dk   #+#    #+#                 */
/*   Updated: 2021/10/27 13:06:10 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"
#include "parser.h"
#include <errno.h>

static void	setup_next_pipe(t_file_io *fd)
{
	close(fd->write);
	fd->read = fd->pipe[0];
	if (pipe(fd->pipe) == -1)
		exit_minishell(errno);
	fd->write = fd->pipe[1];
	fd->dup_stdout = 1;
	fd->dup_stdin = 1;
}

static void	setup_pipe_end(t_file_io *fd)
{
	close(fd->write);
	fd->read = fd->pipe[0];
	fd->dup_stdin = 1;
	fd->dup_stdout = 0;
}

void	execute_pipeline(t_data *data)
{
	t_astree	*node;

	if (pipe(data->fd->pipe) == -1)
		exit_minishell(errno);
	data->fd->dup_stdin = 0;
	data->fd->dup_stdout = 1;
	data->fd->read = data->fd->pipe[0];
	data->fd->write = data->fd->pipe[1];
	data->fd->output = 0;
	execute_command(data, data->astree->left);
	node = data->astree->right;
	while (node && node->type == AST_PIPE)
	{
		setup_next_pipe(data->fd);
		execute_command(data, node->left);
		close(data->fd->read);
		node = node->right;
	}
	setup_pipe_end(data->fd);
	execute_command(data, node);
	close(data->fd->pipe[0]);
}
