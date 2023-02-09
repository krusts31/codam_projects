/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_bmp_bonus.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:20:47 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/04/30 12:20:47 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"
#include "../../libs/libft/libft.h"

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

static void	write_file_header(t_task *task, int fd, int pad_amount)
{
	unsigned char	file_header[BMP_FILE_HEADER_SIZE];
	size_t			file_size;

	ft_bzero(file_header, BMP_FILE_HEADER_SIZE);
	file_size = BMP_FILE_HEADER_SIZE + BMP_INFO_HEADER_SIZE;
	file_size += task->X_res * task->Y_res + pad_amount * task->Y_res;
	file_header[0] = 'B';
	file_header[1] = 'M';
	file_header[2] = file_size;
	file_header[3] = file_size >> 8;
	file_header[4] = file_size >> 16;
	file_header[5] = file_size >> 24;
	file_header[10] = sizeof(file_header) + BMP_INFO_HEADER_SIZE;
	if (write(fd, file_header, sizeof(file_header)) == -1)
		exit(!printf("Error\nsave_bmp.c:20\n"));
}

static void	write_info_header(t_data *data, int fd)
{
	unsigned char	information_header[BMP_INFO_HEADER_SIZE];

	ft_bzero(information_header, BMP_INFO_HEADER_SIZE);
	information_header[0] = BMP_INFO_HEADER_SIZE;
	information_header[4] = data->task.X_res;
	information_header[5] = data->task.X_res >> 8;
	information_header[6] = data->task.X_res >> 16;
	information_header[7] = data->task.X_res >> 24;
	information_header[8] = data->task.Y_res;
	information_header[9] = data->task.Y_res >> 8;
	information_header[10] = data->task.Y_res >> 16;
	information_header[11] = data->task.Y_res >> 24;
	information_header[12] = 1;
	information_header[14] = 24;
	if (write(fd, information_header, sizeof(information_header)) == -1)
		exit(!printf("Error\nsave_bmp.c:20\n"));
}

static void	write_body(t_data *data, int fd, int pad_amount, char *padding)
{
	unsigned char	color[3];
	char			*addr;
	int				y;
	int				x;

	y = (int)data->task.Y_res - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < (int)data->task.X_res)
		{
			addr = data->addr;
			addr += (y * data->line_length + x * (data->bits_per_pixel / 8));
			color[0] = (*((unsigned int *)addr));
			color[1] = (*((unsigned int *)addr)) >> 8;
			color[2] = (*((unsigned int *)addr)) >> 16;
			if (write(fd, color, 3) == -1)
				exit(!printf("Error\nsvae_bmp.c:69"));
			x++;
		}
		if (write(fd, padding, pad_amount) == -1)
			exit(!printf("Error\nsave_bmp.c:72"));
		y--;
	}
}

void	save_bmp(t_data *data)
{
	int		fd;
	int		pad_amount;
	char	padding[3];

	fd = open("screen_shots/render.bmp",
			O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (fd == -1)
		exit(!printf("Error: %s\n", strerror(errno)));
	pad_amount = ((4 - (data->task.X_res * 3) % 4) % 4);
	write_file_header(&data->task, fd, pad_amount);
	write_info_header(data, fd);
	write_body(data, fd, pad_amount, padding);
	close(fd);
	exit(0);
}
