/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_error_and_exit.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 19:05:31 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/12/06 19:05:32 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdlib.h>

void	print_error_and_exit(char *error_msg)
{
	const int	write_failed = -1;

	if (error_msg == NULL)
		exit(43);
	if (write_error_msg(error_msg) == write_failed)
		exit(42);
	exit(1);
}
