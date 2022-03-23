/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/07 11:41:34 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/10/27 12:58:41 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list123
{
	struct s_list123	*next;
	char				*rem;
	char				*tmp;
	char				buf[BUFFER_SIZE + 1];
	size_t				index;
	size_t				prev;
	size_t				x;
	size_t				y;
	size_t				len;
	int					ret;
	int					fd;
}		t_list123;

int				get_next_line(int fd, char **line);
int				len_to_c(char *line, char hit, int ret, t_list123 **info);
int				ft_con(t_list123 *tmep, char **line, t_list123 **info);
t_list123		*init_list(int fd);
t_list123		*ft_lst_b(t_list123 **lst, t_list123 *new);
int				delete_node(t_list123 **info, char **line);
#endif
