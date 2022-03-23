/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/23 15:55:54 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/07/11 17:35:11 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ss1;
	unsigned char	*ss2;
	int				ret;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*ss1 != *ss2)
		{
			ret = *ss1 - *ss2;
			return (ret);
		}
		if (*ss1 == '\0' || *ss2 == '\0')
			return (0);
		ss1++;
		ss2++;
		n--;
	}
	return (0);
}
