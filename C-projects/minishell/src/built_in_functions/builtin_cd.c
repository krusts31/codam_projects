/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_cd.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts/dkrecisz <codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 15:54:41 by alkrusts/dk   #+#    #+#                 */
/*   Updated: 2021/11/01 15:23:24 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "environ.h"
#include <errno.h>
#include <limits.h>
#include <string.h>

static int	builtin_cd_error(char *path, int error_id)
{
	minishell_putstr_fd("minishell: cd: ", 2);
	minishell_putstr_fd(path, 2);
	minishell_putstr_fd(": ", 2);
	minishell_putendl_fd(strerror(error_id), 2);
	errno = 0;
	return (1);
}

static int	print_usage(void)
{
	minishell_putendl_fd("minishell: cd: single argument required", 2);
	return (1);
}

int	builtin_cd(t_command *cmd, t_environ *env)
{
	char	cwd[PATH_MAX + 1];

	errno = 0;
	if (cmd->argc != 2)
		return (print_usage());
	if (getcwd(cwd, PATH_MAX) == NULL)
	{
		if (errno == 2)
			builtin_cd_error(cmd->argv[1], errno);
		else
			return (errno);
	}
	environ_set(env, "OLDPWD", cwd);
	if (chdir(cmd->argv[1]) == -1)
		return (builtin_cd_error(cmd->argv[1], errno));
	getcwd(cwd, PATH_MAX);
	if (getcwd(cwd, PATH_MAX) == NULL)
	{
		if (errno == 2)
			errno = 0;
		else
			return (errno);
	}
	environ_set(env, "PWD", cwd);
	return (0);
}
