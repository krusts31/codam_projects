/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils3_bonus.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:20:48 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/04/30 12:20:48 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parcer_bonus.h"

#include <unistd.h>

int	argc_error(char *str)
{
	write(1, str, ft_strlen(str));
	return (-1);
}

size_t	ft_size_t_len(size_t nr)
{
	int	ret;

	ret = 0;
	if (nr == 0)
		return (1);
	if (nr < 0)
	{
		nr = -nr;
		ret++;
	}
	while (nr >= 1)
	{
		ret++;
		nr = nr / 10;
	}
	return (ret);
}

void	free_sq(t_task *task)
{
	t_sq	*tmp;

	if (task != NULL)
	{
		while (task->sq)
		{
			tmp = task->sq->next;
			free(task->sq);
			task->sq = tmp;
		}
	}
}
