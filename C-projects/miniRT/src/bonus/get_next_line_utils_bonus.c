/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/05 15:57:11 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/01/09 21:58:32 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	len_to_c(char *line, char hit, int ret, t_list123 **info)
{
	int			x;
	t_list123	*now;

	if (hit != 'x')
	{
		x = 0;
		if (line == NULL)
			return (0);
		while (line[x] != hit && line[x] != '\0')
			x++;
		return (x);
	}
	while (*info)
	{
		now = (*info)->next;
		free((*info)->tmp);
		free((*info)->rem);
		free(*info);
		(*info) = now;
	}
	free(*info);
	return (ret);
}

int	ft_con(t_list123 *tmep, char **line, t_list123 **info)
{
	while (tmep->buf[tmep->y] != '\n' && tmep->buf[tmep->y] != '\0')
	{
		tmep->tmp[tmep->x] = tmep->buf[tmep->y];
		tmep->x++;
		tmep->y++;
	}
	if (tmep->buf[tmep->y] == '\n')
	{
		tmep->len = len_to_c(tmep->buf + tmep->y + 1, '\0', 0, &tmep);
		tmep->rem = malloc(sizeof(char) * tmep->len + 1);
		if (tmep->rem == NULL)
			return (len_to_c(NULL, 'x', -1, info));
		tmep->x = 0;
		tmep->y++;
		while (tmep->buf[tmep->y] != '\0')
		{
			tmep->rem[tmep->x] = tmep->buf[tmep->y];
			tmep->y++;
			tmep->x++;
		}
		tmep->rem[tmep->x] = '\0';
	}
	*line = tmep->tmp;
	tmep->tmp = NULL;
	return (1);
}

t_list123	*init_list(int fd)
{
	t_list123	*info;

	info = malloc(sizeof(t_list123) * 1);
	if (info == NULL)
		return (NULL);
	info->next = NULL;
	info->rem = NULL;
	info->tmp = NULL;
	info->index = 0;
	info->prev = 0;
	info->ret = 1;
	info->fd = fd;
	return (info);
}

t_list123	*ft_lst_b(t_list123 **lst, t_list123 *new)
{
	t_list123	*tmp;

	tmp = *lst;
	if (new == NULL)
		return (NULL);
	if (*lst == NULL)
	{
		*lst = new;
		return (*lst);
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (tmp->next);
}

int	delete_node(t_list123 **info, char **line)
{
	t_list123	*tmp;
	t_list123	*prev;

	if (line != NULL)
		*line[0] = '\0';
	tmp = *info;
	if (tmp != NULL && tmp->ret == 0)
	{
		*info = (*info)->next;
		free(tmp);
		return (0);
	}
	while (tmp != NULL && tmp->ret != 0)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return (0);
	prev->next = tmp->next;
	free(tmp);
	return (0);
}
