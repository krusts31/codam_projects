/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   malloc_wraper.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/09 15:41:32 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/09 15:49:30 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	*malloc_wrapper(const char *name, const int size, const int value)
{
	void	*ptr;

	ptr = malloc(size * value);
	if (!ptr)
	{
		printf("Error:\n%s failed!\n", name);
		exit(3);
	}
	return (ptr);
}
