/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   environ_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts/dkrecisz <codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 15:55:01 by alkrusts/dk   #+#    #+#                 */
/*   Updated: 2021/10/28 14:43:07 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <errno.h>

int	environ_compare(char *s1, char *s2)
{
	return (ft_strlen(s1) == ft_strlen(s2) && \
		ft_strncmp(s1, s2, ft_strlen(s2)) == 0);
}

char	*environ_get(t_environ *head, char *key)
{
	t_environ	*tmp;

	if (head == NULL || key == NULL)
		return (NULL);
	tmp = head;
	while (tmp && key)
	{
		if (environ_compare(tmp->key, key))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

void	environ_unset(t_environ **head, char *key)
{
	t_environ	*tmp;
	t_environ	*previous;

	if (head == NULL || *head == NULL)
		return ;
	tmp = *head;
	previous = NULL;
	while (key && tmp)
	{
		if (environ_compare(tmp->key, key))
		{
			free(tmp->key);
			free(tmp->value);
			free(tmp->key_value);
			if (previous)
				previous->next = tmp->next;
			else if (previous == NULL)
				*head = tmp->next;
			free(tmp);
			tmp = previous;
			return ;
		}
		previous = tmp;
		tmp = tmp->next;
	}
}

void	environ_free(t_environ *head)
{
	t_environ	*tmp;
	t_environ	*save;

	if (head == NULL)
		return ;
	tmp = head;
	while (tmp)
	{
		save = tmp->next;
		free(tmp->key);
		free(tmp->value);
		free(tmp->key_value);
		free(tmp);
		tmp = NULL;
		tmp = save;
	}
}

char	**environ_get_array(t_environ *env)
{
	t_environ	*tmp;
	char		**array;
	size_t		i;

	i = 0;
	tmp = env;
	if (env == NULL)
		return (NULL);
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	array = (char **)minishell_calloc(i + 1, sizeof(char *));
	i = 0;
	tmp = env;
	while (tmp)
	{
		if (tmp->key_value == NULL)
			exit_minishell_custom(". environ_utils:107\n");
		array[i] = minishell_strdup(tmp->key_value);
		tmp = tmp->next;
		i++;
	}
	return (array);
}
