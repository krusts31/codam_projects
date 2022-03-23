/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnlen_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/10 22:42:47 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/07/11 15:42:19 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strnlen(const char *s, size_t maxlen)
{
	const char	*s_orig = s;

	while (*s && maxlen > 0)
	{
		s++;
		maxlen--;
	}
	return ((size_t)s - (size_t)s_orig);
}
