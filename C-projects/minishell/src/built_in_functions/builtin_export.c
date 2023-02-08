/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_export.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts/dkrecisz <codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 15:54:51 by alkrusts/dk   #+#    #+#                 */
/*   Updated: 2021/11/02 14:29:45 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "environ.h"
#include <stdlib.h>

static int	check_variable_name(char *name)
{
	int		letter;
	char	*s;

	letter = 0;
	if (name == NULL || name[0] == 0 || name[0] == '=')
		return (EXIT_FAILURE);
	s = ft_strchr(name, '+');
	if (s && *(s + 1) != '=')
		return (EXIT_FAILURE);
	while (*name && *name != '=')
	{
		if (ft_isalpha(*name))
			letter = TRUE;
		else if (ft_isalnum(*name) == 0 && *name != '_' && *name != '+')
			return (EXIT_FAILURE);
		else if (ft_isdigit(*name) && letter == 0)
			return (EXIT_FAILURE);
		name++;
	}
	return (EXIT_SUCCESS);
}

static int	print_exported_variables(t_command *cmd, t_environ	*env)
{
	while (env)
	{
		minishell_putstr_fd("declare -x ", cmd->fd->write);
		minishell_putstr_fd(env->key, cmd->fd->write);
		minishell_putstr_fd("=\"", cmd->fd->write);
		minishell_putstr_fd(env->value, cmd->fd->write);
		minishell_putendl_fd("\"", cmd->fd->write);
		env = env->next;
	}
	return (0);
}

static int	export_error(char *arg)
{
	minishell_putstr_fd("minishell: export: `", 2);
	minishell_putstr_fd(arg, 2);
	minishell_putendl_fd("\': not a valid identifier", 2);
	return (1);
}

static void	add_new_variable(t_environ **env, t_environ *new)
{
	if (environ_get(*env, new->key))
	{
		if (ft_strchr(new->key_value, '=') == 0)
		{
			free(new->key);
			free(new->value);
			free(new->key_value);
			free(new);
			return ;
		}
	}
	environ_modify_prep(env, new);
	free(new->key);
	free(new->value);
	free(new->key_value);
	free(new);
}

int	builtin_export(t_command *cmd, t_environ **env)
{
	t_environ	*my_var;
	size_t		i;
	int			exit_status;

	if (cmd->argc == 1)
		return (print_exported_variables(cmd, *env));
	i = 1;
	exit_status = 0;
	while (cmd->argv[i])
	{
		if (check_variable_name(cmd->argv[i]))
			return (export_error(cmd->argv[i]));
		i++;
	}
	i = 1;
	while (cmd->argv[i])
	{
		my_var = environ_new(cmd->argv[i]);
		if (environ_get(*env, my_var->key))
			add_new_variable(env, my_var);
		else
			environ_add_back(env, my_var);
		i++;
	}
	return (exit_status);
}
