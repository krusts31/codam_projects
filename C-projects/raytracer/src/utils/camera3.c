/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera3.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:19:35 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/04/30 12:19:35 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minRT.h"

#include <stdlib.h>
#include <stdio.h>

t_image_plane	*ft_init_image_plane(void)
{
	t_image_plane	*tmp;

	tmp = malloc(sizeof(t_image_var) * 1);
	if (tmp == NULL)
		exit(!printf("Error\ncamera3:24\n"));
	return (tmp);
}

void	*ft_free_image(t_image_plane **plane)
{
	free(*plane);
	return (NULL);
}
