/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_int_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/25 13:40:52 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/12/25 13:43:23 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_minuss_no_dot_int(t_print *p, t_list1 *f)
{
	if (p->pad_amount == 0 && p->n == 1)
		p->pad_amount = 1;
	if (p->zero_present == 0 || p->minuss_present)
		ft_memset(p->p + p->n, ' ', p->pad_amount - p->n);
	else
		ft_memset(p->p + p->n, '0', p->pad_amount - p->n);
	ft_memmove(p->p + p->n, p->a + p->n, ft_strlen(p->a) - p->n);
	if (p->n == 1)
		ft_memmove(p->p, "-", 1);
	ft_putstr(p->p);
	f->total_chars_printed += ft_strlen(p->p);
	return (1);
}

int		ft_minuss_dot_int(t_print *p, t_list1 *f, long l)
{
	if (p->pad_amount > (long)ft_strlen(p->a) && p->pad_amount > p->d)
		ft_memset(p->p, ' ', p->s);
	if ((long)ft_strlen(p->a) <= p->d)
	{
		ft_memset(p->p + p->n, '0', p->d - p->n);
		if (p->n == 1)
			ft_memset(p->p, '-', 1);
		ft_memmove(p->p + (p->d - (l - p->n)) + p->n, p->a + p->n, l - p->n);
	}
	else
		ft_memmove(p->p, p->a, l);
	ft_putstr(p->p);
	f->total_chars_printed += ft_strlen(p->p);
	return (1);
}

int		ft_no_minuss_no_dot_int(t_print *p, t_list1 *f)
{
	long	l;

	l = (long)ft_strlen(p->a);
	if (p->zero_present == 0)
	{
		if ((long)p->pad_amount - l > 0)
			ft_memset(p->p, ' ', (p->pad_amount - l));
		if (p->n == 1)
			ft_memmove(p->p + (p->s - l), "-", 1);
	}
	else
	{
		if ((long)p->pad_amount - l > 0)
			ft_memset(p->p + p->n, '0', (p->pad_amount - l));
		if (p->n == 1)
			ft_memmove(p->p, "-", 1);
	}
	ft_memmove(p->p + (p->s - l) + p->n, p->a + p->n, l - p->n);
	ft_putstr(p->p);
	f->total_chars_printed += ft_strlen(p->p);
	return (1);
}
