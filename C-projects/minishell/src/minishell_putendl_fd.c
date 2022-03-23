/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell_putendl_fd.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts/dkrecisz <codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 15:57:15 by alkrusts/dk   #+#    #+#                 */
/*   Updated: 2021/10/27 13:11:59 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

ssize_t	minishell_putendl_fd(const char *s, int fd)
{
	ssize_t	ret;

	ret = minishell_putstr_fd(s, fd);
	ret += minishell_write(fd, "\n", 1);
	return (ret);
}
