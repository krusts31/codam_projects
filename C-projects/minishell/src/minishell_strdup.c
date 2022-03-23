/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell_strdup.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/13 08:49:55 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/10/13 08:50:00 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

char	*minishell_strdup(const char *s)
{
	char	*ptr;
	size_t	x;
	size_t	y;

	y = 0;
	x = ft_strlen(s);
	ptr = minishell_calloc(x + 1, sizeof(char));
	while (s[y])
	{
		ptr[y] = s[y];
		y++;
	}
	return (ptr);
}
