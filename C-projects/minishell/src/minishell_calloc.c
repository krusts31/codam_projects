/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell_calloc.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts/dkrecisz <codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 15:57:10 by alkrusts/dk   #+#    #+#                 */
/*   Updated: 2021/09/13 15:57:36 by alkrusts/dk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <errno.h>

void	*minishell_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = ft_calloc(nmemb, size);
	if (!ptr)
		exit_minishell(errno);
	return (ptr);
}
