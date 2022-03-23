/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_utils_1.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/25 13:48:06 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/12/25 13:48:18 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_con_ptr(t_print *p, char *tmp)
{
	free(p->a);
	p->a = tmp;
}

int		ft_free_in(t_list1 *info, va_list va, t_print *p)
{
	va_end(va);
	if (info != NULL)
		free(info->cs);
	free(info);
	if (p != NULL)
	{
		free(p->p);
		free(p->a);
	}
	free(p);
	return (-1);
}

void	ft_get_pad_char(t_print *p)
{
	if (p->pad_amount < 0)
		p->pad_amount = -p->pad_amount;
	p->s = 1;
	if (p->s < (size_t)p->pad_amount)
		p->s = p->pad_amount;
	p->p = ft_calloc(p->s + 1, sizeof(char));
	if (p->p == NULL)
		p->s = 0;
}

void	ft_init_info(t_list1* info)
{
	info->cs = NULL;
	info->length_of_cs_string = 0;
	info->total_chars_printed = 0;
}

int	ft_edge(t_list1 *info, t_print *p)
{
	if (p->pad_amount != 0)
		ft_memset(p->p, ' ', p->pad_amount - 1);
	if (p->zero_present == 1 && p->minuss_present != 1)
	{
		if (p->pad_amount != 0)
			ft_memset(p->p, '0', p->pad_amount - 1);
	}
	if (p->minuss_present == 1)
	{
		write(1, "\0", 1);
		ft_putstr(p->p);
	}
	else
	{
		ft_putstr(p->p);
		write(1, "\0", 1);
	}
	info->total_chars_printed += ft_strlen(p->p) + 1;
	return (1);
}
