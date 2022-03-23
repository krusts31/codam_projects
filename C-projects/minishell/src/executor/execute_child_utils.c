/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_child_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/02 09:57:31 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/11/02 10:02:02 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <errno.h>
#include <limits.h>

char	**creat_fresh_array(void)
{
	char	cwd[PATH_MAX + 1];
	char	**env_array;

	errno = 0;
	if (getcwd(cwd, PATH_MAX) == NULL)
		errno = 0;
	env_array = minishell_calloc(4, sizeof(char *));
	env_array[0] = ft_strjoin("PWD=", cwd);
	env_array[1] = minishell_strdup("SHLVL=0");
	env_array[2] = minishell_strdup("_=./minishell");
	if (errno > 0)
		exit_minishell(errno);
	return (env_array);
}
