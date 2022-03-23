/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/23 15:58:11 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/07/11 17:36:42 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nr;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nr = -n;
	}
	else
		nr = (unsigned int)n;
	if (nr >= 10)
		ft_putnbr_fd(nr / 10, fd);
	ft_putchar_fd((char)(nr % 10 + 48), fd);
}
