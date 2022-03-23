/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_do_char.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 12:58:29 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/12/06 20:33:34 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_res(t_list1 *info, t_print *p)
{
	if (ft_strlen(p->p))
	{
		ft_putstr(p->p);
		info->total_chars_printed += ft_strlen(p->p);
	}
	else
	{
		ft_putstr(p->a);
		info->total_chars_printed += ft_strlen(p->a);
	}
	return (1);
}

static int	ft_arg_memset(t_print *p)
{
	char	*tmp;

	if (p->pad_amount != 0)
		ft_memset(p->p, ' ', p->pad_amount - ft_strlen(p->a));
	if (p->zero_present == 1 && p->minuss_present != 1)
		ft_memset(p->p, '0', p->pad_amount - ft_strlen(p->a));
	if (p->minuss_present == 1)
		tmp = ft_strjoin(p->a, p->p);
	else
		tmp = ft_strjoin(p->p, p->a);
	if (tmp == NULL)
		return (0);
	free(p->p);
	p->p = tmp;
	return (1);
}

static int	ft_arg(t_print *p, int value)
{
	if (value == 0)
		p->a = ft_calloc(1, sizeof(char));
	else
	{
		p->a = ft_calloc(2, sizeof(char));
		p->a[0] = (char)value;
	}
	if (p->a == NULL)
		return (0);
	if (p->pad_amount > (long)ft_strlen(p->a))
		ft_memset(p->p, ' ', p->pad_amount - ft_strlen(p->a));
	return (ft_arg_memset(p));
}

static int	ft_continue_char(t_list1 *info, va_list va, t_print *p)
{
	int		value;

	if (p->pad_amount >= INT_MAX - 1 || p->pad_amount < INT_MIN + 2)
		return (0);
	value = va_arg(va, int);
	ft_get_pad_char(p);
	if (value == 0)
		return (ft_edge(info, p));
	if (p->s == 0)
		return (0);
	if (!ft_arg(p, value))
		return (0);
	return (ft_print_res(info, p));
}

int			ft_do_char(t_list1 *info, va_list va, t_print *p)
{
	size_t	index;

	ft_init_print(p);
	index = 0;
	while (info->cs[index] != '\0')
	{
		if (info->cs[index] == '-')
			p->minuss_present = 1;
		if (info->cs[index] == '0')
			p->zero_present = 1;
		if (info->cs[index] == '*')
			ft_cs_st(p, va);
		if (info->cs[index] > '0' && info->cs[index] <= '9')
		{
			p->pad_amount = ft_atoi(info->cs + index);
			break ;
		}
		index++;
	}
	if (!ft_continue_char(info, va, p))
		return (0);
	return (1);
}
