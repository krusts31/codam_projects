/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/23 15:59:56 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/07/11 17:11:00 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int		resu;
	const unsigned char	*ss1;
	const unsigned char	*ss2;

	ss1 = s1;
	ss2 = s2;
	while (n > 0)
	{
		if (*ss1 != *ss2)
		{
			resu = *ss1 - *ss2;
			return (resu);
		}
		ss1++;
		ss2++;
		n--;
	}
	return (0);
}
