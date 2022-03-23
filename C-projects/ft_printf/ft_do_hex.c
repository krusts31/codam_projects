/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_do_hex.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 14:08:40 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/12/07 17:33:08 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_hex_zero(t_print *p, t_list1 *info)
{
	if (p->pad_amount > 0)
		ft_memset(p->p, ' ', p->pad_amount);
	ft_putstr(p->p);
	info->total_chars_printed += ft_strlen(p->p);
	return (1);
}

int			ft_no_minuss(t_print *p, t_list1 *f)
{
	long	len;

	len = ft_strlen(p->a);
	if (p->dot_present == 1)
		return (ft_no_minuss_dot(p, f));
	if (p->dot_present == 0)
		return (ft_no_minuss_no_dot(p, f));
	if (len > p->pad_amount)
	{
		ft_putstr(p->a);
		f->total_chars_printed += len;
		return (1);
	}
	if (p->zero_present == 1 && p->pad_amount > len)
	{
		ft_memset(p->p, '0', p->s - len);
		ft_memmove(p->p + (p->s - len), p->a, len);
		ft_putstr(p->p);
		f->total_chars_printed += len;
	}
	return (1);
}

int			ft_minuss(t_print *p, t_list1 *f)
{
	long	len;

	len = ft_strlen(p->a);
	if (p->d != 0)
		return (ft_minuss_dot(p, f, len));
	if (p->d == 0)
		return (ft_minuss_no_dot(p, f));
	if ((long)len > p->pad_amount)
	{
		ft_putstr(p->a);
		f->total_chars_printed += len;
		return (1);
	}
	if (p->zero_present == 1 && p->pad_amount > (long)len)
	{
		ft_memset(p->p + (p->s - len), '0', p->s - len);
		ft_memmove(p->p, p->a, len);
		ft_putstr(p->p);
		f->total_chars_printed += ft_strlen(p->p);
		return (1);
	}
	return (0);
}

static int	ft_continue_hex(t_list1 *info, va_list va, t_print *p)
{
	long	num;

	if (p->pad_amount >= INT_MAX - 1 || p->pad_amount < INT_MIN + 2)
		return (0);
	if (p->d >= INT_MAX - 1 || p->d < INT_MIN + 2)
		return (0);
	num = va_arg(va, int);
	p->a = ft_convert_str_hex(num);
	if (p->a == NULL)
		return (0);
	ft_get_pad(p);
	if (p->s == 0)
		return (0);
	if (p->a[0] == '0' && p->d == 0 && p->dot_present)
		return (ft_hex_zero(p, info));
	if (p->minuss_present == 0)
		return (ft_no_minuss(p, info));
	else
		return (ft_minuss(p, info));
	return (0);
}

int			ft_do_hex(t_list1 *info, va_list va, t_print *p)
{
	size_t	index;

	index = 0;
	ft_init_print(p);
	while (info->cs[index] != '\0')
	{
		if (info->cs[index] == '-')
			p->minuss_present = 1;
		if (info->cs[index] == '0')
			p->zero_present = 1;
		if (info->cs[index] == '.')
			index = ft_cs_dot(info, p, index, va);
		if (info->cs[index] == '*')
			ft_cs_st(p, va);
		if (info->cs[index] > '0' && info->cs[index] <= '9')
		{
			p->pad_amount = ft_atoi(info->cs + index);
			index += (ft_intlen(p->pad_amount) - 1);
		}
		index++;
	}
	if (!ft_continue_hex(info, va, p))
		return (0);
	return (1);
}
