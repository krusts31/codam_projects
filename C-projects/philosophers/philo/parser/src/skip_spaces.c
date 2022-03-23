/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   skip_spaces.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/28 13:11:16 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/01/28 16:24:15 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

const char	*skip_spaces(const char *spaces)
{
	while (is_spaces(*spaces))
		spaces++;
	return (spaces);
}
