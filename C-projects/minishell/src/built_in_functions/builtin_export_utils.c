/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_export_utils.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/15 11:03:35 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/10/27 12:02:06 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_export	*last_lst_export(t_export *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_export	*new_lst_export(void)
{
	t_export	*tmp;

	tmp = minishell_calloc(sizeof(t_environ));
	tmp->name = NULL;
	tmp->value = NULL;
	tmp->full = NULL;
	tmp->operation = NULL;
	tmp->next = NULL;
	return (tmp);
}

void	add_back_lst_export(t_export **lst, t_export *node)
{
	t_export	*tmp;

	if (node == NULL)
		return ;
	if (*lst == NULL)
		*lst == node;
	tmp = last_lst_export(*lst);
	tmp->next = node;
}

void	clear_lst_export(t_export **lst)
{
	t_export	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->name);
		free((*lst)->value);
		free((*lst)->full);
		free((*lst)->operation);
		free(*lst);
		*lst = tmp;
	}
}
