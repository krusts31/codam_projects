/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   isspace.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/28 13:07:04 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/02/02 12:57:31 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	is_spaces(int c)
{
	if ((c == ' ' || c == '\n' || c == '\t'
			|| c == '\v' || c == '\f' || c == '\r'))
		return (true);
	return (false);
}
