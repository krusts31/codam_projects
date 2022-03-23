/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_echo.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts/dkrecisz <codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 15:54:43 by alkrusts/dk   #+#    #+#                 */
/*   Updated: 2021/10/18 06:11:13 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <unistd.h>

static int	is_valid_option(char *s)
{
	size_t	i;

	if (s[0] != '-' || !s[1])
		return (0);
	if (ft_strncmp("-n", s, 3) == 0)
		return (1);
	i = 1;
	while (s[i])
	{
		if (s[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

static int	get_option(t_command *cmd, int *option)
{
	int	i;

	i = 1;
	*option = 0;
	while (i < cmd->argc && is_valid_option(cmd->argv[i]))
	{
		*option = 1;
		i++;
	}
	return (i);
}

int	builtin_echo(t_command *cmd)
{
	ssize_t	write_ret;
	int		option;
	int		i;

	write_ret = 0;
	option = 0;
	if (cmd->argc > 1)
	{
		i = get_option(cmd, &option);
		while (i < cmd->argc && write_ret >= 0)
		{
			write_ret = ft_putstr_fd(cmd->argv[i], cmd->fd->write);
			i++;
			if (i < cmd->argc && write_ret >= 0)
				write_ret = write(cmd->fd->write, " ", 1);
		}
	}
	if (option == 0 && write_ret >= 0)
		write_ret = write(cmd->fd->write, "\n", 1);
	if (write_ret == -1)
		return (-1);
	return (0);
}
