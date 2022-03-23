/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   subtract_time.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/19 18:13:44 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/01 21:41:58 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>

double	subtract_time_in_ms(struct timeval x, struct timeval y)
{
	return (((x.tv_sec - y.tv_sec) * 1000.0
			+ (x.tv_usec - y.tv_usec) / 1000.0));
}
