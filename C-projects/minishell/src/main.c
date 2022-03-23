/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts/dkrecisz <codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 15:57:07 by alkrusts/dk   #+#    #+#                 */
/*   Updated: 2021/11/01 16:23:36 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <errno.h>
#include <signal.h>

int	g_sig;

static void	init_terminal(t_data *data)
{
	if (isatty(STDIN_FILENO))
		tcgetattr(0, &data->old_term);
	data->new_term = data->old_term;
	data->new_term.c_lflag &= ~(ECHOCTL);
	if (isatty(STDIN_FILENO))
		tcsetattr(0, TCSANOW, &data->new_term);
}

int	main(int argc, char *argv[], char **envp)
{
	t_data			*data;
	int				exit_status;

	g_sig = 0;
	if (signal(SIGINT, sig_int_parent) == SIG_ERR)
		exit_minishell_custom("Error SIGINT ");
	if (signal(SIGQUIT, sig_quit_parent) == SIG_ERR)
		exit_minishell_custom("Error SIGQUIT ");
	data = init_data(envp, argv);
	init_terminal(data);
	if (argc == 1)
	{
		data->interactive = TRUE;
		minishell_interactive(data);
	}
	else
	{
		errno = 0;
		minishell_non_interactive(data, argc, argv);
	}
	exit_status = data->exit_status;
	free_data(data);
	return (exit_status);
}
