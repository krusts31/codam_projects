/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colors_bonus.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:20:46 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/04/30 12:20:46 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "varibles_bonus.h"

unsigned int	create_trgb(t_vec_i i)
{
	return (i.r << 16 | i.g << 8 | i.b);
}
