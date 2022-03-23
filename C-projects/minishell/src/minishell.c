/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts/dkrecisz <codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 15:53:37 by alkrusts/dk   #+#    #+#                 */
/*   Updated: 2021/10/30 10:51:16 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "executor.h"
#include "minishell.h"
#include "parser.h"
#include "lexer.h"
#include "libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include <readline/readline.h>
#include <readline/history.h>

static int	check_option_flag(char *arg)
{
	size_t	i;

	if (!arg[0] || arg[0] != '-' || !arg[1])
		return (0);
	if (arg[1] != 'c')
		exit_minishell(2);
	i = 1;
	while (arg[i])
	{
		if (arg[i] != 'c')
			exit_minishell(2);
		i++;
	}
	return (1);
}

static int	read_flags(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc && check_option_flag(argv[i]))
		i++;
	if (i == argc)
	{
		printf("minishell: -c: option requires an argument\n");
		exit_minishell(2);
	}
	return (i);
}

void	minishell_non_interactive(t_data *data, int argc, char *argv[])
{
	int					flags;
	int					ret;

	ret = 0;
	data->interactive = FALSE;
	if (argc > 1)
	{
		flags = read_flags(argc, argv);
		data->line = ft_strdup(argv[flags]);
	}
	else
		ret = get_next_line(0, &data->line);
	if (errno || data->line == NULL || ret == -1)
		exit_minishell(errno);
	data->line_len = ft_strlen(data->line);
	if (lexer(&data, data->line) == EXIT_FAILURE)
		printf("Syntax error!\n");
	else
	{
		parser(data);
		execute(data);
		delete_ast(data->astree);
		free_token_list(data->token);
		data->token_mask = 0;
	}
}

static void	minishell_con(t_data *data, t_local var)
{
	if (g_sig == 1)
		data->exit_status = 1;
	if (data->line == NULL)
		return ;
	errno = 0;
	if (ft_strlen(data->line) != 0)
		add_history(data->line);
	data->line_len = ft_strlen(data->line);
	if (lexer(&data, data->line) == EXIT_FAILURE)
		printf("Syntax error!\n");
	else
	{
		parser(data);
		execute(data);
		delete_ast(data->astree);
		data->astree = NULL;
		free_token_list(data->token);
		free(data->fd);
		data->fd = (t_file_io *)minishell_calloc(1, sizeof(t_file_io));
		data->token_mask = 0;
	}
	if (var.flag == 1)
		exit(1);
}

void	minishell_interactive(t_data *data)
{
	t_local	var;

	var.flag = 0;
	while (1)
	{
		g_sig = 0;
		if (isatty(STDIN_FILENO))
		{
			data->line = readline("minishell$ ");
			if (data->line == NULL)
				exit(data->exit_status);
		}
		else
		{
			var.flag = 1;
			errno = 0;
			var.ret = get_next_line(0, &data->line);
			if (errno || data->line == NULL || var.ret == -1)
				exit_minishell(errno);
		}
		minishell_con(data, var);
		free(data->line);
		data->line = NULL;
	}
}
