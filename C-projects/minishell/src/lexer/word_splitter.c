/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   word_splitter.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts/dkrecisz <codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 15:56:34 by alkrusts/dk   #+#    #+#                 */
/*   Updated: 2021/09/13 15:57:50 by alkrusts/dk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <stdlib.h>

static size_t	get_array_size(char const *s, const char *delim)
{
	size_t	size;

	size = 0;
	while (*s)
	{
		if (!ft_strchr(delim, *s) && (ft_strchr(delim, *(s + 1)) || \
			*(s + 1) == '\0'))
			size++;
		s++;
	}
	return (size);
}

static size_t	get_word_size(char const *s, const char *delim)
{
	size_t	i;
	size_t	j;
	char	*scope;

	scope = NULL;
	i = 0;
	while (s[i])
	{
		j = 0;
		while (delim[j])
		{
			if (s[i] == delim[j])
			{
				scope = (char *)s + i;
				return (scope - s);
			}
			j++;
		}
		i++;
	}
	if (scope == NULL)
		scope = (char *)s + ft_strlen(s);
	return (scope - s);
}

static void	free_array(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int	make_words(char **arr, const char *s, const char *delim)
{
	size_t	token_size;
	size_t	s_len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	s_len = ft_strlen(s);
	while (i < s_len)
	{
		while (ft_strchr(delim, s[i]) != NULL && s[i] != '\0')
			i++;
		token_size = get_word_size(s + i, delim);
		arr[j] = ft_substr(s + i, 0, token_size);
		if (arr[j] == NULL)
			return (1);
		j++;
		i += token_size;
	}
	arr[j] = NULL;
	return (0);
}

char	**word_splitter(char const *s, const char *delim)
{
	char		**array;
	size_t		size;

	if (s == NULL)
		return (NULL);
	if (!delim)
		delim = "";
	else
		delim = "\t\n";
	size = get_array_size(s, delim);
	array = (char **)minishell_calloc(size + 1, sizeof(char *));
	if (make_words(array, s, delim) == 1)
		free_array(array);
	return (array);
}
