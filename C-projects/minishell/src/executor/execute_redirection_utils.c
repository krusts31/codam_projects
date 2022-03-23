/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_redirection_utils.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 15:26:08 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/11/04 19:42:22 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include <stdlib.h>
#include <fcntl.h>

void	pop_node_left(t_exec *stru, t_astree **node)
{
	stru->parent = (*node)->parent;
	stru->node = (*node);
	(*node) = (*node)->left;
	(*node)->parent = stru->parent;
	if (stru->node->right)
	{
		stru->node->right->parent = (*node);
		(*node)->right = stru->node->right;
	}
	if (stru->node)
	{
		if (stru->node->str)
			free(stru->node->str);
		free(stru->node);
		stru->node = NULL;
	}
}

void	delete_parent(t_exec *stru, t_astree **node)
{
	stru->parent = (*node)->parent;
	if ((*node)->parent)
	{
		(*node)->right = (*node)->parent->right;
		(*node)->parent = (*node)->parent->parent;
	}
	if ((*node)->parent)
	{
		if ((*node)->parent->right == stru->parent)
			(*node)->parent->right = *node;
		else
			(*node)->parent->left = *node;
	}
	if (stru->parent)
	{
		free(stru->parent->str);
		stru->parent->str = NULL;
		free(stru->parent);
		stru->parent = NULL;
	}
	if ((*node)->right)
		(*node)->right->parent = *node;
	stru->root = *node;
}

void	create_file(t_astree *node, t_file_io *fd)
{
	if (node->type & AST_REDIR_OUT)
		fd->output = open(node->str, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	else if (node->type & AST_APPEND)
		fd->output = open(node->str, O_CREAT | O_APPEND | O_WRONLY, 0644);
}

void	shift_arguments(t_exec *stru, t_astree *node, t_astree *parent)
{
	t_astree	*tmp;
	t_astree	*save_node;

	save_node = node;
	tmp = stru->root->right;
	while (tmp->right)
		tmp = tmp->right;
	parent->right = NULL;
	node = save_node;
	node->parent = tmp;
	node->parent->right = node;
}
