/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   environ.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts/dkrecisz <codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 15:55:04 by alkrusts/dk   #+#    #+#                 */
/*   Updated: 2021/11/02 10:31:24 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "environ.h"
#include <errno.h>
#include <stdlib.h>

void	environ_add_back(t_environ **env, t_environ *new)
{
	t_environ	*tmp;

	tmp = *env;
	if (new == NULL)
		return ;
	if (*env == NULL)
		*env = new;
	else
	{
		while (tmp->next)
		{
			if (environ_compare(new->key, tmp->key))
			{
				free(tmp->value);
				free(tmp->key_value);
				tmp->value = new->value;
				tmp->key_value = new->key_value;
				free(new->key);
				free(new);
				return ;
			}
			tmp = tmp->next;
		}
		tmp->next = new;
	}
}

t_environ	*environ_new(const char *key_value)
{
	t_environ	*n3w;
	size_t		key_len;
	size_t		key_value_len;

	if (!key_value || key_value[0] == 0)
		return (NULL);
	if (ft_strnstr(key_value, "+=", ft_strlen(key_value)) != NULL)
		return (environ_addition(key_value));
	if (ft_strchr(key_value, '=') == NULL)
		return (environ_new_empty(key_value));
	key_value_len = ft_strlen(key_value);
	n3w = (t_environ *)minishell_calloc(1, sizeof(t_environ));
	n3w->key = (char *)minishell_calloc(key_value_len + 1, sizeof(char));
	n3w->value = (char *)minishell_calloc(key_value_len + 1, sizeof(char));
	n3w->key_value = ft_strdup(key_value);
	if (n3w->key_value == NULL)
		exit_minishell(errno);
	key_len = ft_strchr(key_value, '=') - key_value;
	ft_strlcpy(n3w->key, key_value, key_len + 1);
	ft_strlcpy(n3w->value, key_value + key_len + 1, key_value_len);
	return (n3w);
}

t_environ	*environ_deep_copy(char **env, char **argv)
{
	t_environ	*head;
	size_t		i;
	char		*tmp;

	i = 0;
	head = NULL;
	tmp = ft_strjoin("SHELL=", argv[0]);
	if (tmp == NULL)
		exit_minishell(errno);
	environ_add_back(&head, environ_new(tmp));
	free(tmp);
	if (env == NULL || *env == NULL)
		return (NULL);
	while (env[i])
	{
		if (ft_strnstr(env[i], "SHELL", 5) != 0)
			i++;
		else
		{
			environ_add_back(&head, environ_new(env[i]));
			i++;
		}
	}
	return (head);
}

void	environ_modify(t_environ **head, t_environ *new)
{
	t_environ	*tmp;

	tmp = *head;
	while (*head && tmp && new->key)
	{
		if (environ_compare(tmp->key, new->key))
		{
			if (new->key_value != NULL)
			{
				if (ft_strnstr(new->key_value, "+=", ft_strlen(new->key_value)))
					environ_add_to_env(&tmp, new->key, new->value);
				else
				{
					free(tmp->value);
					free(tmp->key_value);
					tmp->value = minishell_strdup(new->value);
					tmp->key_value = environ_get_keyvalue(new->key, new->value);
				}
				return ;
			}
		}
		tmp = tmp->next;
	}
}

void	environ_set(t_environ *head, char *key, char *value)
{
	t_environ	*new;

	if (key == NULL || key[0] == 0)
		return ;
	if (environ_get(head, key))
	{
		new = (t_environ *)minishell_calloc(1, sizeof(t_environ));
		new->key = key;
		new->value = value;
		new->key_value = environ_get_keyvalue(new->key, new->value);
		environ_modify_prep(&head, new);
		return ;
	}
	new = (t_environ *)minishell_calloc(1, sizeof(t_environ));
	new->key = ft_strdup(key);
	if (new->key == NULL)
		exit_minishell(errno);
	if (value == NULL)
		new->value = ft_strdup("");
	else
		new->value = ft_strdup(value);
	if (new->value == NULL)
		exit_minishell(errno);
	new->key_value = environ_get_keyvalue(new->key, new->value);
	environ_add_back(&head, new);
}
