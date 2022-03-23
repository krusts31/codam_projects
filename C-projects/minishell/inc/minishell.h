/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts/dkrecisz <codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 15:54:30 by alkrusts/dk   #+#    #+#                 */
/*   Updated: 2021/11/02 15:19:18 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "structs.h"

extern int	g_sig;

/**
 *	Boolean defines - Because we are too cool for stdbool.
**/

# define FALSE	0
# define TRUE	1

/**
 * Maximal amount of tokens to protect stack overvlows.
**/
# define TOKEN_MAX 254

/*
**	COLORS THAT YOU SEE ON THE PROOMPT
*/

# define GREEN "\033[32;1;4m"
# define BLUE "\033[34;1;4m"
# define WHITE "\033[97;0;4m"
# define RESET "\033[0m"

t_list	*minishell_lstnew(void *content);
void	minishell_non_interactive(t_data *data, int argc, char *argv[]);
void	minishell_interactive(t_data *data);
void	exit_minishell(int error_id);
void	exit_minishell_custom(char *str);
t_data	*init_data(char **envp, char **argv);
void	free_data(t_data *data);
void	increment_shlvl(t_environ *env);
void	quote_removal(t_data **data);

/**
 * Libft and glibc wrapper functions 
 * */

void	minishell_putstr(const char *str);
void	*minishell_calloc(size_t nmemb, size_t size);
ssize_t	minishell_write(int fd, const void *buf, size_t count);
ssize_t	minishell_putchar_fd(const char c, int fd);
ssize_t	minishell_putstr_fd(const char *s, int fd);
ssize_t	minishell_putendl_fd(const char *s, int fd);
char	*minishell_strdup(const char *s);

/*
**	SIGNAL HOOK FUNCTIOMS
*/

void	sig_quit_parent(int ig);
void	sig_int_parent(int ig);
void	sig_int_child(int ig);
void	sig_quit_child(int ig);
void	sig_herdocs(int ig);

#endif
