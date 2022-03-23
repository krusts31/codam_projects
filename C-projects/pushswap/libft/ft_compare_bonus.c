/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_compare_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/23 16:03:48 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/07/05 14:28:42 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_compare(const char c, const char *z)
{
	while (*z != '\0')
	{
		if (c == *z)
			return (1);
		z++;
	}
	return (0);
}
