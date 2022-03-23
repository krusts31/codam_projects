/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_unset.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts/dkrecisz <codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 15:54:57 by alkrusts/dk   #+#    #+#                 */
/*   Updated: 2021/10/18 05:16:18 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "environ.h"

static int	check_variable_name(char *name)
{
	int	letter;

	letter = 0;
	if (name == NULL || name[0] == 0 || name[0] == '=')
		return (1);
	while (*name && *name != '=')
	{
		if (ft_isalpha(*name))
			letter = TRUE;
		else if (ft_isalnum(*name) == 0 && *name != '_')
			return (1);
		else if (ft_isdigit(*name) && letter == 0)
			return (1);
		name++;
	}
	return (0);
}

static int	unset_error(char *arg)
{
	minishell_putstr_fd("minishell: unset: `", 2);
	minishell_putstr_fd(arg, 2);
	minishell_putendl_fd("\': not a valid identifier", 2);
	return (1);
}

int	builtin_unset(t_data *data, t_command *cmd)
{
	size_t	i;
	int		error;

	if (cmd->argc == 1)
		return (0);
	else if (cmd->argc > 1 && cmd->argv[1][0] == '-')
	{
		minishell_putendl_fd("minishell: unset: options are not supported", 2);
		return (2);
	}
	i = 1;
	error = 0;
	while (cmd->argv[i])
	{
		if (check_variable_name(cmd->argv[i]))
			error = unset_error(cmd->argv[i]);
		else
			environ_unset(&data->env, cmd->argv[i]);
		i++;
	}
	return (error);
}
