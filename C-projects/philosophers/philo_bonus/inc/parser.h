/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 19:11:40 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/02/25 11:55:20 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "struct.h"

# include <stdbool.h>

const char	*skip_spaces(const char *spaces);
bool		is_int(const char *argv);
bool		is_spaces(int c);
int			ft_atoi(const char *nptr);
int			ft_is_digit(int c);

int			print_error_return_to_main(const char *error);
void		print_parced_data(t_programm_args args);

int			lexer(int argc, char **argv, t_programm_args *parced_data);
int			parser(int argc, char **argv, t_programm_args *parced_data);

#endif
