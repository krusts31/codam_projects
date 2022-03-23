/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intlen_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/23 16:03:06 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/11/14 14:46:10 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_intlen(int nr)
{
	int	ret;

	ret = 0;
	if (nr == 0)
		return (1);
	if (nr == -2147483648)
		return (0);
	if (nr < 0)
	{
		nr = -nr;
		ret++;
	}
	while (nr >= 1)
	{
		ret++;
		nr = nr / 10;
	}
	return (ret);
}
