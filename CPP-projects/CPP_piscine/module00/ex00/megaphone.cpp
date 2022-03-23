/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   megaphone.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/28 17:00:02 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/08/05 17:25:28 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	ft_toupper(int c)
{
	if ((c >= 97) && (c <= 122))
		return (c - 32);
	return (c);
}

int		main(int argc, char	**argv)
{
	int	index;
	int	i;

	index = 1;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (argc > 1)
		{
			i = 0;
			while (argv[index][i])
			{
				std::cout << (char)ft_toupper(argv[index][i]);
				i++;
			}
			argc--;
			index++;
		}
		std::cout << std::endl;
	}
	return (0);
}
