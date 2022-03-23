/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 19:02:47 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/12/06 19:02:49 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdlib.h>
#include <stdbool.h>

int	main(int argc, char **argv)
{
	t_stack	*numbers;

	numbers = NULL;
	parcer(argc, argv, &numbers);
	if (is_sorted(numbers) == false)
		sort(&numbers);
	exit(0);
}
