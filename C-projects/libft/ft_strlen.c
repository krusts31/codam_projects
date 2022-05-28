/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                         :+:    :+:           */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/23 15:56:03 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/05/28 23:21:47 by alkrusts        ########   odam.nl       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	size_t	retu;

	retu = 0;
	while (*s != '\0')
	{
		retu++;
		s++;
	}
	return (retu);
}
