/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_redirection.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/09 04:16:44 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/11/06 13:01:08 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"
#include "parser.h"
#include "lexer.h"
#include <fcntl.h>
#include <errno.h>

static int	open_file(t_file_io *fd, t_data *data, t_astree *node)
{
	if (node->type & AST_REDIR_IN)
		fd->input = open(node->str, O_RDONLY);
	else if (node->type & AST_HERE_DOC)
		fd->input = 0;
	if (fd->input == -1)
	{
		print_error(data, node->str, errno);
		while (node->parent)
			node = node->parent;
		data->astree = node;
		data->exit_status = 1;
		return (1);
	}
	return (0);
}

static int	redirect_input(t_exec *stru, t_file_io *fd, t_data *data,
		t_astree *node)
{
	if (fd->input)
	{
		close(fd->input);
		delete_parent(stru, &node);
	}
	return (open_file(fd, data, node));
}

static int	redirect_output(t_exec *stru, t_file_io *fd, t_astree *node)
{
	if (fd->output)
		close(fd->output);
	if (fd->output || node->parent)
	{
		if (node->parent->type & (AST_HERE_DOC | AST_REDIR_OUT | AST_APPEND))
			delete_parent(stru, &node);
		else if (is_redirection(node->parent->type)
			&& node->right && node->right->type & AST_WORD)
			shift_arguments(stru, node->right, node);
	}
	create_file(node, fd);
	if (fd->output == -1)
		return (1);
	fd->write = fd->output;
	return (0);
}

static void	execute_stuff(t_data *data, t_astree *node)
{
	if ((data->token_mask & PIPE) == 0)
	{
		while (node->parent)
			node = node->parent;
	}
	if ((data->token_mask & PIPE) == 0)
		data->astree = node;
	if (data->astree->right && data->astree->right->type
		& AST_WORD && (data->token_mask & PIPE) == 0)
		execute_word_list(data, data->astree->right);
	else if (node && node->type == AST_WORD)
		execute_word_list(data, node);
}

void	execute_redirection(t_data *data, t_astree *node, t_file_io *fd)
{
	t_exec		stru;

	stru.root = node;
	while (node && is_redirection(node->type))
	{
		if (node->type & AST_REDIR_IN)
		{
			if (redirect_input(&stru, fd, data, node) == 1)
				return ;
		}
		else if (node->type & (AST_REDIR_OUT | AST_APPEND))
		{
			if (redirect_output(&stru, fd, node) == 1)
				return (print_error(data, node->str, errno));
		}
		else if (node->type & AST_HERE_DOC)
			node = execute_here_doc(data, node, fd, &stru);
		if (node->left)
			node = node->left;
		else if (node->right)
			node = node->right;
		else
			break ;
	}
	execute_stuff(data, node);
}
