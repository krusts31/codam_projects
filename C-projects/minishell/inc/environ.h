/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   environ.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts/dkrecisz <codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 15:54:22 by alkrusts/dk   #+#    #+#                 */
/*   Updated: 2021/11/01 16:26:40 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRON_H
# define ENVIRON_H

# include "minishell.h"

t_environ	*environ_deep_copy(char **env, char **argv);
char		*environ_get(t_environ *head, char *key);
void		environ_set(t_environ *head, char *key, char *value);
void		environ_add_back(t_environ **env, t_environ *new);
t_environ	*environ_new(const char *key_value);
void		environ_unset(t_environ **head, char *key);
void		environ_free(t_environ *head);
char		**environ_get_array(t_environ *env);
int			environ_compare(char *s1, char *s2);
char		*environ_get_keyvalue(char *key, char *value);
void		environ_modify(t_environ **head, t_environ *new);
t_environ	*environ_new_empty(const char *key_value);
t_environ	*environ_addition(const char *key_value);
void		environ_modify_prep(t_environ **head, t_environ *prep);
int			environ_add_to_env(t_environ **varible, char *key, char *value);

#endif
