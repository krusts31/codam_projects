/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/07 17:35:32 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/11/09 22:20:48 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int     main(int argc, char **argv)
{
	int             fd;
	int				fd2;
	int             fd3;
	int				fd4;
	char            *line;
	char            *line2;
	char            *line3;
	char            *line4;
	int             ret;
	int				ret1;
	int             ret2;
	int				ret3;
 
	(void)argc;
	line = NULL;
	line2 = NULL;
	line3 = NULL;
	line4 = NULL;
	fd = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	fd3 = open(argv[3], O_RDONLY);
	fd4 = open(argv[4], O_RDONLY);
	ret = 1;
	ret1 = 1;
	ret2 = 1;
	ret3 = 1;
	if (fd4 < 0)
		ret3 = 0;
	if (fd3 < 0)
		ret2 = 0;
	if (fd2 < 0)
		ret1 = 0;
	if (fd < 0)
		ret = 0;
	int	x;

	x = 3;
	while (ret > 0 || ret1 > 0 || ret3 > 0 || ret2 > 0)
	{ 
		if (ret >= 0 && fd > 0)
		{
			ret = get_next_line(fd, &line);
			if (ret == -1)
				return (0);
			printf("[%d], file 1: %s\n", ret, line);
			free(line);
			line = NULL;
			x--;
		}
		if (ret1 >= 0 && fd2 > 0)
		{
			ret1 = get_next_line(fd2, &line2);
			if (ret1 == -1)
				return (0);
			printf("[%d], file 2: %s\n", ret1, line2);
			free(line2);
			line2 = NULL;
		}
		if (ret2 >= 0 && fd3 > 0)
		{
			ret2 = get_next_line(fd3, &line3);
			if (ret2 == -1)
				return (0);
			printf("[%d], file 3: %s\n", ret2, line3);
			free(line3);
			line3 = NULL;
		}
		if (ret3 >= 0 && fd4 > 0)
		{
			ret3 = get_next_line(fd4, &line4);
			if (ret3 == -1)
				return (0);
			printf("[%d], file 4: %s\n", ret3, line4);
			free(line4);
			line4 = NULL;
		}
	}
	close(fd);
	close(fd2);
	close(fd3);
	close(fd4);
	return (0);
}
