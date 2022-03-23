/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   signals.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts/dkrecisz <codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 15:56:55 by alkrusts/dk   #+#    #+#                 */
/*   Updated: 2021/11/02 14:09:10 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <signal.h>

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

void	sig_quit_child(int ig)
{
	(void)ig;
	g_sig = 131;
}

void	sig_int_child(int ig)
{
	(void)ig;
	g_sig = 130;
}

void	sig_int_parent(int ig)
{
	(void)ig;
	if (signal(SIGINT, sig_int_parent) == SIG_ERR)
		exit_minishell_custom("ERROR SIGINT ");
	if (signal(SIGQUIT, sig_quit_parent) == SIG_ERR)
		exit_minishell_custom("ERROR SIGQUIT ");
	rl_replace_line("", 0);
	ft_putchar('\n');
	rl_on_new_line();
	rl_redisplay();
	g_sig = 1;
}

void	sig_quit_parent(int ig)
{
	(void)ig;
	if (signal(SIGINT, sig_int_parent) == SIG_ERR)
		exit_minishell_custom("ERROR SIGINT ");
	if (signal(SIGQUIT, sig_quit_parent) == SIG_ERR)
		exit_minishell_custom("ERROR SIGQUIT ");
	rl_on_new_line();
	rl_redisplay();
}

void	sig_herdocs(int ig)
{
	if (ig == SIGQUIT)
	{
		if (signal(SIGQUIT, sig_herdocs) == SIG_ERR)
			exit_minishell_custom("ERROR SIGINT ");
		if (signal(SIGINT, sig_herdocs) == SIG_ERR)
			exit_minishell_custom("ERROR SIGQUIT ");
		rl_on_new_line();
		rl_redisplay();
		return ;
	}
	if (ig == SIGINT)
	{
		if (signal(SIGINT, sig_int_parent) == SIG_ERR)
			exit_minishell_custom("ERROR SIGINT ");
		if (signal(SIGQUIT, sig_quit_parent) == SIG_ERR)
			exit_minishell_custom("ERROR SIGQUIT ");
		g_sig = 1;
		close(0);
		ft_putchar('\n');
	}
}
