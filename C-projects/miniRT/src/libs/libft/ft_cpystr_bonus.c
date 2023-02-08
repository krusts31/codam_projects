/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_cpystr_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/23 16:03:41 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/05/23 16:03:43 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_cpystr(char *dst, const char *src)
{
	while (*src != '\0')
	{
		*dst = *src;
		dst++;
		src++;
	}
	return (dst);
}
