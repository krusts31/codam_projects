/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   print_error_exit.c                                  :+:    :+:           */
/*                                                      +:+                   */
/*   By: alkrusts <alkrusts@student.codam.nl >         +#+                    */
/*                                                    +#+                     */
/*   Created: 2022/01/08 15:17:11 by alkrusts       #+#    #+#                */
/*   Updated: 2022/01/24 20:19:35 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	print_error_return_to_main(const char *error)
{
	printf("%s\n", error);
	return (1);
}
