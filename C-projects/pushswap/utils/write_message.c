/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_message.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 19:05:39 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/12/06 19:05:40 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <unistd.h>

int	write_msg(char *msg)
{
	int	ret;

	ret = write(1, msg, ft_strlen(msg));
	return (ret);
}

int	write_error_msg(char *msg)
{
	int	ret;

	ret = write(2, msg, ft_strlen(msg));
	return (ret);
}
