/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrev_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/23 15:55:18 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/05/23 15:55:23 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *ptr, int number)
{
	int	loop;

	loop = number;
	while (loop > 0)
	{
		ptr++;
		loop--;
	}
	return (ptr);
}
