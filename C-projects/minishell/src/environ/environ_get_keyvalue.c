/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   environ_get_keyvalue.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/13 10:46:58 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/11/01 14:18:19 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "environ.h"
#include "libft.h"

#include <stdlib.h>
#include <errno.h>

/**
 * environ_get_keyvalue - creates a key-value pair in one string
 *  
 * just for a reminder why we need to add '+2' for calculating len:
 * length of key-value pair = length of key + '=' + length of value + '\0'
 * 
 * */

char	*environ_get_keyvalue(char *key, char *value)
{
	char	*keyvalue;
	size_t	len;
	size_t	key_len;
	size_t	value_len;

	if (key == NULL)
		return (NULL);
	if (value == NULL)
	{
		value = ft_strdup("");
		if (value == NULL)
			exit_minishell(errno);
	}
	key_len = ft_strlen(key);
	value_len = ft_strlen(value);
	len = key_len + value_len + 2;
	keyvalue = (char *)minishell_calloc(len, sizeof(char));
	ft_strlcpy(keyvalue, key, key_len + 1);
	ft_strlcat(keyvalue, "=", len + 1);
	ft_strlcat(keyvalue, value, len + 1);
	return (keyvalue);
}

t_environ	*environ_new_empty(const char *key_value)
{
	t_environ	*new;

	new = (t_environ *)minishell_calloc(1, sizeof(t_environ));
	new->key = ft_strdup(key_value);
	new->value = ft_strdup("");
	new->key_value = ft_strdup(key_value);
	if (new->key_value == NULL || new->value == NULL || new->key == NULL)
		exit_minishell(errno);
	return (new);
}

t_environ	*environ_addition(const char *key_value)
{
	t_environ	*n3w;
	size_t		key_len;
	size_t		key_value_len;

	key_value_len = ft_strlen(key_value);
	n3w = (t_environ *)minishell_calloc(1, sizeof(t_environ));
	n3w->key = (char *)minishell_calloc(key_value_len + 1, sizeof(char));
	n3w->value = (char *)minishell_calloc(key_value_len + 1, sizeof(char));
	n3w->key_value = ft_strdup(key_value);
	if (n3w->key_value == NULL)
		exit_minishell(errno);
	key_len = ft_strnstr(key_value, "+=", ft_strlen(key_value)) - key_value;
	ft_strlcpy(n3w->key, key_value, key_len + 1);
	ft_strlcpy(n3w->value, key_value + key_len + 2, key_value_len);
	return (n3w);
}

int	environ_add_to_env(t_environ **varible, char *key, char *value)
{
	char	*tmp;

	tmp = ft_strjoin((*varible)->value, value);
	if (tmp == NULL)
		exit_minishell(errno);
	free((*varible)->value);
	(*varible)->value = tmp;
	free((*varible)->key_value);
	(*varible)->key_value = environ_get_keyvalue(key, (*varible)->value);
	return (1);
}
