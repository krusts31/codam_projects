/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   check_functions.c                                   :+:    :+:           */
/*                                                      +:+                   */
/*   By: alkrusts <alkrusts@student.codam.nl >         +#+                    */
/*                                                    +#+                     */
/*   Created: 2022/01/08 16:56:39 by alkrusts       #+#    #+#                */
/*   Updated: 2022/01/28 18:49:03 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <limits.h>

bool	is_int(const char *argv)
{
	int			negative;
	long int	res;

	negative = 1;
	res = 0;
	argv = skip_spaces(argv);
	if (*argv == '-')
		negative = -1;
	if (*argv == '-' || *argv == '+')
		argv++;
	while (*argv)
	{
		if (!ft_is_digit(*argv))
			return (false);
		res = res * 10 + (*argv - 48);
		argv++;
	}
	if (res > INT_MAX || res < INT_MIN)
		return (false);
	return (true);
}
