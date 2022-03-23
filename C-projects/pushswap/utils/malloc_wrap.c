/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   malloc_wrap.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 19:05:26 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/12/06 19:05:27 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

#include <stdlib.h>

void	*malloc_wrap(size_t size, size_t amount)
{
	void	*malloced_mem;

	malloced_mem = ft_calloc(size, amount);
	if (malloced_mem == NULL)
		print_error_and_exit("Error, malloc failed!\n");
	return (malloced_mem);
}
