/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/05 15:56:36 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/01/08 03:57:09 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_new_line(char **line, t_list123 *temp, t_list123 **info)
{
	temp->len = len_to_c(temp->rem, '\0', 0, &temp) + temp->index;
	temp->prev = 1;
	temp->x = 0;
	temp->y = 0;
	temp->tmp = malloc((temp->len * sizeof(char)) + 1);
	if (temp->tmp == NULL)
		return (len_to_c(NULL, 'x', -1, info));
	temp->tmp[temp->len] = '\0';
	if (temp->rem != NULL)
	{
		while (temp->rem[temp->x] != '\0')
		{
			temp->tmp[temp->x] = temp->rem[temp->x];
			temp->x++;
		}
		free(temp->rem);
		temp->rem = NULL;
	}
	temp->index++;
	return (ft_con(temp, line, info));
}

static int	ft_null_byte(t_list123 *info)
{
	info->y = info->index + len_to_c(info->rem, '\0', 0, &info);
	info->tmp = malloc(sizeof(char) * info->y + 1);
	if (info->tmp == NULL)
		return (0);
	info->tmp[info->y] = '\0';
	while (info->y != 0 && info->x != 0)
	{
		info->y--;
		info->x--;
		info->tmp[info->y] = info->buf[info->x];
	}
	if (info->rem != NULL)
	{
		info->x = len_to_c(info->rem, '\0', 0, &info);
		while (info->y != 0 && info->x != 0)
		{
			info->y--;
			info->x--;
			info->tmp[info->y] = info->rem[info->x];
		}
		free(info->rem);
	}
	info->rem = info->tmp;
	info->prev = 0;
	return (1);
}

static int	read_and_copy(t_list123 *info)
{
	info->x = 0;
	if (info->prev == 0)
	{
		info->ret = read(info->fd, info->buf, BUFFER_SIZE);
		info->buf[info->ret] = '\0';
	}
	else
	{
		while (info->rem[info->x] != '\0')
		{
			info->buf[info->x] = info->rem[info->x];
			info->x++;
		}
		info->buf[info->x] = '\0';
		free(info->rem);
		info->rem = NULL;
		info->prev = 1;
	}
	info->index = 0;
	return (1);
}

static int	gnl_con(t_list123 **info, t_list123 **tmp, char **line)
{
	while ((*tmp)->ret)
	{
		if (!read_and_copy(*tmp))
			return (len_to_c(NULL, 'x', -1, info));
		if ((*tmp)->ret == 0)
		{
			if ((*tmp)->rem == NULL)
				break ;
			*line = (*tmp)->rem;
			return (delete_node(info, NULL));
		}
		while ((*tmp)->buf[(*tmp)->index])
		{
			if ((*tmp)->buf[(*tmp)->index] == '\n')
				return (ft_new_line(line, *tmp, info));
			(*tmp)->index++;
		}
		(*tmp)->x = len_to_c((*tmp)->buf, '\0', 0, tmp);
		if (!ft_null_byte(*tmp))
			return (len_to_c(NULL, 'x', -1, info));
	}
	*line = malloc(1 * sizeof(char));
	if (*line == NULL)
		return (len_to_c(NULL, 'x', -1, info));
	return (delete_node(info, line));
}

int	get_next_line(int fd, char **line)
{
	static t_list123	*info = NULL;
	t_list123			*tmp;

	if (line == NULL || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (len_to_c(NULL, 'x', -1, &info));
	if (info == NULL)
	{
		info = init_list(fd);
		if (info == NULL)
			return (len_to_c(NULL, 'x', -1, &info));
	}
	tmp = info;
	while (tmp)
	{
		if (tmp->fd == fd)
			break ;
		tmp = tmp->next;
	}
	if (tmp == NULL)
	{
		tmp = ft_lst_b(&info, init_list(fd));
		if (tmp == NULL)
			return (len_to_c(NULL, 'x', -1, &info));
	}
	return (gnl_con(&info, &tmp, line));
}
