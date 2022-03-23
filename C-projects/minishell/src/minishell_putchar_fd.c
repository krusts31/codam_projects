/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell_putchar_fd.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts/dkrecisz <codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 15:57:13 by alkrusts/dk   #+#    #+#                 */
/*   Updated: 2021/10/27 13:11:48 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

ssize_t	minishell_putchar_fd(const char c, int fd)
{
	return (minishell_write(fd, &c, 1));
}
