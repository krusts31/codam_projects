/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   increment_shlvl.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts/dkrecisz <codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 15:57:01 by alkrusts/dk   #+#    #+#                 */
/*   Updated: 2021/11/01 15:31:10 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "environ.h"
#include "libft.h"

#include <stdlib.h>
#include <errno.h>

void	increment_shlvl(t_environ *env)
{
	t_environ	*new;
	char		*shlvl_str;
	char		*shlvl_str_new;
	char		*key_value;
	int			shlvl_nb;

	shlvl_str = environ_get(env, "SHLVL");
	if (shlvl_str != NULL)
	{
		shlvl_nb = ft_atoi(shlvl_str);
		shlvl_nb++;
		shlvl_str_new = ft_itoa(shlvl_nb);
		key_value = ft_strjoin("SHLVL=", shlvl_str_new);
		if (errno)
			exit_minishell(errno);
		free(shlvl_str_new);
	}
	else
		key_value = minishell_strdup("SHLVL=1");
	new = environ_new(key_value);
	free(key_value);
	environ_add_back(&env, new);
}
