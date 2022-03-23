/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_int_utils_1.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/06 08:43:32 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/12/25 13:51:14 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_no_minuss_int(t_print *p, t_list1 *f)
{
	long	len;

	len = ft_strlen(p->a);
	if (p->dot_present == 1)
		return (ft_no_minuss_dot_int(p, f));
	if (p->dot_present == 0)
		return (ft_no_minuss_no_dot_int(p, f));
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

int	ft_minuss_int(t_print *p, t_list1 *f)
{
	long	len;

	len = ft_strlen(p->a);
	if (p->d != 0)
		return (ft_minuss_dot_int(p, f, len));
	if (p->d == 0)
		return (ft_minuss_no_dot_int(p, f));
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
	}
	return (1);
}

int	ft_no_minuss_dot_int(t_print *p, t_list1 *f)
{
	long	l;

	l = (long)ft_strlen(p->a);
	if (p->pad_amount > (long)ft_strlen(p->a) && p->pad_amount > p->d)
		ft_memset(p->p, ' ', p->s);
	if ((long)ft_strlen(p->a) <= p->d)
	{
		ft_memset(p->p + (p->s - p->d), '0', (p->d));
		if (p->n == 1 && p->s - p->d != 0)
			ft_memmove(p->p + ((p->s - p->d) - p->n), "-", 1);
		if (p->n == 1 && p->s - p->d == 0)
			ft_memmove(p->p + (p->s - p->d), "-", 1);
		if (p->pad_amount <= p->d)
			ft_memmove(p->p + (p->s - (l - p->n)) + p->n, p->a + p->n, l - p->n);
		if (p->pad_amount > p->d)
			ft_memmove(p->p + (p->s - (l - p->n)), p->a + p->n, l - p->n);
	}
	else
		ft_memmove(p->p + (p->s - l), p->a, l);
	ft_putstr(p->p);
	f->total_chars_printed += ft_strlen(p->p);
	return (1);
}
