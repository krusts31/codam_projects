/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_env.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts/dkrecisz <codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 15:54:45 by alkrusts/dk   #+#    #+#                 */
/*   Updated: 2021/10/26 13:39:01 by alkrusts/dk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <errno.h>

int	builtin_env(t_command *cmd, t_environ *env)
{
	errno = 0;
	if (cmd->argc > 1)
	{
		minishell_putendl_fd("minishell: env: arguments are not supported", 2);
		return (ECANCELED);
	}
	while (env && errno == 0)
	{
		if (ft_strrchr(env->key_value, '='))
			minishell_putendl_fd(env->key_value, cmd->fd->write);
		env = env->next;
	}
	return (errno);
}
